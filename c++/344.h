#include<iostream>
#include<string>
using namespace std;
class Solution {
	public:
		string reverseString(string s) {
			char c;
			for(int begin=0,end=s.size()-1;begin<end;begin++,end--)
			{
				c=s[begin];
				s[begin]=s[end];
				s[end]=c;
			}
			return s;
		}
};
