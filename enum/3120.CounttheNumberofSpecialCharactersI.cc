/*
   You are given a string word. A letter is called special if it appears both in lowercase and uppercase in word.

   Return the number of special letters in word.



   Example 1:

Input: word = "aaAbcBC"

Output: 3

Explanation:

The special characters in word are 'a', 'b', and 'c'.

Example 2:

Input: word = "abc"

Output: 0

Explanation:

No character in word appears in uppercase.

Example 3:

Input: word = "abBCab"

Output: 1

Explanation:

The only special character in word is 'b'.



Constraints:

1 <= word.length <= 50
word consists of only lowercase and uppercase English letters.

*/

#define c11
#include"head.h"
class Solution {
	public:
		int numberOfSpecialChars(string word) {
		unordered_set<char> s(word.begin(),word.end());

		int res=0;
		for(char c='a';c<='z';c++)
			if(s.count(c)&&s.count(c-'a'+'A'))
				++res;
		return res;
		}
};


int main() 
{
	Solution s;
	cout<<s.numberOfSpecialChars("aaAbcBC")<<endl;
	cout<<s.numberOfSpecialChars("abc")<<endl;
	cout<<s.numberOfSpecialChars("abBCab")<<endl;
	return 0;
}
