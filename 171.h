#include<iostream>
#include<string>
using namespace std;
class Solution {
	public:
		int titleToNumber(string s) {
			int res=0,start=0;
			while(start<s.size())
			{
				res*=26;
				res+=s[start++]-'A'+1; 
			}
			return res;
		}
};
