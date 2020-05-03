#include<iostream>
#include<string>
using namespace std;
class Solution {
	public:
		int lengthOfLastWord(string s) {
			int len=0;
			for(int i=s.size()-1;i>=0;i--)
			{
				while(s[i]==' '&&i>=0)i--;
				while(s[i]!=' '&&i>=0)
				{
					len++;
					i--;
				}
				break;
			}       
			return len;
		}
};
