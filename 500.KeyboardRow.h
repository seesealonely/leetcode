/*
   Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below. 
   */

#include"head.h"

typedef struct Pair
{
	char c;
	int set;
}Pair;
class Solution {
	public:
	void show(vector<string> res)
	{
	for(int i=0;i<res.size();++i)
		cout<<res[i]<<endl;
	}
		vector<string> findWords(vector<string>& words) {
			Pair p[26]={{'a',1},{'b',2},{'c',2},{'d',1},{'e',0},{'f',1},{'g',1},{'h',1},{'i',0}, {'j',1},{'k',1},{'l',1},{'m',2},{'n',2},{'o',0},{'p',0},{'q',0}, {'r',0},{'s',1},{'t',0},{'u',0},{'v',2},{'w',0},{'x',2},{'y',0},{'z',2}};
			vector<string> res;	
			int i,j;
			for(i=0;i<words.size();++i)
			{
				for(j=0;j<words[i].size();++j)
					if(p[tolower(words[i][0])-'a'].set!=p[tolower(words[i][j])-'a'].set)
						break;
				if(j==words[i].size())res.push_back(words[i]);
			}
			return res;
		}
};
