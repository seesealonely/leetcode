/*
Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.

Note:

    Input contains only lowercase English letters.
    Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
    Input length is less than 50,000.

Example 1:

Input: "owoztneoer"

Output: "012"

Example 2:

Input: "fviefuro"

Output: "45"

*/

#include"head.h"

class Solution {
public:
    string originalDigits(string s) {
	vector<int> count(10,0);
	string res;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='z') count[0]++;
		if(s[i]=='w') count[2]++;
		if(s[i]=='u') count[4]++;
		if(s[i]=='x') count[6]++;
		if(s[i]=='g') count[8]++;
		if(s[i]=='o') count[1]++;
		if(s[i]=='t') count[3]++;
		if(s[i]=='f') count[5]++;
		if(s[i]=='s') count[7]++;
		if(s[i]=='i') count[9]++;
	}        
	count[3]-=count[2]+count[8];
	count[5]-=count[4];
	count[7]-=count[6];
	count[1]-=count[0]+count[2]+count[4];
	count[9]-=count[5]+count[6]+count[8];
	for(int i=0;i<count.size();i++)
		while(count[i]--)
		res+=to_string(i);
	return res;
    }
};
