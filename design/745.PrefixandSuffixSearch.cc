/*
   Design a special dictionary that searches the words in it by a prefix and a suffix.

   Implement the WordFilter class:

   WordFilter(string[] words) Initializes the object with the words in the dictionary.
   f(string pref, string suff) Returns the index of the word in the dictionary, which has the prefix pref and the suffix suff. If there is more than one valid index, return the largest of them. If there is no such word in the dictionary, return -1.



   Example 1:

   Input
   ["WordFilter", "f"]
   [[["apple"]], ["a", "e"]]
   Output
   [null, 0]
   Explanation
   WordFilter wordFilter = new WordFilter(["apple"]);
   wordFilter.f("a", "e"); // return 0, because the word at index 0 has prefix = "a" and suffix = "e".



Constraints:

1 <= words.length <= 104
1 <= words[i].length <= 7
1 <= pref.length, suff.length <= 7
words[i], pref and suff consist of lowercase English letters only.
At most 104 calls will be made to the function f.

*/


#include"head.h"
/*
class TrieNode
{
	public:
		TrieNode *children;
		int id;
	public:
	TrieNode()
	{
		children=new TrieNode[27];
	}
};
class Trie{
	public:
		TrieNode *root;
	public:
		Trie()
		{
			root=new TrieNode();
		}
		void insert(string s,int num)
		{
			TrieNode *node=root;
			for(int i=0;i<s.size();i++)
			{
				char c=s[i];
				if(node->children[c-'a']==NULL)
					node->children[c-'a']=new TrieNode();
				node=node->children[c-'a'];
				node->id=num;
			}
		}

		int search(string prefix)
		{
			TrieNode *node=root;
			for(int i=0;i<prefix.size();i++)
			{
				char c=prefix[i];
				if(node->children[c-'a']==NULL) return -1;

				node=node->children[c-'a'];
			}
			return node->id;
		}
};

class WordFilter {
	public:
		WordFilter(vector<string>& words) {
		r=new Trie();
		for(int i=0;i<words.size();i++)
			for(int j=0;j<Words[i].size();j++)
			{
				string cur=words[i];
				Trie.insert(cur.substr(j,cur.size())+"{"+cur,i);
			}

		}

		int f(string pref, string suff) {
		return Trie.search(suffix,+"{"+prefix);
		}
	private:
		Trie *r;
};
*/
class WordFilter{
	public:
		int son[1500000][27]={},val[1500000]={},idx=0;
		void insert(string &s,int id)
		{
			int p=0,u;
			for(int i=0;i<s.size();i++)
			{
				char c=s[i];
				if(c=='#') u=26;
				else u=c-'a';
				if(!son[p][u]) son[p][u]=++idx;
				p=son[p][u];
				val[p]=id;
			}
		}

		int query(string &s)
		{
			int p=0,u=0;
			for(int i=0;i<s.size();i++)
			{
				char c=s[i];
				if(c=='#') u=26;
				else u=c-'a';

				if(!son[p][u])return -1;
				p=son[p][u];
			}
			return val[p];
		}
		WordFilter(vector<string>&words)
		{
			int n=words.size();
			for(int i=0;i<n;i++)
			{
				string cur="#"+words[i];
				insert(cur,i);
				for(int j=words[i].size()-1;j>=0;j--)
				{
					cur=words[i][j]+cur;
					insert(cur,i);
				}
			}
		}
		int f(string prefix,string suffix)
		{
			string cur=suffix+"#"+prefix;
			return query(cur);
		}
};
int main() 
{
	vector<string> words={{"apple"}};
	WordFilter wf(words);
	cout<<wf.f("a","e")<<endl;
	return 0;
}
