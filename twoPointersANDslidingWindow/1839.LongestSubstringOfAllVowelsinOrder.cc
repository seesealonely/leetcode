/*
   A string is considered beautiful if it satisfies the following conditions:

   Each of the 5 English vowels ('a', 'e', 'i', 'o', 'u') must appear at least once in it.
   The letters must be sorted in alphabetical order (i.e. all 'a's before 'e's, all 'e's before 'i's, etc.).

   For example, strings "aeiou" and "aaaaaaeiiiioou" are considered beautiful, but "uaeio", "aeoiu", and "aaaeeeooo" are not beautiful.

   Given a string word consisting of English vowels, return the length of the longest beautiful substring of word. If no such substring exists, return 0.

   A substring is a contiguous sequence of characters in a string.



   Example 1:

Input: word = "aeiaaioaaaaeiiiiouuuooaauuaeiu"
Output: 13
Explanation: The longest beautiful substring in word is "aaaaeiiiiouuu" of length 13.

Example 2:

Input: word = "aeeeiiiioooauuuaeiou"
Output: 5
Explanation: The longest beautiful substring in word is "aeiou" of length 5.

Example 3:

Input: word = "a"
Output: 0
Explanation: There is no beautiful substring, so return 0.



Constraints:

1 <= word.length <= 5 * 105
word consists of characters 'a', 'e', 'i', 'o', and 'u'.

 */
#include"head.h"
class Solution {
	public:
		int longestBeautifulSubstring(string word) {
			vector<char> window;
			set<char> count;
			int res=0;
			for(int l=0,r=0;r<word.size();r++)
			{
				const char c=word[r];
				if(window.empty()||c>=window.back())
				{
					window.push_back(c);
					count.insert(c);
					if(count.size()==5)
						res=max(res,(int)window.size());
				}				
				else
				{
					l=r;
					window.clear();
					count.clear();
					window.push_back(c);
					count.insert(c);
				}
			}	
			return res;
		}
};
int main() 
{
	Solution s;
	cout<<s.longestBeautifulSubstring("aeiaaioaaaaeiiiiouuuooaauuaeiu")<<endl;
	cout<<s.longestBeautifulSubstring("aeeeiiiioooauuuaeiou")<<endl;
	cout<<s.longestBeautifulSubstring("a")<<endl;
	return 0;
}
