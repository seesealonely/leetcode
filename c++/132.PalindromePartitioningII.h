/*
   Given a string s, partition s such that every substring of the partition is a palindrome.

   Return the minimum cuts needed for a palindrome partitioning of s.

   For example, given s = "aab",
   Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut. 
   */

#include"head.h"

class Solution {
	public:
		int minCut(string s) {
			vector<int> cut(s.size()+1,0);
			for(int i=0;i<=s.size();++i) cut[i]=i-1;
			for(int i=0;i<s.size();++i)
			{
				for(int j=0;i-j>=0&&i+j<s.size()&&s[i-j]==s[i+j];++j)
					cut[i+j+1]=min(cut[i+j+1],1+cut[i-j]);
				for(int j=1;i-j+1>=0&&i+j<s.size()&&s[i-j+1]==s[i+j];++j)
					cut[i+j+1]=min(cut[i+j+1],1+cut[i-j+1]);       
			}
			return cut[s.size()];
		}
};
