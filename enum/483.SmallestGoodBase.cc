/*
   Given an integer n represented as a string, return the smallest good base of n.

   We call k >= 2 a good base of n, if all digits of n base k are 1's.



   Example 1:

Input: n = "13"
Output: "3"
Explanation: 13 base 3 is 111.

Example 2:

Input: n = "4681"
Output: "8"
Explanation: 4681 base 8 is 11111.

Example 3:

Input: n = "1000000000000000000"
Output: "999999999999999999"
Explanation: 1000000000000000000 base 999999999999999999 is 11.



Constraints:

n is an integer in the range [3, 1018].
n does not contain any leading zeros.

*/


#include"head.h"
class Solution {
	public:
		typedef long long int ll;
		string smallestGoodBase(string n) {
		ll N=stoll(n);
		for(int t = log2(N)+1;t>=3;t--)
		{
			ll k=pow(N,1.0/(t-1));
			ll tot=0;
			for(int i=0;i<t;i++)
			{
				tot=tot*k+1;
				if(tot>N)
					break;
			}
			if(tot==N)
				return to_string(k);
		}
		return to_string(N-1);
		}
};


int main() 
{
	Solution s;
	cout<<s.smallestGoodBase("13")<<endl;
	cout<<s.smallestGoodBase("4681")<<endl;
	cout<<s.smallestGoodBase("1000000000000000000")<<endl;
	return 0;
}
