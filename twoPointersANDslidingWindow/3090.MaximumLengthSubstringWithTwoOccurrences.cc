/*
   Given a string s, return the maximum length of a
   substring
   such that it contains at most two occurrences of each character.



   Example 1:

Input: s = "bcbbbcba"

Output: 4

Explanation:
The following substring has a length of 4 and contains at most two occurrences of each character: "bcbbbcba".

Example 2:

Input: s = "aaaa"

Output: 2

Explanation:
The following substring has a length of 2 and contains at most two occurrences of each character: "aaaa".



Constraints:

2 <= s.length <= 100
s consists only of lowercase English letters.
*/


#include"head.h"
class Solution {
	public:
		int maximumLengthSubstring(string s) {
		const int n=s.size();
		vector<int> cnt(26,0);
		int res=0;
		for(int l=0,r=0;r<n;r++)
		{
			int x=s[r]-'a';
			++cnt[x];	
			while(cnt[x]>2)
				--cnt[s[l++]-'a'];

			res=max(res,r-l+1);
		}
		return res;
		}
};


int main() 
{
	Solution s;
	cout<<s.maximumLengthSubstring("bcbbbcba")<<endl;
	cout<<s.maximumLengthSubstring("aaaa")<<endl;
	return 0;
}
