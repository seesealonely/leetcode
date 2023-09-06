/*
   You are given a string s and an integer k.

   A k-subsequence is a subsequence of s, having length k, and all its characters are unique, i.e., every character occurs once.

   Let f(c) denote the number of times the character c occurs in s.

   The beauty of a k-subsequence is the sum of f(c) for every character c in the k-subsequence.

   For example, consider s = "abbbdd" and k = 2:

   f('a') = 1, f('b') = 3, f('d') = 2
   Some k-subsequences of s are:
   "abbbdd" -> "ab" having a beauty of f('a') + f('b') = 4
   "abbbdd" -> "ad" having a beauty of f('a') + f('d') = 3
   "abbbdd" -> "bd" having a beauty of f('b') + f('d') = 5

   Return an integer denoting the number of k-subsequences whose beauty is the maximum among all k-subsequences. Since the answer may be too large, return it modulo 109 + 7.

   A subsequence of a string is a new string formed from the original string by deleting some (possibly none) of the characters without disturbing the relative positions of the remaining characters.

   Notes

   f(c) is the number of times a character c occurs in s, not a k-subsequence.
   Two k-subsequences are considered different if one is formed by an index that is not present in the other. So, two k-subsequences may form the same string.



   Example 1:

Input: s = "bcca", k = 2
Output: 4
Explanation: From s we have f('a') = 1, f('b') = 1, and f('c') = 2.
The k-subsequences of s are: 
bcca having a beauty of f('b') + f('c') = 3 
bcca having a beauty of f('b') + f('c') = 3 
bcca having a beauty of f('b') + f('a') = 2 
bcca having a beauty of f('c') + f('a') = 3
bcca having a beauty of f('c') + f('a') = 3 
There are 4 k-subsequences that have the maximum beauty, 3. 
Hence, the answer is 4. 

Example 2:

Input: s = "abbcd", k = 4
Output: 2
Explanation: From s we have f('a') = 1, f('b') = 2, f('c') = 1, and f('d') = 1. 
The k-subsequences of s are: 
abbcd having a beauty of f('a') + f('b') + f('c') + f('d') = 5
abbcd having a beauty of f('a') + f('b') + f('c') + f('d') = 5 
There are 2 k-subsequences that have the maximum beauty, 5. 
Hence, the answer is 2. 



Constraints:

1 <= s.length <= 2 * 105
1 <= k <= s.length
s consists only of lowercase English letters.

*/


#include"head.h"
class Solution {
	public:
		typedef long long ll;
		const int mod=1e9+7;
		int countKSubsequencesWithMaxBeauty(string s, int k) {
		const int n=s.size();
		vector<int> hash(26,0);
		for(int i=0;i<n;i++)
			++hash[s[i]-'a'];

		sort(hash.begin(),hash.end(),[](int x,int y)
				{
				return x>y;
				});
		ll res=1;
		for(int i=0,cnt=0;i<26&&k>0;i++)
		{
			++cnt;
			if(i<25&&hash[i]==hash[i+1])
				continue;
			res=res*pow(hash[i],min(cnt,k))%mod;

			if(k>=cnt)
				k-=cnt;
			else
				res=res*C(cnt,k)%mod,k=0;
			cnt=0;
		}
		if(k>0)
			return 0;
		return res;
		}
		int pow(int x,int  y)
		{
			ll res=1,p=x;
			for(;y;y>>=1)
			{
				if(y&1) res=res*p%mod;
				p=p*p%mod;
			}
			return res;
		}
		int C(int x,int y)
		{
			ll res=1;
			for(int i=1;i<=x;i++)
				res=res*i%mod;

			for(int i=1;i<=x-y;i++)
				res=res*pow(i,mod-2)%mod;

			for(int i=1;i<=y;i++)
				res=res*pow(i,mod-2)%mod;
			return res;
		}
};


int main() 
{
	Solution s;
	cout<<s.countKSubsequencesWithMaxBeauty("bcca",2)<<endl;
	cout<<s.countKSubsequencesWithMaxBeauty("abbcd",4)<<endl;
	return 0;
}
