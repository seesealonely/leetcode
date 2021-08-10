/*
   You are given a string s consisting only of characters 'a' and 'b'​​​​.

   You can delete any number of characters in s to make s balanced. s is balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'.

   Return the minimum number of deletions needed to make s balanced.



   Example 1:

Input: s = "aababbab"
Output: 2
Explanation: You can either:
Delete the characters at 0-indexed positions 2 and 6 ("aababbab" -> "aaabbb"), or
Delete the characters at 0-indexed positions 3 and 6 ("aababbab" -> "aabbbb").

Example 2:

Input: s = "bbaaaaabb"
Output: 2
Explanation: The only solution is to delete the first two characters.



Constraints:

1 <= s.length <= 105
s[i] is 'a' or 'b'​​.

*/
#include"head.h"
class Solution {
	public:
		int minimumDeletions(string s) {
			return dp(s);
			return preSum(s);
		}
		int preSum(string s) {
			int n=s.size(),res=INT_MAX;
			vector<int> prea(n+1,0),preb(n+1,0);
			for(int i=0;i<n;i++)
				if(s[i]=='a')
					prea[i+1]=prea[i]+1,preb[i+1]=preb[i];
				else
					preb[i+1]=preb[i]+1,prea[i+1]=prea[i];
			for(int i=0;i<n;i++)
				res=min(res,preb[i]+prea[n]-prea[i+1]);
		return res;
		}
		int dp(string s)
		{
			int a=0,b=0,n=s.size();//a is min num of dels for all a,b is min num of dels for all b;
			for(int i=0;i<n;i++)
				if(s[i]=='a')
					b=min(a,b+1);
				else
					a++;
			return min(a,b);
		}
};
