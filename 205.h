#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
       int m[128]={0},m1[128]={0};
	for(int i=0;i<s.size()||i<t.size();++i)
	{
	if(m[s[i]]!=m1[t[i]]) 
	return false;
	else {m[s[i]]=m1[t[i]]=i+1;}
	} 
	return true;
}
};
