#include<iostream>
#include<string>
using namespace std;
class Solution {
	public:
		int countSegments(string s) {
			int res=0;
			for(int i=0;i<s.size();)
			{
				if(s[i]!=' ')	
				{
					res++;
					while(s[i]!=' '&&i<s.size()) i++;       
				}
				while(s[i]==' '&&i<s.size()) i++; 
			}
			return res;
		}
};
