#include<iostream>
#include<string>
#include<vector>
using namespace std;
void dfs(string digits,int begin,string point,vector<string> &v)
{
	int num[]={0,3,6,9,12,15,19,22,26};
	int tmp=digits[begin]-'0'-2;
	for(int i=num[tmp];i<num[tmp+1];i++)
	{
		point.push_back('a'+i);
		if(begin+1<=digits.size()-1)
			dfs(digits,begin+1,point,v);	
		if(begin==(digits.size()-1))
			v.push_back(point);
		point.erase(point.size()-1);
	}
}
class Solution {
	public:
		vector<string> letterCombinations(string digits) {
			string point;
			vector<string>  v;
			if(!digits.empty())
				dfs(digits,0,point,v);
			return v;
		}
};
