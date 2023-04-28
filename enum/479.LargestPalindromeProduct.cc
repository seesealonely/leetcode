/*
   Given an integer n, return the largest palindromic integer that can be represented as the product of two n-digits integers. Since the answer can be very large, return it modulo 1337.



   Example 1:

Input: n = 2
Output: 987
Explanation: 99 x 91 = 9009, 9009 % 1337 = 987

Example 2:

Input: n = 1
Output: 9



Constraints:

1 <= n <= 8

*/


#include"head.h"
class Solution {
	public:
		int largestPalindrome(int n) {
		if(n==1) return 9;

		int r=pow(10,n)-1;

		for(int l=r;;--l)
		{
			long long pa=l;
			for(int x=l;x>0;x/=10)
				pa=pa*10+x%10;
			for(int x=r;(long long)x*x>=pa;--x)
				if(pa%x==0)
					return pa%1337;
		}


		}
};


int main() 
{
	Solution s;
	cout<<s.largestPalindrome(2)<<endl;
	cout<<s.largestPalindrome(1)<<endl;
	return 0;
}
