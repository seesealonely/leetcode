/*
*/

#include"head.h"

class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
	if(S.empty()||shifts.empty()) return S;
	string res(S);
	long long sum=0;
	for(int i=S.size()-1;i>=0;i--)
	{
		sum+=shifts[i];
		res[i]=(S[i]-'a'+sum)%26+'a';
	}
	return res;
    }
};
