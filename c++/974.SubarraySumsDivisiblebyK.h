/*
Given an array A of integers, return the number of (contiguous, non-empty) subarrays that have a sum divisible by K.

 

Example 1:

Input: A = [4,5,0,-2,-3,1], K = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by K = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

 

Note:

    1 <= A.length <= 30000
    -10000 <= A[i] <= 10000
    2 <= K <= 10000

*/

#include"head.h"

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
    	int l=A.size();
	vector<int> prefix(l+1,0);
	for(int i=0;i<l;i++)
		prefix[i+1]=A[i]+prefix[i];
	vector<int> mod(K,0);
	for(int i=1;i<l+1;i++)	
	mod[(prefix[i]%K+K)%K]++;
	int res=mod[0];
	for(int i=0;i<K;i++)
		res+=mod[i]*(mod[i]-1)/2;
	return res;
    }
};
