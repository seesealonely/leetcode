/*
   Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.

   Example 1

Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2

Output: [0, 2]

Example 2

Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10

Output: [-34, -14, -10, -10, 10]
*/

#include"head.h"
class Solution {
	public:
		vector<int> diffWaysToCompute(string input) {
			return dfs(input);
		}
		vector<int>  dfs(string s)
		{
			vector<int> res;
			for(unsigned int i=0;i<s.size();++i)
				if(ispunct(s[i]))
				{
					vector<int>  preH=dfs(s.substr(0,i));
					vector<int>  nextH=dfs(s.substr(i+1));
					for(unsigned int j=0;j<preH.size();++j)
						for(unsigned int k=0;k<nextH.size();++k)
						{
							if(s[i]=='+')
								res.push_back(preH[j]+nextH[k]);
							else if(s[i]=='-')
								res.push_back(preH[j]-nextH[k]);
							else if(s[i]=='*')
								res.push_back(preH[j]*nextH[k]);
						}
				}
			if(res.empty())
				res.push_back(atoi(s.c_str()));
			return res;
		}
};
