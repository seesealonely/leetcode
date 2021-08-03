/*
   Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.

   A string is represented by an array if the array elements concatenated in order forms the string.



   Example 1:

Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
Output: true
Explanation:
word1 represents string "ab" + "c" -> "abc"
word2 represents string "a" + "bc" -> "abc"
The strings are the same, so return true.

Example 2:

Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
Output: false

Example 3:

Input: word1 = ["abc", "d", "defg"], word2 = ["abcddefg"]
Output: true



Constraints:

1 <= word1.length, word2.length <= 103
1 <= word1[i].length, word2[i].length <= 103
1 <= sum(word1[i].length), sum(word2[i].length) <= 103
word1[i] and word2[i] consist of lowercase letters.

*/
#include"head.h"
class Solution {
	public:
		bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
			int w1=0,w2=0,c1=0,c2=0;
			while(w1<word1.size()&&w2<word2.size())
			{
				if(word1[w1][c1++]!=word2[w2][c2++])
					return false;
				c1%=word1[w1].size();
				c2%=word2[w2].size();
				if(!c1) w1++;
				if(!c2) w2++;
			}
			return w1==word1.size()&&w2==word2.size();
		}
};
