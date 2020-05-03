/*
   Given a roman numeral, convert it to an integer.

   Input is guaranteed to be within the range from 1 to 3999.
   */
#include"head.h"
class Solution {
	public:
		int romanToInt(string s)
		{
			if(s.empty()) return 0;
			int map[24]={0};
			map['I'-'A']=1;
			map['V'-'A']=5;
			map['X'-'A']=10;
			map['L'-'A']=50;
			map['C'-'A']=100;
			map['D'-'A']=500;
			map['M'-'A']=1000;
			int res=map[s[s.size()-1]-'A'];
			for(int i=s.size()-2;i>=0;--i)
			res+=(map[s[i]-'A']<map[s[i+1]-'A']?-map[s[i]-'A']:map[s[i]-'A']);
			return res;
	
		}
};
