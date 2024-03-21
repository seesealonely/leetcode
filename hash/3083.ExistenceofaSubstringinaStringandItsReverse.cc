/*
   Given a string s, find any
   substring
   of length 2 which is also present in the reverse of s.

   Return true if such a substring exists, and false otherwise.



   Example 1:

Input: s = "leetcode"

Output: true

Explanation: Substring "ee" is of length 2 which is also present in reverse(s) == "edocteel".

Example 2:

Input: s = "abcba"

Output: true

Explanation: All of the substrings of length 2 "ab", "bc", "cb", "ba" are also present in reverse(s) == "abcba".

Example 3:

Input: s = "abcd"

Output: false

Explanation: There is no substring of length 2 in s, which is also present in the reverse of s.



Constraints:

1 <= s.length <= 100
s consists only of lowercase English letters.

*/

#define c11
#include"head.h"
class Solution {
	public:
		bool isSubstringPresent(string s) {
		unordered_set<int> h;
		for(int i=0;i<s.size()-1;i++)
		{
			int key=26*(s[i]-'a')+s[i+1]-'a';
			h.insert(key);
		}

		for(int i=s.size()-1;i>=1;i--)
		{
			int key=26*(s[i]-'a')+s[i-1]-'a';
			if(h.find(key)!=h.end())
				return true;
		}
		return false;
		}
};


int main() 
{
	Solution s;
	cout<<s.isSubstringPresent("leetcode")<<endl;
	cout<<s.isSubstringPresent("abcba")<<endl;
	cout<<s.isSubstringPresent("abcd")<<endl;
	return 0;
}
