/*
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:

Input: ["abcw","baz","foo","bar","xtfn","abcdef"]
Output: 16 
Explanation: The two words can be "abcw", "xtfn".

Example 2:

Input: ["a","ab","abc","d","cd","bcd","abcd"]
Output: 4 
Explanation: The two words can be "ab", "cd".

Example 3:

Input: ["a","aa","aaa","aaaa"]
Output: 0 
Explanation: No such pair of words.

*/

#include"318.MaximumProductofWordLengths.h"

int main()
{
	vector<string> v;
v.push_back("abcw");
v.push_back("baz");
v.push_back("foo");
v.push_back("bar");
v.push_back("xtfn");
v.push_back("abcdef");
	Solution s;
	cout<<s.maxProduct(v)<<endl;
	v.clear();
v.push_back("a");
v.push_back("ab");
v.push_back("abc");
v.push_back("d");
v.push_back("cd");
v.push_back("bcd");
v.push_back("abcd");
	cout<<s.maxProduct(v)<<endl;
	return 0;
}
