/*
   You are given a 0-indexed string s and are tasked with finding two non-intersecting palindromic substrings of odd length such that the product of their lengths is maximized.

   More formally, you want to choose four integers i, j, k, l such that 0 <= i <= j < k <= l < s.length and both the substrings s[i...j] and s[k...l] are palindromes and have odd lengths. s[i...j] denotes a substring from index i to index j inclusive.

   Return the maximum possible product of the lengths of the two non-intersecting palindromic substrings.

   A palindrome is a string that is the same forward and backward. A substring is a contiguous sequence of characters in a string.



   Example 1:

Input: s = "ababbb"
Output: 9
Explanation: Substrings "aba" and "bbb" are palindromes with odd length. product = 3 * 3 = 9.

Example 2:

Input: s = "zaaaxbbby"
Output: 9
Explanation: Substrings "aaa" and "bbb" are palindromes with odd length. product = 3 * 3 = 9.



Constraints:

2 <= s.length <= 105
s consists of lowercase English letters.

*/


#include"head.h"
#define ULL unsigned long long 
#define LL long long
const int N=100010;
const int base=13331;
class Solution {
	private:
		ULL h1[N],h2[N],power[N];
		int left[N],right[N];
		int pre[N],suf[N];
	bool check(int p,int len)
	{
		int l=p-len+1,r=p+len-1;
		return h1[r]-h1[l-1]*power[r-l+1]==h2[l]-h2[r+1]*power[r-l+1];
	}
	public:
		long long maxProduct(string s) {
		const int n=s.size();
		power[0]=1;
		for(int i=1;i<=n;i++)
			power[i]=power[i-1]*base;

		h1[0]=0;
		for(int i=1;i<=n;i++)
			h1[i]=h1[i-1]*base+s[i-1];

		h2[n+1]=0;
		for(int i=n;i>0;i--)
			h2[i]=h2[i+1]*base+s[i-1];

		for(int i=1;i<=n;i++)
		{
			int l=1,r=min(i,n-i+1);
			while(l<r)
			{
				int mid=(l+r)>>1;
				if(check(i,mid+1)) l=mid+1;
				else r=mid;
			}
			left[i]=i-l+1;
			right[i]=i+l-1;
		}

		pre[0]=0;
		for(int i=1,j=1;i<=n;i++)
		{
			while(right[j]<i) j++;
			pre[i]=max(pre[i-1],2*(i-j)+1);
		}

		suf[n+1]=0;
		for(int i=n,j=n;i>0;i--)
		{
			while(left[j]>i) j--;
			suf[i]=max(suf[i+1],2*(j-i)+1);
		}

		LL res=0;
		for(int i=1;i<n;i++)
			res=max(res,(LL)pre[i]*suf[i+1]);
		return res;
		}
};


int main() 
{
	Solution s;
	cout<<s.maxProduct("ababbb")<<endl;
	cout<<s.maxProduct("zaaaxbbby")<<endl;
	return 0;
}
