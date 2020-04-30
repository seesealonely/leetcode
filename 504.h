#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
class Solution {
	public:
		string convertToBase7(int num) {
			string res;
			if(num==0)
			{
			res.push_back('0');
			return res;
			}
			bool flag=false;
			if(num<0) 
			{
				flag=true;
				num=0-num;
			}
			while(num)
			{
				res.push_back('0'+num%7);
				num/=7;
			}       
			if(flag) res.push_back('-');
			reverse(res.begin(),res.end());
			return res;
		}
};
