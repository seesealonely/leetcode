/*
   Return the result of evaluating a given boolean expression, represented as a string.

   An expression can either be:

   "t", evaluating to True;
   "f", evaluating to False;
   "!(expr)", evaluating to the logical NOT of the inner expression expr;
   "&(expr1,expr2,...)", evaluating to the logical AND of 2 or more inner expressions expr1, expr2, ...;
   "|(expr1,expr2,...)", evaluating to the logical OR of 2 or more inner expressions expr1, expr2, ...



   Example 1:

Input: expression = "!(f)"
Output: true

Example 2:

Input: expression = "|(f,t)"
Output: true

Example 3:

Input: expression = "&(t,f)"
Output: false

Example 4:

Input: expression = "|(&(t,f,t),!(t))"
Output: false



Constraints:

1 <= expression.length <= 20000
expression[i] consists of characters in {'(', ')', '&', '|', '!', 't', 'f', ','}.
expression is a valid expression representing a boolean, as given in the description.

*/

#include"head.h"

class Solution {
	public:
		bool parseBoolExpr(string expression) {
			stack<char> opt,nums;
			int res=false;
			for(int i=0;i<expression.size();i++)
			{
				if(expression[i]=='('||expression[i]=='t'||expression[i]=='f')
					nums.push(expression[i]);
				else if(expression[i]=='&'||expression[i]=='|'||expression[i]=='!')
					opt.push(expression[i]);
				else if(expression[i]==')')
				{
					int o=opt.top();opt.pop();
					if(o=='!') 		
					{
						res=!transfer(nums.top());nums.pop();
						nums.pop();
					}
					else if(o=='|')
					{
						res=transfer(nums.top());nums.pop();
						while(nums.top()!='(')
						{res|=transfer(nums.top());nums.pop();}
						nums.pop();
					}
					else if(o=='&')
					{
						res=transfer(nums.top());nums.pop();
						while(nums.top()!='(')
						{res&=transfer(nums.top());nums.pop();}
						nums.pop();
					}
					if(opt.empty())
						return res;
					else	
					{
					if(res) nums.push('t');
					else nums.push('f');
					}
				}
			}        
			return res;
		}
		bool transfer(char c)
		{
			if(c=='t') return true;
			else return false;
		}
};
