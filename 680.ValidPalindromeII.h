/*
 Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:

Input: "aba"
Output: True

Example 2:

Input: "abca"
Output: True
Explanation: You could delete the character 'c'.

Note:

    The string will only contain lowercase characters a-z. The maximum length of the string is 50000.

*/

#include"head.h"

class Solution {
public:
    bool validPalindrome(string s) {
	
	for(int i=0,j=s.size()-1;i<j;i++,j--)
	{
		if(s[i]!=s[j])
		{
			int i1=i+1,j1=j,i2=i,j2=j-1;
			while(i1<j1&&s[i1]==s[j1]) i1++,j1--;
			while(i2<j2&&s[i2]==s[j2]) i2++,j2--;
			return i1>=j1||i2>=j2;
		}
	}	        
	return true;
    }
};
