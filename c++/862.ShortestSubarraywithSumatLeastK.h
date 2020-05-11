/*
Return the length of the shortest, non-empty, contiguous subarray of A with sum at least K.

If there is no non-empty subarray with sum at least K, return -1.



Example 1:

Input: A = [1], K = 1
Output: 1

Example 2:

Input: A = [1,2], K = 4
Output: -1

Example 3:

Input: A = [2,-1,2], K = 3
Output: 3



Note:

1 <= A.length <= 50000
-10 ^ 5 <= A[i] <= 10 ^ 5
1 <= K <= 10 ^ 9

*/
#include"head.h"
class Solution {
public:
int shortestSubarray(vector<int>& A, int K) {
	vector<int> B(A.size()+1,0);
	int res=INT_MAX;
	for(int i=0;i<B.size()-1;i++)
		B[i+1]=B[i]+A[i];	
	deque<int> d;
	for(int i=0;i<B.size()+1;i++)
	{
		while(d.size()>0&&B[i]-B[d.front()]>=K)
			res=min(res,i-d.front()),d.pop_front();	
		while(d.size()>0&&B[i]<=B[d.back()])
			d.pop_back();
		d.push_back(i);
	}
	return res!=INT_MAX?res:-1;
}
};
