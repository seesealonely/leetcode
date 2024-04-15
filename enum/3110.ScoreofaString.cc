/*
   You are given a string s. The score of a string is defined as the sum of the absolute difference between the ASCII values of adjacent characters.

   Return the score of s.



   Example 1:

Input: s = "hello"

Output: 13

Explanation:

The ASCII values of the characters in s are: 'h' = 104, 'e' = 101, 'l' = 108, 'o' = 111. So, the score of s would be |104 - 101| + |101 - 108| + |108 - 108| + |108 - 111| = 3 + 7 + 0 + 3 = 13.

Example 2:

Input: s = "zaz"

Output: 50

Explanation:

The ASCII values of the characters in s are: 'z' = 122, 'a' = 97. So, the score of s would be |122 - 97| + |97 - 122| = 25 + 25 = 50.



Constraints:

2 <= s.length <= 100
s consists only of lowercase English letters.

*/


#include"head.h"
class Solution {
	public:
		int scoreOfString(string s) {
		int res=0,n=s.size();
		for(int i=1;i<n;i++)
			res+=abs(s[i]-s[i-1]);
		return res;
		}
};


int main() 
{
	Solution s;
	cout<<s.scoreOfString("hello")<<endl;
	cout<<s.scoreOfString("zaz")<<endl;
	return 0;
}
