#include<iostream>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
 	if(n<=2) return n;
	int  nminusone=2,nminustwo=1,res;
	for(int i=3;i<=n;i++)
	{
		res=nminusone+nminustwo;
		nminustwo=nminusone;
		nminusone=res;	
	}       
	return res;
    }
};
