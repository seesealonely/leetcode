/*
An array is monotonic if it is either monotone increasing or monotone decreasing.

An array A is monotone increasing if for all i <= j, A[i] <= A[j].  An array A is monotone decreasing if for all i <= j, A[i] >= A[j].

Return true if and only if the given array A is monotonic.

 

Example 1:

Input: [1,2,2,3]
Output: true

Example 2:

Input: [6,5,4,4]
Output: true

Example 3:

Input: [1,3,2]
Output: false

Example 4:

Input: [1,2,4,5]
Output: true

Example 5:

Input: [1,1,1]
Output: true

*/

#include"896.MonotonicArray.h"

int main()
{
	vector<int> v;
	Solution s;
	v.push_back(1);v.push_back(2);v.push_back(2);v.push_back(3);
	cout<<s.isMonotonic(v)<<endl;
	v.clear();v.push_back(6);v.push_back(5);v.push_back(5);v.push_back(4);
	cout<<s.isMonotonic(v)<<endl;
	v.clear();v.push_back(1);v.push_back(3);v.push_back(2);
	cout<<s.isMonotonic(v)<<endl;
	v.clear();v.push_back(1);v.push_back(2);v.push_back(4);v.push_back(5);
	cout<<s.isMonotonic(v)<<endl;
	v.clear();v.push_back(1);v.push_back(1);v.push_back(1);
	cout<<s.isMonotonic(v)<<endl;
	return 0;
}
