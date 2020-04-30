/*
In MATLAB, there is a very useful function called 'reshape', which can reshape a matrix into a new one with different size but keep its original data.

You're given a matrix represented by a two-dimensional array, and two positive integers r and c representing the row number and column number of the wanted reshaped matrix, respectively.

The reshaped matrix need to be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the 'reshape' operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

Example 1:

Input: 
nums = 
[[1,2],
 [3,4]]
r = 1, c = 4
Output: 
[[1,2,3,4]]
Explanation:
The row-traversing of nums is [1,2,3,4]. The new reshaped matrix is a 1 * 4 matrix, fill it row by row by using the previous list.

Example 2:

Input: 
nums = 
[[1,2],
 [3,4]]
r = 2, c = 4
Output: 
[[1,2],
 [3,4]]
Explanation:
There is no way to reshape a 2 * 2 matrix to a 2 * 4 matrix. So output the original matrix.

Note:

    The height and width of the given matrix is in range [1, 100].
    The given r and c are all positive.

*/

#include"566.ReshapetheMatrix.h"

int main()
{
	vector<vector<int> > v,vv;
	vector<int> v0,vv0,vv1;
	v.push_back(vector<int> (4,0));
	v[0][0]=1;	v[0][1]=2;	v[0][2]=3;	v[0][3]=4;
	vv.push_back(vector<int> (2,0));
	vv.push_back(vector<int> (2,0));
	vv[0][0]=1;	vv[0][1]=2;vv[1][0]=3;	vv[1][1]=4;
	Solution s;
	show(s.matrixReshape(v,1,4));
	show(s.matrixReshape(vv,2,4));
	return 0;
}
