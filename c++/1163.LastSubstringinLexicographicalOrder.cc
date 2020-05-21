/*
Given a string s, return the last substring of s in lexicographical order.



Example 1:

Input: "abab"
Output: "bab"
Explanation: The substrings are ["a", "ab", "aba", "abab", "b", "ba", "bab"]. The lexicographically maximum substring is "bab".

Example 2:

Input: "leetcode"
Output: "tcode"



Note:

1 <= s.length <= 4 
s contains only lowercase English letters.

*/
#include"1163.LastSubstringinLexicographicalOrder.h"
int main() 
 {
 	 Solution s;
 	 cout<<s.lastSubstring("abab")<<endl;
 	 cout<<s.lastSubstring("leetcode")<<endl;
 	 return 0;
 }
