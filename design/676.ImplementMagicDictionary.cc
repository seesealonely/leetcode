/*
   Design a data structure that is initialized with a list of different words. Provided a string, you should determine if you can change exactly one character in this string to match any word in the data structure.

   Implement the MagicDictionary class:

   MagicDictionary() Initializes the object.
   void buildDict(String[] dictionary) Sets the data structure with an array of distinct strings dictionary.
   bool search(String searchWord) Returns true if you can change exactly one character in searchWord to match any string in the data structure, otherwise returns false.



   Example 1:

   Input
   ["MagicDictionary", "buildDict", "search", "search", "search", "search"]
   [[], [["hello", "leetcode"]], ["hello"], ["hhllo"], ["hell"], ["leetcoded"]]
   Output
   [null, null, false, true, false, false]

   Explanation
   MagicDictionary magicDictionary = new MagicDictionary();
   magicDictionary.buildDict(["hello", "leetcode"]);
   magicDictionary.search("hello"); // return False
   magicDictionary.search("hhllo"); // We can change the second 'h' to 'e' to match "hello" so we return True
   magicDictionary.search("hell"); // return False
   magicDictionary.search("leetcoded"); // return False



Constraints:

1 <= dictionary.length <= 100
1 <= dictionary[i].length <= 100
dictionary[i] consists of only lower-case English letters.
All the strings in dictionary are distinct.
1 <= searchWord.length <= 100
searchWord consists of only lower-case English letters.
buildDict will be called only once before search.
At most 100 calls will be made to search.

*/


#include"head.h"
class MagicDictionary {
	public:
		static const int N=10001;
		int trie[N][26],idx;
		bool end[N];
		MagicDictionary() {
		memset(trie,0,sizeof(trie));
		memset(end,false,sizeof(end));
		idx=1;
		}

		void buildDict(vector<string> dictionary) {
			for(int i=0;i<dictionary.size();i++)
				insert(dictionary[i]);
		}
		void insert(string &s)
		{
			int t=0;
			for(int j=0;j<s.size();j++)
			{
				int i=s[j]-'a';
				if(trie[t][i]==0)
					trie[t][i]=++idx;
				t=trie[t][i];
			}
			end[t]=true;
		}

		bool search(string searchWord) {
		return dfs(searchWord,0,0,0);
		}
		bool dfs(string &s,int si,int t,int diff)
		{
			if(end[t]&&si==s.size()&&diff==1) return true;
			if(diff>1||si==s.size()) return false;

			for(int i=0;i<26;i++)
			{
				if(trie[t][i])
					if(dfs(s,si+1,trie[t][i],diff+(s[si]-'a'!=i)))
						return true;
			}
			return false;
		}
};


int main() 
{
	MagicDictionary magicDictionary = MagicDictionary();
magicDictionary.buildDict({"hello", "leetcode"});
magicDictionary.search("hello"); // return False
magicDictionary.search("hhllo"); // We can change the second 'h' to 'e' to match "hello" so we return True
magicDictionary.search("hell"); // return False
magicDictionary.search("leetcoded"); // return False
	return 0;
}
