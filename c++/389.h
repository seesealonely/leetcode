#include<iostream>
#include<map>
using namespace std;
//map
/*
class Solution {
public:
    char findTheDifference(string s, string t) {
       map<char,int> m;
	for(int i=0;i<s.size();i++)
	if(m[s[i]]) m[s[i]]++;
	for(int i=0;i<t.size();i++)
	if(!m[t[i]]) return t[i];
	else  m[t[i]]--;
    }
};
*/
class Solution {
public:
    char findTheDifference(string s, string t) {
	char res=0;
	for(int i=0;i<s.size();i++)
	{
		res^=s[i];
		res^=t[i];
	}
	return res^=t[t.size()-1];
    }
};
