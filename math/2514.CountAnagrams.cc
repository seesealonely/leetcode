/*
   You are given a string s containing one or more words. Every consecutive pair of words is separated by a single space ' '.

   A string t is an anagram of string s if the ith word of t is a permutation of the ith word of s.

   For example, "acb dfe" is an anagram of "abc def", but "def cab" and "adc bef" are not.

   Return the number of distinct anagrams of s. Since the answer may be very large, return it modulo 109 + 7.



   Example 1:

Input: s = "too hot"
Output: 18
Explanation: Some of the anagrams of the given string are "too hot", "oot hot", "oto toh", "too toh", and "too oht".

Example 2:

Input: s = "aa"
Output: 1
Explanation: There is only one anagram possible for the given string.



Constraints:

1 <= s.length <= 105
s consists of lowercase English letters and spaces ' '.
There is single space between consecutive words.

*/


#include"head.h"
class Solution {
	public:
		typedef long long ll;
		static const int mod=1e9+7;
		vector<ll> fac;
		ll power(int x,int y)
		{
			ll res=1,p=x;
			for(;y;y>>=1)
			{
				if(y&1) 
					res=res*p%mod;
				p=p*p%mod;
			}
			return res;
		}
		ll solve(const string &s)
		{
			const int n=s.size();
			vector<int> cnt(26,0);
			for(int i=0;i<n;i++)
				cnt[s[i]-'a']++;

			ll res=fac[n];
			for(int i=0;i<26;i++)
				res=res*power(fac[cnt[i]],mod-2)%mod;
			return res;
		}
		int countAnagrams(string s) {
			const int n=s.size();
			fac.resize(n+1);
			fac[0]=1;
			for(int i=1;i<=n;i++)
				fac[i]=fac[i-1]*i%mod;

			ll res=1;
			for(int i=0;i<n;i++)
			{
				string sub;
				while(i<n&&s[i]!=' ')
				{
					sub+=s[i++];
				}
				res=res*solve(sub)%mod;
			}
			return res;
		}
};


int main() 
{
	Solution s;
	cout<<s.countAnagrams("too hot")<<endl;
	cout<<s.countAnagrams("aa")<<endl;
	return 0;
}
