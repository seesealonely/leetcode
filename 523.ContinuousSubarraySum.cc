/*

ven a list of non-negative numbers and a target integer k, write a function to check if the array has a continuous subarray of size at least 2 that sums up to the multiple of k, that is, sums up to n*k where n is also an integer.

Example 1:

Input: [23, 2, 4, 6, 7],  k=6
Output: True
Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 6.

Example 2:

Input: [23, 2, 6, 4, 7],  k=6
Output: True
Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5 and sums up to 42.

Note:

    The length of the array won't exceed 10,000.
    You may assume the sum of all the numbers is in the range of a signed 32-bit integer.
*/


#include"523.ContinuousSubarraySum.h"

int main()
{
	int e1[]={23, 2, 4, 6, 7};
	vector<int> v(e1,e1+5);
	Solution s;
	cout<<s.checkSubarraySum(v,6)<<endl;
	cout<<s.checkSubarraySum(v,0)<<endl;
	v.clear();
	v.push_back(0);	v.push_back(0);
	cout<<s.checkSubarraySum(v,0)<<endl;
	v.clear();
	v.push_back(1);	v.push_back(2);v.push_back(3);
	cout<<s.checkSubarraySum(v,4)<<endl;
	v.clear();
	v.push_back(1);	v.push_back(1);
	cout<<s.checkSubarraySum(v,2)<<endl;
	return 0;
}
