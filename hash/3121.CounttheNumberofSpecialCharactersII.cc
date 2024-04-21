/*
   You are given a string word. A letter c is called special if it appears both in lowercase and uppercase in word, and every lowercase occurrence of c appears before the first uppercase occurrence of c.

   Return the number of special letters in word.



   Example 1:

Input: word = "aaAbcBC"

Output: 3

Explanation:

The special characters are 'a', 'b', and 'c'.

Example 2:

Input: word = "abc"

Output: 0

Explanation:

There are no special characters in word.

Example 3:

Input: word = "AbBCab"

Output: 0

Explanation:

There are no special characters in word.



Constraints:

1 <= word.length <= 2 * 105
word consists of only lowercase and uppercase English letters.

*/


#include"head.h"
class Solution {
	public:
		int numberOfSpecialChars(string word) {
		const int n=word.size();
		unordered_map<char,int> s,S;
		for(int i=0;i<n;i++)
			if(word[i]>='a'&&word[i]<='z')
				s[word[i]]=i;

		for(int i=n-1;i>=0;i--)
			if(word[i]>='A'&&word[i]<='Z')
				S[word[i]]=i;
		int res=0;
		for(char c='a';c<='z';c++)
			if(s.count(c)&&S.count(c-'a'+'A')&&s[c]<S[c-'a'+'A'])
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
