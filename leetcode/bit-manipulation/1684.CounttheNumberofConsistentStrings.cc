/*
   You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.

   Return the number of consistent strings in the array words.



   Example 1:

Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
Output: 2
Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.

Example 2:

Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
Output: 7
Explanation: All strings are consistent.

Example 3:

Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
Output: 4
Explanation: Strings "cc", "acd", "ac", and "d" are consistent.



Constraints:

1 <= words.length <= 104
1 <= allowed.length <= 26
1 <= words[i].length <= 10
The characters in allowed are distinct.
words[i] and allowed contain only lowercase English letters.

*/
#include"head.h"
class Solution {
	public:
		int countConsistentStrings(string allowed, vector<string>& words) {
		int hash=0,res=0;
		for(int i=0;i<allowed.size();i++)
			hash|=(1<<(allowed[i]-'a'));

		for(int i=0;i<words.size();i++)
		{
			int j=0;
			for(;j<words[i].size();j++)
				if((hash&(1<<(words[i][j]-'a')))==0)
					break;
			if(j==words[i].size())
				res++;
		}
		return res;
		}
};
int main() 
{
	Solution s;
	vector<string> v={"ad","bd","aaab","baa","badab"};
	cout<<s.countConsistentStrings("ab",v)<<endl;
	v.clear();v={"a","b","c","ab","ac","bc","abc"};
	cout<<s.countConsistentStrings("abc",v)<<endl;
	v.clear();v={"cc","acd","b","ba","bac","bad","ac","d"};
	cout<<s.countConsistentStrings("cad",v)<<endl;
	return 0;
}
