/*
   Given a string s, return the number of homogenous substrings of s. Since the answer may be too large, return it modulo 109 + 7.

   A string is homogenous if all the characters of the string are the same.

   A substring is a contiguous sequence of characters within a string.



   Example 1:

Input: s = "abbcccaa"
Output: 13
Explanation: The homogenous substrings are listed as below:
"a" appears 3 times.
"aa" appears 1 time.
"b" appears 2 times.
"bb" appears 1 time.
"c" appears 3 times.
"cc" appears 2 times.
"ccc" appears 1 time.
3 + 1 + 2 + 1 + 3 + 2 + 1 = 13.

Example 2:

Input: s = "xy"
Output: 2
Explanation: The homogenous substrings are "x" and "y".

Example 3:

Input: s = "zzzzz"
Output: 15



Constraints:

1 <= s.length <= 105
s consists of lowercase letters.
*/
#include"head.h"
class Solution {
	public:
		int countHomogenous(string s) {
		int count=0,prechar=0,res=0,mod=(int)1e9+7;
		for(int i=0;i<s.size();i++)
		{
			count=s[i]==prechar?count+1:1;
			prechar=s[i];
			res=(res+count)%mod;
		}
		return res;
		}
};
