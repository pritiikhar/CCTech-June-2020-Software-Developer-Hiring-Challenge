
//Question 1 : Check if the given point lies inside or outside a polygon ?

#include <iostream> 
using namespace std; 

// Define Infinite 
#define INF 10000 

struct Point 
{ 
	double x; 
	double y; 
}; 

//  p, q, r are three points
//The following finction checks whether the point q lies on segment pr
bool lieOnSeg(Point p, Point q, Point r) 
{ 
	if (q.x <= (p.x, r.x) && q.x >= (p.x, r.x) && 
			q.y <= (p.y, r.y) && q.y >= (p.y, r.y)) 
		return true; 
	return false; 
} 

// This function checks orientation of  (p, q, r)
// 0 -> p, q and r are colinear 
// 1 -> Clockwise 
// 2 -> Counterclockwise 
int checkOrientation(Point p, Point q, Point r) 
{ 
	int val = (q.y - p.y) * (r.x - q.x) - 
			(q.x - p.x) * (r.y - q.y); 

	if (val == 0) return 0;  
	return (val > 0)? 1: 2; 
} 


//The following function checks if the segment p1q1 and p2q2 intersect


bool segIntersect(Point p1, Point q1, Point p2, Point q2) 
{ 
    
    int o1 = checkOrientation(p1, q1, p2); 
    int o2 = checkOrientation(p1, q1, q2); 
    int o3 = checkOrientation(p2, q2, p1); 
    int o4 = checkOrientation(p2, q2, q1); 
  
    // case 1
    if (o1 != o2 && o3 != o4) 
        return true; 
  
    //  Cases 2 
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1 
    if (o1 == 0 && lieOnSeg(p1, p2, q1)) return true; 
  
    // p1, q1 and q2 are colinear and q2 lies on segment p1q1 
    if (o2 == 0 && lieOnSeg(p1, q2, q1)) return true; 
  
    // p2, q2 and p1 are colinear and p1 lies on segment p2q2 
    if (o3 == 0 && lieOnSeg(p2, p1, q2)) return true; 
  
     // p2, q2 and q1 are colinear and q1 lies on segment p2q2 
    if (o4 == 0 && lieOnSeg(p2, q1, q2)) return true; 
  
    return false; //If all of the above cases are false
} 

//Checks if the point lies inside the polygon

bool lieInside(Point polygon[], int n, Point p) 
{ 
	// There should be at least 3 vertices in polygon[] 
	if (n < 3) return false; 

	
	Point extreme = {INF, p.y}; 

	
	int count = 0, i = 0; 
	do
	{ 
		int next = (i+1)%n; 
 
		if (segIntersect(polygon[i], polygon[next], p, extreme)) 
		{ 
			// If the point 'p' is colinear with line segment 'i-next', 
			// then check if it lies on segment. If it lies, return true, 
			// otherwise false 
			if (checkOrientation(polygon[i], p, polygon[next]) == 0) 
			return lieOnSeg(polygon[i], p, polygon[next]); 

			count++; 
		} 
		i = next; 
	} while (i != 0); 

	// Return true if count is odd, false otherwise 
	return count&1; 
} 


int main() 
{ 
  //Input for polygon1 - Case1 in question 1
	Point polygon1[] = {{1,0}, {8, 3}, {8, 8}, {1, 5}}; 
	int n = sizeof(polygon1)/sizeof(polygon1[0]); 
	Point p = {3,5}; 
	lieInside(polygon1, n, p)? cout << "True \n": cout << "False \n"; 
  
   //Input for polygon2 - Case2 in question 1
   Point polygon2[] = {{-3, 2}, {-2, -0.8}, {0, 1.2}, {2.2, 0}, {2, 4.5}}; 
    p = {0, 0}; 
   n = sizeof(polygon2)/sizeof(polygon2[0]); 
    lieInside(polygon2, n, p)? cout << "True \n": cout << "False \n"; 

	return 0; 
}
