/*
Given an array of integers A, consider all non-empty subsequences of A.

For any sequence S, let the width of S be the difference between the maximum and minimum element of S.

Return the sum of the widths of all subsequences of A. 

As the answer may be very large, return the answer modulo 10^9 + 7.

 

Example 1:

Input: [2,1,3]
Output: 6
Explanation:
Subsequences are [1], [2], [3], [2,1], [2,3], [1,3], [2,1,3].
The corresponding widths are 0, 0, 0, 1, 1, 2, 2.
The sum of these widths is 6.

 

Note:

    1 <= A.length <= 20000
    1 <= A[i] <= 20000

*/

#include"head.h"

class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
	sort(A.begin(),A.end());
	int c=1,res=0,mod=1e9+7;	
	for(int i=0;i<A.size();i++,c=(c<<1)%mod)
	res=(res+A[i]*c-A[A.size()-1-i]*c)%mod; 
	return res%mod;
    }
};
