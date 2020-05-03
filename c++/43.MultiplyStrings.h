/*
   Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

   Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"

Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to integer directly.

*/

#include"head.h"

class Solution {
	public:
		string multiply(string num1, string num2) {
			vector<int> pos(num1.size()+num2.size(),0); 	       
			string res;
			int start=0;
			for(int i=num1.size()-1;i>=0;i--)
				for(int j=num2.size()-1;j>=0;j--)
				{
					int mul=(num1[i]-'0')*(num2[j]-'0');
					int p1=i+j,p2=i+j+1;
					int sum=mul+pos[p2];
					pos[p1]+=sum/10;
					pos[p2]=sum%10;
				}
			while((!pos[start])&&start<pos.size()-1) start++;	
			while(start<pos.size()) res+=pos[start++]+'0';
			return res;
		}
};
