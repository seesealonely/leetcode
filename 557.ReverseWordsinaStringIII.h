/*
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:

Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

Note: In the string, each word is separated by single space and there will not be any extra space in the string. 
*/

#include"head.h"

class Solution {
public:
    string reverseWords(string s) {
	for(int begin=0,end=0;end<s.size()+1;)
	if(s[end]!=' '&&end!=s.size()) end++;        
	else
	{
		reverse(s,begin,end-1);
		while(s[end++]==' ') ;
		begin=end-1;
	}
	return s;
    }
private:
	inline void reverse(string &s,int begin,int end)
	{
		int temp;
		for(;begin<end;++begin,--end) 		
		{
		temp=s[begin];
		s[begin]=s[end];
		s[end]=temp;
		}
	}
};
