/*
   Given a string s containing only digits, return the
   lexicographically smallest string
   that can be obtained after swapping adjacent digits in s with the same parity at most once.

   Digits have the same parity if both are odd or both are even. For example, 5 and 9, as well as 2 and 4, have the same parity, while 6 and 9 do not.



   Example 1:

Input: s = "45320"

Output: "43520"

Explanation:

s[1] == '5' and s[2] == '3' both have the same parity, and swapping them results in the lexicographically smallest string.

Example 2:

Input: s = "001"

Output: "001"

Explanation:

There is no need to perform a swap because s is already the lexicographically smallest.



Constraints:

2 <= s.length <= 100
s consists only of digits.

*/


#include"head.h"
class Solution {
	public:
		string getSmallestString(string s) {
		const int n=s.size();
		for(int i=0;i<n-1;i++)
		{
			int x=s[i],y=s[i+1];
			if(x>y&&x%2==y%2)
			{
				swap(s[i],s[i+1]);
				break;
			}
		}
		return s;
		}
};


int main() 
{
	Solution s;
	cout<<s.getSmallestString("45320")<<endl;
	cout<<s.getSmallestString("001")<<endl;
	return 0;
}
