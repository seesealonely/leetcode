/*
*/

#include"head.h"

bool usingQueue(string s,string e)
{
	queue<char> qu;
	if(s.size()!=e.size()) return false;
	for(int i=0;i<s.size();i++)
	if(s[i]!='X') qu.push(s[i]);
	for(int i=0;i<e.size();i++)
	if(e[i]!='X')
	if(e[i]==qu.front()) qu.pop();
	else return false;
	return qu.empty();
}
class Solution {
public:
    bool canTransform(string start, string end) {
	return 	usingQueue(start,end);        
    }
};
