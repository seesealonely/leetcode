/*
   A wonderful string is a string where at most one letter appears an odd number of times.

   For example, "ccjjc" and "abab" are wonderful, but "ab" is not.

   Given a string word that consists of the first ten lowercase English letters ('a' through 'j'), return the number of wonderful non-empty substrings in word. If the same substring appears multiple times in word, then count each occurrence separately.

   A substring is a contiguous sequence of characters in a string.



   Example 1:

Input: word = "aba"
Output: 4
Explanation: The four wonderful substrings are underlined below:
- "aba" -> "a"
- "aba" -> "b"
- "aba" -> "a"
- "aba" -> "aba"

Example 2:

Input: word = "aabb"
Output: 9
Explanation: The nine wonderful substrings are underlined below:
- "aabb" -> "a"
- "aabb" -> "aa"
- "aabb" -> "aab"
- "aabb" -> "aabb"
- "aabb" -> "a"
- "aabb" -> "abb"
- "aabb" -> "b"
- "aabb" -> "bb"
- "aabb" -> "b"

Example 3:

Input: word = "he"
Output: 2
Explanation: The two wonderful substrings are underlined below:
- "he" -> "h"
- "he" -> "e"



Constraints:

1 <= word.length <= 105
word consists of lowercase English letters from 'a' to 'j'.
*/
#include"head.h"
class Solution {
	public:
		long long wonderfulSubstrings(string word) {
		const int n=word.size();
		vector<int> count(1<<10,0);

		count[0]=1;
		int state=0;long long res=0;
		for(int i=0;i<n;i++)
		{
			state^=1<<(word[i]-'a');
			res+=count[state];
			for(int j=0;j<10;j++)
				res+=count[state^(1<<j)];
			count[state]++;
		}
		return res;
		}
};
int main() 
{
	Solution s;
	cout<<s.wonderfulSubstrings("aba")<<endl;
	cout<<s.wonderfulSubstrings("aabb")<<endl;
	cout<<s.wonderfulSubstrings("he")<<endl;
	return 0;
}
