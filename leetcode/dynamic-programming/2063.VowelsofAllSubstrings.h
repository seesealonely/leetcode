/*
   Given a string word, return the sum of the number of vowels ('a', 'e', 'i', 'o', and 'u') in every substring of word.

   A substring is a contiguous (non-empty) sequence of characters within a string.

Note: Due to the large constraints, the answer may not fit in a signed 32-bit integer. Please be careful during the calculations.



Example 1:

Input: word = "aba"
Output: 6
Explanation:
All possible substrings are: "a", "ab", "aba", "b", "ba", and "a".
- "b" has 0 vowels in it
- "a", "ab", "ba", and "a" have 1 vowel each
- "aba" has 2 vowels in it
Hence, the total sum of vowels = 0 + 1 + 1 + 1 + 1 + 2 = 6.

Example 2:

Input: word = "abc"
Output: 3
Explanation:
All possible substrings are: "a", "ab", "abc", "b", "bc", and "c".
- "a", "ab", and "abc" have 1 vowel each
- "b", "bc", and "c" have 0 vowels each
Hence, the total sum of vowels = 1 + 1 + 1 + 0 + 0 + 0 = 3.

Example 3:

Input: word = "ltcd"
Output: 0
Explanation: There are no vowels in any substring of "ltcd".

Example 4:

Input: word = "noosabasboosa"
Output: 237
Explanation: There are a total of 237 vowels in all the substrings.



Constraints:

1 <= word.length <= 105
word consists of lowercase English letters.

*/
#include"head.h"
class Solution {
	public:
		long long countVowels(string word) {
			int n=word.size();
			vector<long long> dp(n+1,0);
			for(int i=1;i<=n;i++)
			{
				dp[i]=dp[i-1];
				if(string("aeiou").find(word[i-1])!=string::npos)
					dp[i]+=i;
			}
			return accumulate(dp.begin(),dp.end(),0LL);
		}
};
