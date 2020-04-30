/*
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

    The length of both num1 and num2 is < 5100.
    Both num1 and num2 contains only digits 0-9.
    Both num1 and num2 does not contain any leading zero.
    You must not use any built-in BigInteger library or convert the inputs to integer directly.

*/

#include"head.h"

class Solution {
public:
    string addStrings(string num1, string num2) {
 	string res;
	int n1,n2;
	for(int i1=num1.size()-1,i2=num2.size()-1,add=0;i1>=0||i2>=0||add;i1--,i2--)
	{
		n1=i1<0?0:num1[i1]-'0';	
		n2=i2<0?0:num2[i2]-'0';	
		res+=((n1+n2+add)%10+'0');
		add=(n1+n2+add)/10;
	}
	reverse(res.begin(),res.end());
	return res;
    }
};
