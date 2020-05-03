/*
*/

#include"head.h"

int usingStack(vector<int> &s)
{
	queue<int> qu;
	int res=0,i=0,pre=0,next=0;
	for(int i=0;i<s.size();i++)
		if(s[i])
		qu.push(i);
	if(qu.front()) res=qu.front();	
	while(qu.size()>1)	
	{
		pre=qu.front();qu.pop();
		next=qu.front();
		res=max(res,(next-pre)/2);
	}
	pre=qu.front();
	if(pre!=s.size()-1)  res=max(res,(int)s.size()-1-pre);
	return res;
}
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
	return usingStack(seats);        
    }
};
