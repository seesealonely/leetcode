/*
   You are given a binary string s. You are allowed to perform two types of operations on the string in any sequence:

   Type-1: Remove the character at the start of the string s and append it to the end of the string.
   Type-2: Pick any character in s and flip its value, i.e., if its value is '0' it becomes '1' and vice-versa.

   Return the minimum number of type-2 operations you need to perform such that s becomes alternating.

   The string is called alternating if no two adjacent characters are equal.

   For example, the strings "010" and "1010" are alternating, while the string "0100" is not.



   Example 1:

Input: s = "111000"
Output: 2
Explanation: Use the first operation two times to make s = "100011".
Then, use the second operation on the third and sixth elements to make s = "101010".

Example 2:

Input: s = "010"
Output: 0
Explanation: The string is already alternating.

Example 3:

Input: s = "1110"
Output: 1
Explanation: Use the second operation on the second element to make s = "1010".



Constraints:

1 <= s.length <= 105
s[i] is either '0' or '1'.

*/
#include"head.h"
class Solution {
	public:
		int minFlips(string s) {
			int n=s.size(),res=INT_MAX;
			string ss=s+s;

			vector<int> p1(2*n+1,0),p2(2*n+1,0); //p1 is 01010...,p2 is 1010...

			for(int i=1;i<=ss.size();i++)
			{
				if((i&1)==(int)(ss[i-1]-'0')) //odd is 1,even is 0
				{
					p1[i]=p1[i-1]+1;
					p2[i]=p2[i-1];
				}
				else //odd is 0,even is 1
				{
					p1[i]=p1[i-1];
					p2[i]=p2[i-1]+1;
				}
			}

			for(int i=n;i<=ss.size();i++)
				res=min(res,min(p1[i]-p1[i-n],p2[i]-p2[i-n]));
			return res;
		}
};
int main() 
{
	Solution s;
	cout<<s.minFlips("111000")<<endl;
	cout<<s.minFlips("010")<<endl;
	cout<<s.minFlips("1110")<<endl;
	return 0;
}
