/*
   Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:

The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/

#include"head.h"

class Solution {
	public:
		string removeKdigits(string num, int k) {
			string res="";
			char c;
			for(int i=0;c=num[i],i<num.size();++i)       
			{
				while(res.size()&&res[res.size()-1]>c&&k)
				{
					res.resize(res.size()-1);
					k--;
				}
				if(res.size()||c!='0') res.push_back(c);
			}
			while(res.size()&&k--) res.resize(res.size()-1);
			return res.empty()?"0":res;
		}
};
