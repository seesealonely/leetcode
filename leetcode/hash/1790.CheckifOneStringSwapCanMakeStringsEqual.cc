/*
   You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.

   Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.



   Example 1:

Input: s1 = "bank", s2 = "kanb"
Output: true
Explanation: For example, swap the first character with the last character of s2 to make "bank".

Example 2:

Input: s1 = "attack", s2 = "defend"
Output: false
Explanation: It is impossible to make them equal with one string swap.

Example 3:

Input: s1 = "kelb", s2 = "kelb"
Output: true
Explanation: The two strings are already equal, so no string swap operation is required.



Constraints:

1 <= s1.length, s2.length <= 100
s1.length == s2.length
s1 and s2 consist of only lowercase English letters.

*/
#include"head.h"
class Solution {
	public:
		bool areAlmostEqual(string s1, string s2) {
		string sub1,sub2;
		for(int i=0;i<s1.size();i++)
		{
			if(s1[i]==s2[i])
				continue;
			sub1+=s1[i];
			sub2=s2[i]+sub2;
			if(sub1.size()>2)
				break;
		}
		return sub1==sub2||sub1.size()==2;
		}
};
int main() 
{
	Solution s;
	cout<<s.areAlmostEqual("bank","kanb")<<endl;
	cout<<s.areAlmostEqual("attack","defend")<<endl;
	cout<<s.areAlmostEqual("kelb","kelb")<<endl;
	cout<<s.areAlmostEqual("abcd","dcba")<<endl;
	return 0;
}
