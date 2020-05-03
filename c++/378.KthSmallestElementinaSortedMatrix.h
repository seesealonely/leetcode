/*
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.

Note:
You may assume k is always valid, 1 ≤ k ≤ n2.
*/

#include"head.h"

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
	int n=matrix.size(),lval=matrix[0][0],rval=matrix[n-1][n-1],midval=0;
	while(lval<rval)
	{
		int count=0;
		midval=lval+(rval-lval)/2;
		for(int i=0;i<n;i++)
			count+=upper_bound(matrix[i].begin(),matrix[i].end(),midval)-matrix[i].begin();
		if(count<k)
			lval=midval+1;
		else
			rval=midval;
	}
	return lval;
    }
};
