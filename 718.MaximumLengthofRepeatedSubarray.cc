/*
Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

Example 1:

Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
Output: 3
Explanation: 
The repeated subarray with maximum length is [3, 2, 1].

Note:

    1 <= len(A), len(B) <= 1000
    0 <= A[i], B[i] < 100

*/
#include "718.MaximumLengthofRepeatedSubarray.h"
int main()
{
	vector<int> a,b;
	a.push_back(1);a.push_back(2);a.push_back(3);a.push_back(2);a.push_back(1);
	b.push_back(3);b.push_back(2);b.push_back(1);b.push_back(4);b.push_back(7);
	Solution s;
	cout<<s.findLength(a,b)<<endl;
	return 0;
}
