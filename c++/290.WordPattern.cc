/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:

    pattern = "abba", str = "dog cat cat dog" should return true.
    pattern = "abba", str = "dog cat cat fish" should return false.
    pattern = "aaaa", str = "dog cat cat dog" should return false.
    pattern = "abba", str = "dog dog dog dog" should return false.

Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space. 
*/

#include"290.WordPattern.h"

int main()
{
	string p("abba"),m("dog cat cat dog");
	Solution s;	
	cout<<s.wordPattern(p,m)<<endl;
	cout<<s.wordPattern("abba","dog cat cat fish")<<endl;
	return 0;
}
