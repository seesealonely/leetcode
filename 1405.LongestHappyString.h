/*
A string is called happy if it does not have any of the strings 'aaa', 'bbb' or 'ccc' as a substring.

Given three integers a, b and c, return any string s, which satisfies following conditions:

    s is happy and longest possible.
    s contains at most a occurrences of the letter 'a', at most b occurrences of the letter 'b' and at most c occurrences of the letter 'c'.
    s will only contain 'a', 'b' and 'c' letters.

If there is no such string s return the empty string "".

 

Example 1:

Input: a = 1, b = 1, c = 7
Output: "ccaccbcc"
Explanation: "ccbccacc" would also be a correct answer.

Example 2:

Input: a = 2, b = 2, c = 1
Output: "aabbc"

Example 3:

Input: a = 7, b = 1, c = 0
Output: "aabaa"
Explanation: It's the only correct answer in this case.

 

Constraints:

    0 <= a, b, c <= 100
    a + b + c > 0
*/
#include"head.h"

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
	int A=0,B=0,C=0;
	string res;
	while(true)
	{
		if(a>0&&((a>=b&&a>=c&&A<2)||B==2||C==2))
		{
			res+='a';
			a--;
			A++;
			B=0;
			C=0;
		}
		else if(b>0&&((b>=a&&b>=c&&B<2)||A==2||C==2))
		{
			res+='b';
			b--;
			B++;
			A=0;
			C=0;
		}
		else if(c>0&&((c>=a&&c>=b&&C<2)||A==2||B==2))
		{
			res+='c';
			c--;
			C++;
			A=0;
			B=0;
		}
		else
			return res;
	}        
    }
};
