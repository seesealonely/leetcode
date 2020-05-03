/*
Let's call an array A a mountain if the following properties hold:

    A.length >= 3
    There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]

Given an array that is definitely a mountain, return any i such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].

Example 1:

Input: [0,1,0]
Output: 1

Example 2:

Input: [0,2,1,0]
Output: 1

Note:

    3 <= A.length <= 10000
    0 <= A[i] <= 10^6
    A is a mountain, as defined above.


*/

#include"852.PeakIndexinaMountainArray.h"

int main()
{
	vector<int> v;
	Solution s;
	v.push_back(0);v.push_back(1);v.push_back(0);
	cout<<s.peakIndexInMountainArray(v)<<endl;
	v.clear();v.push_back(0);v.push_back(2);v.push_back(1);v.push_back(0);
	cout<<s.peakIndexInMountainArray(v)<<endl;
	return 0;
}
