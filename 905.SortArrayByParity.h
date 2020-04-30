/*
Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.
Example 1:

Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.

 

Note:

    1 <= A.length <= 5000
    0 <= A[i] <= 5000

*/

#include"head.h"

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
	int len=A.size();
	vector<int> res(A.size(),0);
	for(int begin=0,end=len-1,i=0;i<A.size();i++)
	{
		if(A[i]%2==1)
		res[end--]=A[i];
		else
		res[begin++]=A[i];
	}
	return res;
    }
};
