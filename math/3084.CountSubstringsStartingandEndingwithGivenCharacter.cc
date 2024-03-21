/*
   You are given a string s and a character c. Return the total number of
   substrings
   of s that start and end with c.



   Example 1:

Input: s = "abada", c = "a"

Output: 6

Explanation: Substrings starting and ending with "a" are: "abada", "abada", "abada", "abada", "abada", "abada".

Example 2:

Input: s = "zzz", c = "z"

Output: 6

Explanation: There are a total of 6 substrings in s and all start and end with "z".



Constraints:

1 <= s.length <= 105
s and c consist only of lowercase English letters.

*/


#include"head.h"
class Solution {
	public:
		long long countSubstrings(string s, char c) {
		typedef long long ll;
		int cnt=0,n=s.size();
		for(int i=0;i<n;i++)
			cnt+=s[i]==c;
		return (long long)(cnt+1)*cnt>>1;
		}
};


int main() 
{
	Solution s;
	cout<<s.countSubstrings("abada",'a')<<endl;
	cout<<s.countSubstrings("zzz",'z')<<endl;
	return 0;
}
