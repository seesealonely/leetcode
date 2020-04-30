/*
Given an array A of non-negative integers, the array is squareful if for every pair of adjacent elements, their sum is a perfect square.

Return the number of permutations of A that are squareful.  Two permutations A1 and A2 differ if and only if there is some index i such that A1[i] != A2[i].

 

Example 1:

Input: [1,17,8]
Output: 2
Explanation: 
[1,8,17] and [17,8,1] are the valid permutations.

Example 2:

Input: [2,2,2]
Output: 1

 

Note:

    1 <= A.length <= 12
    0 <= A[i] <= 1e9

*/

#define c11
#include"head.h"

class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
       return dfs(A,-1,0); 
    }
    int dfs(vector<int> A,int begin,int res=0) {
       	if(begin==A.size()-1) return 1; 
	unordered_set<int> s;
	for(int i=begin+1;i<A.size();i++)
	{
		if(s.insert(A[i]).second&&(begin==-1||pow((int)sqrt(A[begin]+A[i]),2)==A[begin]+A[i]))
		{
			swap(A[begin+1],A[i]);
			res+=dfs(A,begin+1);
		}
	}
	return res;
    }
};
