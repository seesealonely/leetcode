/*
Given an array A of positive integers, call a (contiguous, not necessarily distinct) subarray of A good if the number of different integers in that subarray is exactly K.

(For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.)

Return the number of good subarrays of A.

 

Example 1:

Input: A = [1,2,1,2,3], K = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].

Example 2:

Input: A = [1,2,1,3,4], K = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].

 

Note:

    1 <= A.length <= 20000
    1 <= A[i] <= A.length
    1 <= K <= A.length

*/

#define c11
#include"head.h"

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
	return mostK(A,K)-mostK(A,K-1);
    }
	int mostK(vector<int> &A,int K)
	{
		unordered_map<int,int> fre;
		int res=0,begin=0;
		for(int i=0;i<A.size();i++)
		{
			fre[A[i]]++;
			while(fre.size()>K)
			{
				if(--fre[A[begin]]==0)
					fre.erase(A[begin]);
				begin++;
			}
			res+=i-begin+1;
		}
		return res;
	}
};
