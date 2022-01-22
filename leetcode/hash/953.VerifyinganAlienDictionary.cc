/*
   In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

   Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographically in this alien language.



   Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.

Example 2:

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.

Example 3:

Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).



Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 20
order.length == 26
All characters in words[i] and order are English lowercase letters.

*/
#include"head.h"
class Solution {
	public:
		bool isAlienSorted(vector<string>& words, string order) {
		vector<int> hash(26,0);
		for(int i=0;i<order.size();i++)
			hash[order[i]-'a']=i;

		for(int i=1;i<words.size();i++)
			if(cmp(words[i-1],words[i],hash)>0)
				return false;

		return true;
		}
		static int cmp(string x,string y,vector<int> hash)
		{
			for(int i=0;i<x.size()&&i<y.size();i++)
			{
				int sub=hash[x[i]-'a']-hash[y[i]-'a'];
				if(sub!=0)
					return sub;
			}
			return x.size()-y.size();
		}
};
int main() 
{
	Solution s;
	vector<string> v={"hello","leetcode"};
	cout<<s.isAlienSorted(v,"hlabcdefgijkmnopqrstuvwxyz")<<endl;
	v.clear();v={"word","world","row"};
	cout<<s.isAlienSorted(v,"worldabcefghijkmnpqstuvxyz")<<endl;
	v.clear();v={"apple","app"};
	cout<<s.isAlienSorted(v,"abcdefghijklmnopqrstuvwxyz")<<endl;
	return 0;
}
