/*
   A k-mirror number is a positive integer without leading zeros that reads the same both forward and backward in base-10 as well as in base-k.

   For example, 9 is a 2-mirror number. The representation of 9 in base-10 and base-2 are 9 and 1001 respectively, which read the same both forward and backward.
   On the contrary, 4 is not a 2-mirror number. The representation of 4 in base-2 is 100, which does not read the same both forward and backward.

   Given the base k and the number n, return the sum of the n smallest k-mirror numbers.



   Example 1:

Input: k = 2, n = 5
Output: 25
Explanation:
The 5 smallest 2-mirror numbers and their representations in base-2 are listed as follows:
base-10 base-2
1 1
3 11
5 101
7 111
9 1001
Their sum = 1 + 3 + 5 + 7 + 9 = 25.

Example 2:

Input: k = 3, n = 7
Output: 499
Explanation:
The 7 smallest 3-mirror numbers are and their representations in base-3 are listed as follows:
base-10 base-3
1 1
2 2
4 11
8 22
121 11111
151 12121
212 21212
Their sum = 1 + 2 + 4 + 8 + 121 + 151 + 212 = 499.

Example 3:

Input: k = 7, n = 17
Output: 20379000
Explanation: The 17 smallest 7-mirror numbers are:
1, 2, 3, 4, 5, 6, 8, 121, 171, 242, 292, 16561, 65656, 2137312, 4602064, 6597956, 6958596



Constraints:

2 <= k <= 9
1 <= n <= 30

*/


#include"head.h"
class Solution {
	public:
		typedef long long ll;
		long long kMirror(int k, int n) {
		ll res=0,num=0;
		while(n)
		{
			num=next(num);
			string s=Kstring(num,k);
			if(isTrue(s))
			{
				res+=num;
				n--;
			}
		}
		return res;
		}
		ll next(ll num)
		{
			string s=to_string(num);
			int len=s.size();
			for(int i=len/2;i>=0;i--)
			if(s[i]!='9')
			{
				s[i]++;
				if(len-1-i!=i)
					s[len-1-i]++;

				for(int j=i+1;j<=len/2;j++)
					s[j]=s[len-1-j]='0';
				return stoll(s);
			}
			ll res=1;
			for(int i=0;i<len;i++)
				res*=10;
			return res+1;
		}
		string Kstring(ll num,int k)
		{
			string res;
			while(num)
			{
				res+='0'+num%k;
				num/=k;
			}
			return res;
		}
		bool isTrue(string &s)
		{
			const int n=s.size();
			for(int i=0;i<n/2;i++)
				if(s[i]!=s[n-1-i])
					return false;
			return true;
		}
};


int main() 
{
	Solution s;
	cout<<s.kMirror(2,5)<<endl;
	cout<<s.kMirror(3,7)<<endl;
	cout<<s.kMirror(7,17)<<endl;
	return 0;
}
