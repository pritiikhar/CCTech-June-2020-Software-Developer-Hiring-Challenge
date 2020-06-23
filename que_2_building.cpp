// language Cpp
// Question 2 : Calculate the surface of the building exposed to sunlight ?

#include <bits/stdc++.h>

using namespace std; 

// function to find building's surface exposed to sunlight 
// Since the shape of the building is rectangle, I have used 
// Lenght + Breadth formula to calculate the surface exposed

float exposedToSun(vector<vector<float>> building, double point[]){ 

	// creating empty columns 
	map<float,vector<float>> columns; 

	// fill columns with coordinates 
	for(auto i:building) 
		columns[i[0]].push_back(i[1]); 

	map<pair<float,float>,float > lastx; 

	float length = INT_MAX; 

	for (auto x:columns) 
	{ 
		vector<float> column = x.second; 
		sort(column.begin(), column.end()); 
		for (float j = 0; j < column.size(); j++) 
		{ 
			for (float i = 0; i < j; i++) 
			{ 
				float y1 = column[i]; 

				// check if rectangle can be formed 
				if (lastx.find({y1, column[j]}) != lastx.end()) 
				{ 
					length =  (x.first - lastx[{y1, column[j]}]) + 
							(column[j] - column[i]) ; 
				} 
				lastx[{y1, column[j]}] = x.first; 
			} 
			} 
		} 

		return length; 
  	 
} 


// Driver code 
int main() 
{ 
	// First building input
  vector<vector<float>> building1 = {{4, 0}, {4, -5}, {7, -5}, {7, 0}}; 
  // Second building input
  vector<vector<float>> building2 = {{0.4,-2}, {0.4,-5}, {2.5,-2}, {2.5,-5}};
  // Source of sunlight
  double point[] = {-3.5,1};
  
  
   float buildingSurface = ((exposedToSun(building1,point)) + 
             (exposedToSun(building2,point))) - (sqrt(pow(building2[3][0] - 
    building2[2][0], 2) + pow(building2[3][1] - building2[2][1], 2)) * 1.0 - 0.5) ; 

// Output of case1 given in question2
  cout << (exposedToSun(building1,point)) << "\n";
	
   
  // Output of case2 given in question2
  cout << buildingSurface  <<"\n"; 
 
	return 0; 
} 

 
