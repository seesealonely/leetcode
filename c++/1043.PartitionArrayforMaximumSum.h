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

#include"head.h"

class Solution {
	public:
		int maxSumAfterPartitioning(vector<int>& A, int K) {
			vector<int> dp(A.size()+1,0);
			for(int i=1;i<=A.size();i++)
			{
				int curMax=0;
				for(int k=0;k<K;k++)
				{
					if(i-1-k>=0)
					{
						curMax=max(curMax,A[i-1-k]);
						dp[i]=max(curMax*(k+1)+dp[i-1-k],dp[i]);
					}
					else break;
				}
			}	        
			return  dp[A.size()];
		}
};
