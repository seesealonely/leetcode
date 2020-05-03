/*
Write a function to find the longest common prefix string amongst an array of strings. 
*/

#include"14.LongestCommonPrefix.h"

int main()
{
	vector<string> ss;
	ss.push_back("abca");
	ss.push_back("abc");

	Solution s;
	cout<<s.longestCommonPrefix(ss)<<endl;
	return 0;
}
