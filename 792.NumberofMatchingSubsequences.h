/*
   Given string S and a dictionary of words words, find the number of words[i] that is a subsequence of S.

Example :
Input: 
S = "abcde"
words = ["a", "bb", "acd", "ace"]
Output: 3
Explanation: There are three words in words that are a subsequence of S: "a", "acd", "ace".

Note:

All words in words and S will only consists of lowercase letters.
The length of S will be in the range of [1, 50000].
The length of words will be in the range of [1, 5000].
The length of words[i] will be in the range of [1, 50].

*/

#include"head.h"

class Solution 
{
	public:
		int numMatchingSubseq(string S, vector<string>& words)
		{
			int res=0;
			vector<vector<int> > hash(26);
			for(int i=0;i<S.size();i++)
				hash[S[i]-'a'].push_back(i);	
			for(int i=0;i<words.size();i++)
			{
				int index=-1;
				bool found=true;
				for(int j=0;j<words[i].size();j++)
				{
					auto it=upper_bound(hash[words[i][j]-'a'].begin(),hash[words[i][j]-'a'].end(),index);
						if(it==hash[words[i][j]-'a'].end()) 
							found=false;
						else 
							index=*it;
				}
				if(found)
					res++;
			}
			return res;
		}
};
