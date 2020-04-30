/*
   Implement a basic calculator to evaluate a simple expression string.

   The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

   You may assume that the given expression is always valid.

   Some examples:

   "3+2*2" = 7
   " 3/2 " = 1
   " 3+5 / 2 " = 5

Note: Do not use the eval built-in library function. 
*/

#include"head.h"

class Solution {
	public:
		int calculate(string s) {
			stack<int> st;
			int digit=0,sign='+',res=0;       
			for(int i=0;i<s.size();++i)
			{
				if(isdigit(s[i])) digit=digit*10+s[i]-'0';
				if(!isdigit(s[i])&&s[i]!=' '||i==s.size()-1)
				{
					if(sign=='+')
						st.push(digit);
					else if(sign=='-')
						st.push(-digit);
					else
					{
						if(sign=='*')
							digit=st.top()*digit;
						else
							digit=st.top()/digit;
						st.pop();
						st.push(digit);
					}
					sign=s[i];
					digit=0;
				}
			}
			while(!st.empty()) 
			{
				res+=st.top();
				st.pop();
			}
			return res;
		}
};
