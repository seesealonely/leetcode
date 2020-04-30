/*
Given an integer array A, you partition the array into (contiguous) subarrays of length at most K.  After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning.

 

Example 1:

Input: A = [1,15,7,9,2,5,10], K = 3
Output: 84
Explanation: A becomes [15,15,15,9,10,10,10]

 

Note:

    1 <= K <= A.length <= 500
    0 <= A[i] <= 10^6

*/

#include"1043.PartitionArrayforMaximumSum.h"

int main()
{
	Solution s;
	vector<int> v={1,15,7,9,2,5,10};
	cout<<s.maxSumAfterPartitioning(v,3)<<endl;
	return 0;
}
