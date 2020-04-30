#include<iostream>
#include<string>
using namespace std;
class Solution {
	public:
		string toHex(int num) {
			char hash[]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
			if(num==0) return "0";
			string res;
			while(num)
			{
			res=hash[num&15]+res;	
			num=(unsigned int)num>>4;
			}       
		return res;
		}
};
