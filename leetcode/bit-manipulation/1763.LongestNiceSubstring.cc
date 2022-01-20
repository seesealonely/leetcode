/*
   A string s is nice if, for every letter of the alphabet that s contains, it appears both in uppercase and lowercase. For example, "abABB" is nice because 'A' and 'a' appear, and 'B' and 'b' appear. However, "abA" is not because 'b' appears, but 'B' does not.

   Given a string s, return the longest substring of s that is nice. If there are multiple, return the substring of the earliest occurrence. If there are none, return an empty string.



   Example 1:

Input: s = "YazaAay"
Output: "aAa"
Explanation: "aAa" is a nice string because 'A/a' is the only letter of the alphabet in s, and both 'A' and 'a' appear.
"aAa" is the longest nice substring.

Example 2:

Input: s = "Bb"
Output: "Bb"
Explanation: "Bb" is a nice string because both 'B' and 'b' appear. The whole string is a substring.

Example 3:

Input: s = "c"
Output: ""
Explanation: There are no nice substrings.



Constraints:

1 <= s.length <= 100
s consists of uppercase and lowercase English letters.

*/
#include"head.h"
class Solution {
	public:
		string longestNiceSubstring(string s) {
			string res;
			for(int i=0;i<s.size();i++)
			{
				int l=0,u=0;
				for(int j=i;j<s.size();j++)
				{
					if(s[j]>='a'&&s[j]<='z') l|=(1<<(s[j]-'a'));
					else
						u|=(1<<(s[j]-'A'));
					if(l==u&&j-i+1>res.size())
						res=s.substr(i,j-i+1);
				}
			}
			return res;
		}
};
int main() 
{
	Solution s;
	cout<<s.longestNiceSubstring("YazaAay")<<endl;
	cout<<s.longestNiceSubstring("Bb")<<endl;
	cout<<s.longestNiceSubstring("c")<<endl;
	return 0;
}
