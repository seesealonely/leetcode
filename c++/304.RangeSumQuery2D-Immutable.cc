/*
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:

Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12

Note:

    You may assume that the matrix does not change.
    There are many calls to sumRegion function.
    You may assume that row1 ≤ row2 and col1 ≤ col2.

*/

#include"304.RangeSumQuery2D-Immutable.h"

int main()
{
	vector<vector<int> > v;
	v.resize(v.size()+1);
	v[0].push_back(3);v[0].push_back(0);v[0].push_back(1);v[0].push_back(4);v[0].push_back(2);
	v.resize(v.size()+1);
v[1].push_back(5);v[1].push_back(6);v[1].push_back(3);v[1].push_back(2);v[1].push_back(1);
	v.resize(v.size()+1);
v[2].push_back(1);v[2].push_back(2);v[2].push_back(0);v[2].push_back(1);v[2].push_back(5);
	v.resize(v.size()+1);
v[3].push_back(4);v[3].push_back(1);v[3].push_back(0);v[3].push_back(1);v[3].push_back(7);
	v.resize(v.size()+1);
v[4].push_back(1);v[4].push_back(0);v[4].push_back(3);v[4].push_back(0);v[4].push_back(5);
	NumMatrix s(v);
	cout<<s.sumRegion(2,1,4,3)<<endl;
	cout<<s.sumRegion(1,1,2,2)<<endl;
	cout<<s.sumRegion(1,2,2,4)<<endl;
	return 0;
}
