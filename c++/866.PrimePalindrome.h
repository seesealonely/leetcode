/*
Find the smallest prime palindrome greater than or equal to N.

Recall that a number is prime if it's only divisors are 1 and itself, and it is greater than 1. 

For example, 2,3,5,7,11 and 13 are primes.

Recall that a number is a palindrome if it reads the same from left to right as it does from right to left. 

For example, 12321 is a palindrome.

 

Example 1:

Input: 6
Output: 7

Example 2:

Input: 8
Output: 11

Example 3:

Input: 13
Output: 101

 

Note:

    1 <= N <= 10^8
    The answer is guaranteed to exist and be less than 2 * 10^8.
*/

#include"head.h"

class Solution {
public:
    int primePalindrome(int N) {
	if(N>=8&&N<=11) return 11;
	for(int i=1;i<100000;i++)
	{
		string s=to_string(i),r(s.rbegin(),s.rend());
		s+=r.substr(1);
		int num=stoi(s);
		if(isPrime(num)&&num>=N)
		return num;
	}
	return -1;
    }
    bool isPrime(int num) {
	 if(num<2||num%2==0) return num==2;	       
	for(int i=3;i*i<=num;i+=2)
	if(num%i==0) return false;	
	return true;
    }
};
