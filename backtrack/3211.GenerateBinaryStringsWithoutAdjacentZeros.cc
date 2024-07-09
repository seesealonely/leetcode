/*
   You are given a positive integer n.

   A binary string x is valid if all
   substrings
   of x of length 2 contain at least one "1".

   Return all valid strings with length n, in any order.



   Example 1:

Input: n = 3

Output: ["010","011","101","110","111"]

Explanation:

The valid strings of length 3 are: "010", "011", "101", "110", and "111".

Example 2:

Input: n = 1

Output: ["0","1"]

Explanation:

The valid strings of length 1 are: "0" and "1".



Constraints:

1 <= n <= 18

*/


#include"head.h"
class Solution {
	public:
		vector<string> validStrings(int n) {
			this->n=n;
			string cur;
			backtrack(0,cur);
			return res;
		}
		void backtrack(int st,string cur)
		{
			if(cur.size()==n)
			{
				res.push_back(cur);
				return;
			}
			for(int i=0;i<=1;i++)
			{
				if(st==0||(!cur.empty()&&cur.back()-'0'==1))
				{
					backtrack(st+1,cur+to_string(i));
				}
				else if(st&&cur.back()=='0')
				{
					backtrack(st+1,cur+'1');
					i=2;
				}
			}
		}
	private:
		int n;
		vector<string> res;
};


int main() 
{
	Solution s;
	show(s.validStrings(3));
	show(s.validStrings(1));
	return 0;
}
