/*
   Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.

   A concatenated word is defined as a string that is comprised entirely of at least two shorter words (not necesssarily distinct) in the given array.



   Example 1:

Input: words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats";
"dogcatsdog" can be concatenated by "dog", "cats" and "dog";
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".

Example 2:

Input: words = ["cat","dog","catdog"]
Output: ["catdog"]



Constraints:

1 <= words.length <= 104
1 <= words[i].length <= 30
words[i] consists of only lowercase English letters.
All the strings of words are unique.
1 <= sum(words[i].length) <= 105

*/


#include"head.h"
const int N=100010;

struct Node
{
	int next[26];
	bool word;
	Node()
	{
		memset(next,0,sizeof(next));
		word=false;
	}
};

class Solution {
	public:
		vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
			cnt=0;
			root=++cnt;

			for(int i=0;i<words.size();i++)
				insert(words[i]);

			vector<string> res;
			for(int i=0;i<words.size();i++)
				if(check(words[i]))
					res.push_back(words[i]);

			return res;
		}
	private:
		int cnt,root;
		Node node[N];
		void insert(const string &s)
		{
			int p=root;
			for(int i=0;i<s.size();i++)
			{
				int  c=s[i]-'a';
				if(node[p].next[c]==false)
					node[p].next[c]=++cnt;
				p=node[p].next[c];
			}
			node[p].word=true;
		}
		bool check(const string &s)
		{
			const int n=s.size();
			vector<bool> vis(n+1,false);

			vis[0]=true;
			for(int i=0;i<n;i++)
			{
				if(vis[i]==false)
					continue;

				int p=root;
				bool flag=true;
				for(int j=i+1;j<n;j++)
				{
					int  c=s[j-1]-'a';
					if(node[p].next[c]==false)
					{
						flag=false;
						break;
					}

					p=node[p].next[c];
					if(node[p].word)
						vis[j]=true;
				}

				if(flag==false)
					continue;

				p=node[p].next[s.back()-'a'];
				if(i>0&&p>0&&node[p].word)
					return true;
			}
			return false;
		}
};


int main() 
{
	Solution s;
	vector<string> v={"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};
	show(s.findAllConcatenatedWordsInADict(v));
	v.clear();v={"cat","dog","catdog"};
	show(s.findAllConcatenatedWordsInADict(v));
	return 0;
}
