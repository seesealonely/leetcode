#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
 	int  hl=haystack.size(),nl=needle.size();
	if(!nl)	return 0;
	for(int i=0;i<hl-nl+1;i++)
	{
	for(int j=0;j<nl;j++)
		if(haystack[i+j]!=needle[j])
			break;
	if(j==nl) return i;       
	}
	return -1;
    }
};

