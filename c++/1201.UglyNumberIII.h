/*
Write a program to find the n-th ugly number.

Ugly numbers are positive integers which are divisible by a or b or c.

 

Example 1:

Input: n = 3, a = 2, b = 3, c = 5
Output: 4
Explanation: The ugly numbers are 2, 3, 4, 5, 6, 8, 9, 10... The 3rd is 4.

Example 2:

Input: n = 4, a = 2, b = 3, c = 4
Output: 6
Explanation: The ugly numbers are 2, 3, 4, 6, 8, 9, 10, 12... The 4th is 6.

Example 3:

Input: n = 5, a = 2, b = 11, c = 13
Output: 10
Explanation: The ugly numbers are 2, 4, 6, 8, 10, 11, 12, 13... The 5th is 10.

Example 4:

Input: n = 1000000000, a = 2, b = 217983653, c = 336916467
Output: 1999999984

 

Constraints:

    1 <= n, a, b, c <= 10^9
    1 <= a * b * c <= 10^18
    It's guaranteed that the result will be in range [1, 2 * 10^9]
*/

#include"head.h"

class Solution {
public:
    int nthUglyNumber(int n, int A, int B, int C) {
	int l=1,r=2*(int)1e9,m=(l+r)/2,cur=0;
	long a=(long)A,b=(long)B,c=(long)C;
	long ab=a*b/gcd(a,b),ac=a*c/gcd(a,c),bc=b*c/gcd(b,c),abc=ab*c/gcd(ab,c);
	while(l<r)
	{
		m=l+(r-l)/2;
		cur=m/a+m/b+m/c-m/ab-m/ac-m/bc+m/abc;	
		if(cur<n)
			l=m+1;
		else 
			r=m;
	}
	return l;
    }
	int gcd (int a,int b)
	{
		return b==0?a:gcd(b,a%b);
	}
};
