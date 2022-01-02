/*
   A positive integer is magical if it is divisible by either a or b.

   Given the three integers n, a, and b, return the nth magical number. Since the answer may be very large, return it modulo 109 + 7.



   Example 1:

Input: n = 1, a = 2, b = 3
Output: 2

Example 2:

Input: n = 4, a = 2, b = 3
Output: 6



Constraints:

1 <= n <= 109
2 <= a, b <= 4 * 104

*/
#include"head.h"
class Solution {
	public:
		int nthMagicalNumber(int n, int a, int b) {
			const int lcm=a*b/gcd(a,b),mod=1e9+7;
			const long step=lcm/a+lcm/b-1,count=n/step;
			const long remind=n-step*count;
			long remindnum=0;
			int i=1,j=1,c=0;
			while(c<remind)
			{
				if(i*a<j*b)
					remindnum=a*i++;
				else
					remindnum=b*j++;
				c++;
			}
			return (int)((lcm*count+remindnum)%mod);
		}
		int gcd(int a,int b)
		{
			if(!a) return b;
			return gcd(b%a,a);

		}
};
int main() 
{
	Solution s;
	cout<<s.nthMagicalNumber(1,2,3)<<endl;
	cout<<s.nthMagicalNumber(4,2,3)<<endl;
	return 0;
}
