/*
Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.

 

Example 1:

Input: "Hello"
Output: "hello"

Example 2:

Input: "here"
Output: "here"

Example 3:

Input: "LOVELY"
Output: "lovely"
*/

#include"head.h"

class Solution {
public:
    string toLowerCase(string str) {
 	int diff='A'-'a';       
	string res(str);
	for(int i=0;i<res.size();i++)
	if(res[i]<='Z'&&res[i]>='A')
	res[i]=res[i]-diff;
	return res;	
    }
};

