/*
   Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

   Only one letter can be changed at a time.
   Each transformed word must exist in the word list. Note that beginWord is not a transformed word.

Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.

Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.

*/

#include"head.h"

class Solution {
	public:
		int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
			return bfs(beginWord,endWord,wordList);
		}
		int bfs(string beginWord, string endWord, vector<string>& wordList) {
			unordered_set<string> set(wordList.begin(),wordList.end());
			queue<string> qu;
			qu.push(beginWord);set.erase(beginWord); 
			int res=0;
			while(!qu.empty())
			{
				for(int i=qu.size();i>0;i--)
				{
					string cur=qu.front();qu.pop();	
					if(cur==endWord) return res+1;
					for(int j=0;j<cur.size();j++)
					{
						char  c=cur[j];	
						for(int k=0;k<26;k++)
						{
							cur[j]='a'+k;
							if(set.find(cur)!=set.end())
							{
								qu.push(cur);
								set.erase(cur);
							}
						}	
						cur[j]=c;
					}
				}
				res++;
			}
			return 0;
		}
};
