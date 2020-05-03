/*
In an array A of 0s and 1s, how many non-empty subarrays have sum S?

 

Example 1:

Input: A = [1,0,1,0,1], S = 2
Output: 4
Explanation: 
The 4 subarrays are bolded below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]

 

Note:

    A.length <= 30000
    0 <= S <= A.length
    A[i] is either 0 or 1.

*/

#define c11
#include"head.h"

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
	vector<int> pre(A.size()+1,0);
	int res=0,presum=0;
	unordered_map<int,int> m;
	m[0]=1;
	for(int i=0;i<A.size();i++)
	{
		presum+=A[i];
		res+=m[presum-S];
		m[presum]++;
	}	
	return res;
    }
};
