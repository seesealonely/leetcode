/*
Starting with a positive integer N, we reorder the digits in any order (including the original order) such that the leading digit is not zero.

Return true if and only if we can do this in a way such that the resulting number is a power of 2.

 

Example 1:

Input: 1
Output: true

Example 2:

Input: 10
Output: false

Example 3:

Input: 16
Output: true

Example 4:

Input: 24
Output: false

Example 5:

Input: 46
Output: true

*/

#include"869.ReorderedPowerof2.h"

int main()
{
	Solution s;	
	cout<<s.reorderedPowerOf2(1)<<endl;
	cout<<s.reorderedPowerOf2(10)<<endl;
	cout<<s.reorderedPowerOf2(16)<<endl;
	cout<<s.reorderedPowerOf2(24)<<endl;
	cout<<s.reorderedPowerOf2(46)<<endl;
	return 0;
}
