/*
Given a string text, we are allowed to swap two of the characters in the string. Find the length of the longest substring with repeated characters.



Example 1:

Input: text = "ababa"
Output: 3
Explanation: We can swap the first 'b' with the last 'a', or the last 'b' with the first 'a'. Then, the longest repeated character substring is "aaa", which its length is 3.

Example 2:

Input: text = "aaabaaa"
Output: 6
Explanation: Swap 'b' with the last 'a' (or the first 'a'), and we get longest repeated character substring "aaaaaa", which its length is 6.

Example 3:

Input: text = "aaabbaaa"
Output: 4

Example 4:

Input: text = "aaaaa"
Output: 5
Explanation: No need to swap, longest repeated character substring is "aaaaa", length is 5.

Example 5:

Input: text = "abcdef"
Output: 1



Constraints:

1 <= text.length <= 20000
text consist of lowercase English characters only.
*/
#include"head.h"
class Solution {
public:
int maxRepOpt1(string text) {
	vector<vector<int> > count(26);
	for(int i=0;i<text.size();i++)
	count[text[i]-'a'].push_back(i);
	int pre=1,post=0,res=0,curmax=0;
	for(int i=0;i<26;i++)
	{
	pre=1,post=0,curmax=0;
		for(int j=1;j<count[i].size();j++)
		{
		if(count[i][j]==count[i][j-1]+1)
			pre++;
		else
		{
			post=count[i][j]==count[i][j-1]+2?pre:0;
			pre=1;
		}
		curmax=max(curmax,pre+post);
		}
		res=max(curmax+(count[i].size()>curmax?1:0),res);
	}
	return res;
}
};
