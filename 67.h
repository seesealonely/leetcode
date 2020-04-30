#include<iostream>
#include<string>
using namespace std;
class Solution {
	public:
		string addBinary(string a, string b) {
			string s;
			for(int alast=a.size()-1,blast=b.size()-1,flag=0;alast>=0||blast>=0||flag==1;alast--,blast--)
			{
			flag+=alast>=0?a[alast]-'0':0;
			flag+=blast>=0?b[blast]-'0':0;
			s=(char)(flag%2+'0')+s;
			flag/=2;
			}
			return s;
		}
};
