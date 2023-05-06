/*
   You are given a positive integer primeFactors. You are asked to construct a positive integer n that satisfies the following conditions:

   The number of prime factors of n (not necessarily distinct) is at most primeFactors.
   The number of nice divisors of n is maximized. Note that a divisor of n is nice if it is divisible by every prime factor of n. For example, if n = 12, then its prime factors are [2,2,3], then 6 and 12 are nice divisors, while 3 and 4 are not.

   Return the number of nice divisors of n. Since that number can be too large, return it modulo 109 + 7.

   Note that a prime number is a natural number greater than 1 that is not a product of two smaller natural numbers. The prime factors of a number n is a list of prime numbers such that their product equals n.



   Example 1:

Input: primeFactors = 5
Output: 6
Explanation: 200 is a valid value of n.
It has 5 prime factors: [2,2,2,5,5], and it has 6 nice divisors: [10,20,40,50,100,200].
There is not other value of n that has at most 5 prime factors and more nice divisors.

Example 2:

Input: primeFactors = 8
Output: 18



Constraints:

1 <= primeFactors <= 109
*/


#include"head.h"
class Solution {
	public:
		typedef long long ll;
		ll power(ll x,ll y,ll mod)
		{
			ll res=1,p=x;
			for(;y;y>>=1)
			{
				if(y&1) res=res*p%mod;
				p=p*p%mod;
			}
			return res;
		}
		int maxNiceDivisors(int primeFactors) {
		if(primeFactors==1)
			return 1;

		const int mod=1e9+7;

		int n=primeFactors/3;
		if(primeFactors%3==1)
			return power(3,n-1,mod)*4%mod;

		if(primeFactors%3==2)
			return power(3,n,mod)*2%mod;

		return power(3,n,mod)%mod;

		}
};


int main() 
{
	Solution s;
	cout<<s.maxNiceDivisors(5)<<endl;
	cout<<s.maxNiceDivisors(8)<<endl;
	return 0;
}
