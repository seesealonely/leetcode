/*
   You are given a string word and an array of strings forbidden.

   A string is called valid if none of its substrings are present in forbidden.

   Return the length of the longest valid substring of the string word.

   A substring is a contiguous sequence of characters in a string, possibly empty.



   Example 1:

Input: word = "cbaaaabc", forbidden = ["aaa","cb"]
Output: 4
Explanation: There are 9 valid substrings in word: "c", "b", "a", "ba", "aa", "bc", "baa", "aab", and "aabc". The length of the longest valid substring is 4.
It can be shown that all other substrings contain either "aaa" or "cb" as a substring.

Example 2:

Input: word = "leetcode", forbidden = ["de","le","e"]
Output: 4
Explanation: There are 11 valid substrings in word: "l", "t", "c", "o", "d", "tc", "co", "od", "tco", "cod", and "tcod". The length of the longest valid substring is 4.
It can be shown that all other substrings contain either "de", "le", or "e" as a substring.



Constraints:

1 <= word.length <= 105
word consists only of lowercase English letters.
1 <= forbidden.length <= 105
1 <= forbidden[i].length <= 10
forbidden[i] consists only of lowercase English letters.

*/

#define c11
#include"head.h"
class Solution {
	public:
		int longestValidSubstring(string word, vector<string>& forbidden) {
			unordered_set<string> s(forbidden.begin(),forbidden.end());
			int res=0,n=word.size();
			for(int l=0,r=0;r<n;r++)
			{
				for(int i=r;i>max(r-10,l-1);--i)
					if(s.count(word.substr(i,r-i+1)))
					{
						l=i+1;
						break;
					}
				res=max(res,r-l+1);
			}
			return res;
		}
};


int main() 
{
	Solution s;
	vector<string> forbidden = {"aaa","cb"};
	cout<<s.longestValidSubstring("cbaaaabc",forbidden)<<endl;
	forbidden.clear();forbidden={"de","le","e"};
	cout<<s.longestValidSubstring("leetcode",forbidden)<<endl;
	return 0;
}
