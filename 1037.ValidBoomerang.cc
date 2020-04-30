/*
A boomerang is a set of 3 points that are all distinct and not in a straight line.

Given a list of three points in the plane, return whether these points are a boomerang.

 

Example 1:

Input: [[1,1],[2,3],[3,2]]
Output: true

Example 2:

Input: [[1,1],[2,2],[3,3]]
Output: false

 

Note:

    points.length == 3
    points[i].length == 2
    0 <= points[i][j] <= 100

*/

#include"1037.ValidBoomerang.h"

int main()
{
	Solution s;
	vector<vector<int> > v={{1,1},{3,2},{2,3}};
	cout<<s.isBoomerang(v)<<endl;
	v.clear();v={{1,1},{2,2},{3,3}};
	cout<<s.isBoomerang(v)<<endl;
	return 0;
}
