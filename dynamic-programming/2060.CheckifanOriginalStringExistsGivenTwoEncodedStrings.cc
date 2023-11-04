/*
   An original string, consisting of lowercase English letters, can be encoded by the following steps:

   Arbitrarily split it into a sequence of some number of non-empty substrings.
   Arbitrarily choose some elements (possibly none) of the sequence, and replace each with its length (as a numeric string).
   Concatenate the sequence as the encoded string.

   For example, one way to encode an original string "abcdefghijklmnop" might be:

   Split it as a sequence: ["ab", "cdefghijklmn", "o", "p"].
   Choose the second and third elements to be replaced by their lengths, respectively. The sequence becomes ["ab", "12", "1", "p"].
   Concatenate the elements of the sequence to get the encoded string: "ab121p".

   Given two encoded strings s1 and s2, consisting of lowercase English letters and digits 1-9 (inclusive), return true if there exists an original string that could be encoded as both s1 and s2. Otherwise, return false.

Note: The test cases are generated such that the number of consecutive digits in s1 and s2 does not exceed 3.



Example 1:

Input: s1 = "internationalization", s2 = "i18n"
Output: true
Explanation: It is possible that "internationalization" was the original string.
- "internationalization"
-> Split: ["internationalization"]
-> Do not replace any element
-> Concatenate: "internationalization", which is s1.
- "internationalization"
-> Split: ["i", "nternationalizatio", "n"]
-> Replace: ["i", "18", "n"]
-> Concatenate: "i18n", which is s2

Example 2:

Input: s1 = "l123e", s2 = "44"
Output: true
Explanation: It is possible that "leetcode" was the original string.
- "leetcode"
-> Split: ["l", "e", "et", "cod", "e"]
-> Replace: ["l", "1", "2", "3", "e"]
-> Concatenate: "l123e", which is s1.
- "leetcode"
-> Split: ["leet", "code"]
-> Replace: ["4", "4"]
-> Concatenate: "44", which is s2.

Example 3:

Input: s1 = "a5b", s2 = "c5b"
Output: false
Explanation: It is impossible.
- The original string encoded as s1 must start with the letter 'a'.
- The original string encoded as s2 must start with the letter 'c'.



Constraints:

1 <= s1.length, s2.length <= 40
s1 and s2 consist of digits 1-9 (inclusive), and lowercase English letters only.
The number of consecutive digits in s1 and s2 does not exceed 3.

*/

#define c11
#include"head.h"
class Solution {
	public:
		bool possiblyEquals(string s1, string s2) {
		int n1=s1.size(),n2=s2.size();
		vector<vector<unordered_set<int>>> dp(n1+1,vector<unordered_set<int>>(n2+1));

		dp[0][0].emplace(0);
		for(int i=0;i<=n1;i++)
			for(int j=0;j<=n2;j++)
				for(unordered_set<int>::iterator it=dp[i][j].begin();it!=dp[i][j].end();it++)
				{
					int count=0;
					if(*it<=0)
						for(int ii=i;ii<min(i+3,n1);ii++)
						{
							if(isDigit(s1[ii]))
							{
								count=count*10+s1[ii]-'0';
								dp[ii+1][j].emplace(*it+count);
							}
							else
								break;
						}
					count=0;
					if(*it>=0)
						for(int jj=j;jj<min(j+3,n2);jj++)
						{
							if(isDigit(s2[jj]))
							{
								count=count*10+s2[jj]-'0';
								dp[i][jj+1].emplace(*it-count);
							}
							else
								break;
						}
					if(i<n1&&*it<0&&!isDigit(s1[i]))
						dp[i+1][j].emplace(*it+1);
					if(j<n2&&*it>0&&!isDigit(s2[j]))
						dp[i][j+1].emplace(*it-1);
					if(i<n1&&j<n2&&*it==0&&s1[i]==s2[j])
						dp[i+1][j+1].emplace(0);

				}
				return  dp[n1][n2].count(0);
		}
		bool isDigit(char c)
		{
			return c>='0'&&c<='9';
		}
};


int main() 
{
	Solution s;
	cout<<s.possiblyEquals( "internationalization",  "i18n")<<endl;
	cout<<s.possiblyEquals( "l123e",  "44")<<endl;
	cout<<s.possiblyEquals( "a5b",  "c5b")<<endl;
	return 0;
}
