/*
 Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.

Note: You may assume the string contain only lowercase letters. 
*/

#include"387.FirstUniqueCharacterinaString.h"

int main()
{
	string ss("leetcode");
	string ss1("loveleetcode");
	Solution s;
	cout<<s.firstUniqChar(ss)<<endl;
	cout<<s.firstUniqChar(ss1)<<endl;
	return 0;
}
