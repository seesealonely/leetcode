/*
Given an array A of integers, return true if and only if it is a valid mountain array.

Recall that A is a mountain array if and only if:

    A.length >= 3
    There exists some i with 0 < i < A.length - 1 such that:
        A[0] < A[1] < ... A[i-1] < A[i]
        A[i] > A[i+1] > ... > A[B.length - 1]

 

Example 1:

Input: [2,1]
Output: false

Example 2:

Input: [3,5,5]
Output: false

Example 3:

Input: [0,3,2,1]
Output: true

 

Note:

    0 <= A.length <= 10000
    0 <= A[i] <= 10000 
 
*/

#include"941.ValidMountainArray.h"

int main()
{
	vector<int> v;
	Solution s;
	v.push_back(2);v.push_back(1);
	cout<<s.validMountainArray(v)<<endl;
	v.clear();v.push_back(3);v.push_back(5);v.push_back(5);
	cout<<s.validMountainArray(v)<<endl;
	v.clear();v.push_back(0);v.push_back(3);v.push_back(2);v.push_back(1);
	cout<<s.validMountainArray(v)<<endl;
	return 0;
}
