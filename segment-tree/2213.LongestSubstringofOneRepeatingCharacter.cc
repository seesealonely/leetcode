/*
   You are given a 0-indexed string s. You are also given a 0-indexed string queryCharacters of length k and a 0-indexed array of integer indices queryIndices of length k, both of which are used to describe k queries.

   The ith query updates the character in s at index queryIndices[i] to the character queryCharacters[i].

   Return an array lengths of length k where lengths[i] is the length of the longest substring of s consisting of only one repeating character after the ith query is performed.



   Example 1:

Input: s = "babacc", queryCharacters = "bcb", queryIndices = [1,3,3]
Output: [3,3,4]
Explanation:
- 1st query updates s = "bbbacc". The longest substring consisting of one repeating character is "bbb" with length 3.
- 2nd query updates s = "bbbccc".
The longest substring consisting of one repeating character can be "bbb" or "ccc" with length 3.
- 3rd query updates s = "bbbbcc". The longest substring consisting of one repeating character is "bbbb" with length 4.
Thus, we return [3,3,4].

Example 2:

Input: s = "abyzz", queryCharacters = "aa", queryIndices = [2,1]
Output: [2,3]
Explanation:
- 1st query updates s = "abazz". The longest substring consisting of one repeating character is "zz" with length 2.
- 2nd query updates s = "aaazz". The longest substring consisting of one repeating character is "aaa" with length 3.
Thus, we return [2,3].



Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
k == queryCharacters.length == queryIndices.length
1 <= k <= 105
queryCharacters consists of lowercase English letters.
0 <= queryIndices[i] < s.length

*/


#include"head.h"
class Solution {
	public:
		string s;
		vector<int> pre,suf,mx;
		void maintain(int o,int l,int r)
		{
			pre[o]=pre[o<<1];
			suf[o]=suf[o<<1|1];
			mx[o]=max(mx[o<<1],mx[o<<1|1]);
			int m=(l+r)>>1;
			if(s[m-1]==s[m])
			{
				if(suf[o<<1]==m-l+1) pre[o]+=pre[o<<1|1];
				if(pre[o<<1|1]==r-m) suf[o]+=suf[o<<1];
				mx[o]=max(mx[o],suf[o<<1]+pre[o<<1|1]);
			}
		}
		void build(int o,int l,int r)
		{
			if(l==r)
			{
				pre[o]=suf[o]=mx[o]=1;
				return ;
			}
			int m=(l+r)>>1;
			build(o<<1,l,m);
			build(o<<1|1,m+1,r);
			maintain(o,l,r);
		}

		void update(int o,int l,int r,int i)
		{
			if(l==r) return ;
			int m=(l+r)>>1;
			if(i<=m) update(o<<1,l,m,i);
			else update(o<<1|1,m+1,r,i);
			maintain(o,l,r);
		}
		vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
		this->s=s;
		int n=s.size(),m=queryIndices.size();
		pre.resize(n<<2);
		suf.resize(n<<2);
		mx.resize(n<<2);

		build(1,1,n);
		vector<int> res(m);
		for(int i=0;i<m;i++)
		{
			this->s[queryIndices[i]]=queryCharacters[i];
			update(1,1,n,queryIndices[i]+1);
			res[i]=mx[1];
		}
		return res;
		}
};


int main() 
{
	Solution s;
	vector<int> q={1,3,3};
	show(s.longestRepeating("babacc","bcb",q));
	q.clear();q={2,1};
	show(s.longestRepeating("abyzz","aa",q));
	return 0;
}
