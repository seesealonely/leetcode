/*
Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors.

If there is no such integer in the array, return 0.



Example 1:

Input: nums = [21,4,7]
Output: 32
Explanation:
21 has 4 divisors: 1, 3, 7, 21
4 has 3 divisors: 1, 2, 4
7 has 2 divisors: 1, 7
The answer is the sum of divisors of 21 only.

*/
#include"1390.FourDivisors.h"
int main() 
 {
 	 Solution s;
	 vector<int> v={21,4,7};
 	 cout<<s.sumFourDivisors(v)<<endl;
 	 return 0;
 }
