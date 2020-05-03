/*
Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

You can use each character in text at most once. Return the maximum number of instances that can be formed.

 

Example 1:

Input: text = "nlaebolko"
Output: 1

Example 2:

Input: text = "loonbalxballpoon"
Output: 2

Example 3:

Input: text = "leetcode"
Output: 0

 

Constraints:

    1 <= text.length <= 10^4
    text consists of lower case English letters only.

*/

#include"head.h"

class Solution {
public:
    int maxNumberOfBalloons(string text) {
	vector<int> hash(26);
	for(int i=0;i<text.size();i++)
	       hash[text[i]-'a']++; 
	int res=INT_MAX;
	res=min(res,hash['a'-'a']);
	res=min(res,hash['b'-'a']);
	res=min(res,hash['l'-'a']/2);
	res=min(res,hash['o'-'a']/2);
	res=min(res,hash['n'-'a']);
	return res;
    }
};
