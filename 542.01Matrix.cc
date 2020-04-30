/*
 Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.

Example 1:
Input:

0 0 0
0 1 0
0 0 0

Output:

0 0 0
0 1 0
0 0 0

Example 2:
Input:

0 0 0
0 1 0
1 1 1

Output:

0 0 0
0 1 0
1 2 1

Note:

    The number of elements of the given matrix will not exceed 10,000.
    There are at least one 0 in the given matrix.
    The cells are adjacent in only four directions: up, down, left and right.

*/

#include"542.01Matrix.h"

int main()
{
	vector<vector<int> >v;
	v.resize(v.size()+1);v[0].push_back(0);v[0].push_back(0);v[0].push_back(0);
	v.resize(v.size()+1);v[1].push_back(0);v[1].push_back(1);v[1].push_back(0);
	v.resize(v.size()+1);v[2].push_back(1);v[2].push_back(1);v[2].push_back(1);
	Solution s;
	show(s.updateMatrix(v));
	return 0;
}
