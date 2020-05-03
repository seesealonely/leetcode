/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
*/

#include"172.FactorialTrailingZeroes.h"

int main()
{
	Solution s;
	
	cout<<s.trailingZeroes(4)<<endl;
	cout<<s.trailingZeroes(1024)<<endl;
	cout<<s.trailingZeroes(1808548329)<<endl;

	return 0;
}
