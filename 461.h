#include<iostream>
using namespace std;
class Solution {
public:
    int hammingDistance(int x, int y) {
 	int res=0;
	int tmp=x^y;
	while(tmp)
	{
		if(tmp&1==1) ++res;
		tmp=tmp>>1;
	}       
	return res;
    }
};
