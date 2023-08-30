/*
   You are given a valid boolean expression as a string expression consisting of the characters '1','0','&' (bitwise AND operator),'|' (bitwise OR operator),'(', and ')'.

   For example, "()1|1" and "(1)&()" are not valid while "1", "(((1))|(0))", and "1|(0&(1))" are valid expressions.

   Return the minimum cost to change the final value of the expression.

   For example, if expression = "1|1|(0&0)&1", its value is 1|1|(0&0)&1 = 1|1|0&1 = 1|0&1 = 1&1 = 1. We want to apply operations so that the new expression evaluates to 0.

   The cost of changing the final value of an expression is the number of operations performed on the expression. The types of operations are described as follows:

   Turn a '1' into a '0'.
   Turn a '0' into a '1'.
   Turn a '&' into a '|'.
   Turn a '|' into a '&'.

Note: '&' does not take precedence over '|' in the order of calculation. Evaluate parentheses first, then in left-to-right order.



Example 1:

Input: expression = "1&(0|1)"
Output: 1
Explanation: We can turn "1&(0|1)" into "1&(0&1)" by changing the '|' to a '&' using 1 operation.
The new expression evaluates to 0.

Example 2:

Input: expression = "(0&0)&(0&0&0)"
Output: 3
Explanation: We can turn "(0&0)&(0&0&0)" into "(0|1)|(0&0&0)" using 3 operations.
The new expression evaluates to 1.

Example 3:

Input: expression = "(0|(1|0&1))"
Output: 1
Explanation: We can turn "(0|(1|0&1))" into "(0|(0|0&1))" using 1 operation.
The new expression evaluates to 0.



Constraints:

1 <= expression.length <= 105
expression only contains '1','0','&','|','(', and ')'
All parentheses are properly matched.
There will be no empty parentheses (i.e: "()" is not a substring of expression).

*/


#include"head.h"
class Solution {
	public:
		int minOperationsToFlip(string expression) {
		stack<pair<int,int>> nums;
		stack<char> ops;

		for(int i=0;i<expression.size();i++)
		{
			char c=expression[i];
			if(c=='0'||c=='1'||c==')')
			{
				if(c=='0') nums.push({0,1});
				else if(c=='1') nums.push({1,0});
				else
				{
					if(ops.top()=='(')
						ops.pop();
				}
				if(ops.size()>0&&ops.top()!='(')
				{
					pair<int,int> x=nums.top();
					nums.pop();
					pair<int,int> y=nums.top();
					nums.pop();
					if(ops.top()=='&')
						nums.push({min(x.first,y.first),min(x.second+y.second,1+min(x.second,y.second))});
					else
						nums.push({min(x.first+y.first,1+min(x.first,y.first)),min(x.second,y.second)});
					ops.pop();
				}
			}
			else
				ops.push(c);
		}
		return max(nums.top().first,nums.top().second);
		}
};


int main() 
{
	Solution s;
	cout<<s.minOperationsToFlip("1&(0|1)")<<endl;
	cout<<s.minOperationsToFlip("(0&0)&(0&0&0)")<<endl;
	cout<<s.minOperationsToFlip("(0|(1|0&1))")<<endl;
	return 0;
}
