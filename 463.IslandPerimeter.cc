/*
   You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example:

[[0,1,0,0],
[1,1,1,0],
[0,1,0,0],
[1,1,0,0]]

Answer: 16
Explanation: The perimeter is the 16 yellow stripes in the image below:


*/

#include"463.IslandPerimeter.h"

int main()
{
	vector<vector<int> > v;
	v.push_back({}); v[0].push_back(0);v[0].push_back(1);v[0].push_back(0);v[0].push_back(0);		
	v.push_back({}); v[1].push_back(1);v[1].push_back(1);v[1].push_back(1);v[1].push_back(0);		
	v.push_back({}); v[2].push_back(0);v[2].push_back(1);v[2].push_back(0);v[2].push_back(0);		
	v.push_back({}); v[3].push_back(1);v[3].push_back(1);v[3].push_back(0);v[3].push_back(0);		
	Solution s;
	cout<<s.islandPerimeter(v)<<endl;
	return 0;
}
