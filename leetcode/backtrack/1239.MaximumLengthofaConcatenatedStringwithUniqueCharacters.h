/*
   You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.

   Return the maximum possible length of s.

   A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.



   Example 1:

Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All the valid concatenations are:
- ""
- "un"
- "iq"
- "ue"
- "uniq" ("un" + "iq")
- "ique" ("iq" + "ue")
Maximum length is 4.

Example 2:

Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible longest valid concatenations are "chaers" ("cha" + "ers") and "acters" ("act" + "ers").

Example 3:

Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
Explanation: The only string in arr has all 26 characters.

Example 4:

Input: arr = ["aa","bb"]
Output: 0
Explanation: Both strings in arr do not have unique characters, thus there are no valid concatenations.



Constraints:

1 <= arr.length <= 16
1 <= arr[i].length <= 26
arr[i] contains only lowercase English letters.

*/
#include"head.h"
class Solution {
	public:
		int maxLength(vector<string>& arr) {
			return backTrace(arr);
			return iteration(arr);
		}

		int iteration(vector<string>& arr) {
			int n=arr.size(),res=0;
			vector<int> masks;masks.push_back(0);
			for(int i=0;i<n;i++)
			{
				int mask=0;
				for(int j=0;j<arr[i].size();j++)
				{
					int ch=arr[i][j]-'a';
					if((mask>>ch)&1)
					{
						mask=0;
						break;
					}
					mask|=1<<ch;
				}
				if(!mask)
					continue;
				int m=masks.size();
				for(int k=0;k<m;k++)
				{
					if((masks[k]&mask)==0)
					{
						masks.push_back(masks[k]|mask);
						res=max(res,countBits(masks[k]|mask));
					}
				}
			}
			return res;
		}
		int backTrace(vector<string>& arr) {
			int n=arr.size(),res=0;
			vector<int> masks;masks.push_back(0);
			for(int i=0;i<n;i++)
			{
				int mask=0;
				for(int j=0;j<arr[i].size();j++)
				{
					int ch=arr[i][j]-'a';
					if((mask>>ch)&1)
					{
						mask=0;
						break;
					}
					mask|=1<<ch;
				}
				if(mask)
					masks.push_back(mask);
			}
			dfs(masks,0,0,res);
			return res;
		}
			void dfs(vector<int> masks,int pos,int mask,int &res)
			{
				if(pos==masks.size())
				{
					res=max(res,countBits(mask));
							return;
				}
				if((mask&masks[pos])==0)
					dfs(masks,pos+1,mask|masks[pos],res);
				dfs(masks,pos+1,mask,res);
			}
		int countBits(int mask)
		{
			int res=0;
			while(mask)
			{
				if((mask&1)==1)
				res++;
				mask>>=1;
			}
			return res;
		}
};
