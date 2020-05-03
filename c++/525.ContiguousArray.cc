/*
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:

Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.

Example 2:

Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

Note: The length of the given binary array will not exceed 50,000. 
*/

#include"525.ContiguousArray.h"

int main()
{
	int vv[]={0,1,0,1,1,1,0,1,0,1,0,1};
	vector<int> v(vv,vv+12);
	Solution s;
	cout<<s.findMaxLength(v)<<endl;
	v.clear();
	v.push_back(0);v.push_back(1);
	cout<<s.findMaxLength(v)<<endl;
	return 0;
}
