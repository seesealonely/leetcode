/*
Given a list of non negative integers, arrange them such that they form the largest number.

Example 1:

Input: [10,2]
Output: "210"

Example 2:

Input: [3,30,34,5,9]
Output: "9534330"

Note: The result may be very large, so you need to return a string instead of an integer.

*/

#include"179.LargestNumber.h"

int main()
{
	Solution s;
	vector<int> v={3,30,34,5,9};
	cout<<s.largestNumber(v)<<endl;
	v.clear(); v={10,2};
	cout<<s.largestNumber(v)<<endl;
	v.clear(); v={0,0};
	cout<<s.largestNumber(v)<<endl;
	return 0;
}
