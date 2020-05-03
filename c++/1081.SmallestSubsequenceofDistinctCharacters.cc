/*
Return the lexicographically smallest subsequence of text that contains all the distinct characters of text exactly once.

 

Example 1:

Input: "cdadabcc"
Output: "adbc"

Example 2:

Input: "abcd"
Output: "abcd"

Example 3:

Input: "ecbacba"
Output: "eacb"

Example 4:

Input: "leetcode"
Output: "letcod"

 

Note:

    1 <= text.length <= 1000
    text consists of lowercase English letters.

*/

#include"1081.SmallestSubsequenceofDistinctCharacters.h"

int main()
{
	Solution s;
	cout<<s.smallestSubsequence("cdadabcc")<<endl;
	cout<<s.smallestSubsequence("abcd")<<endl;
	cout<<s.smallestSubsequence("ecbacba")<<endl;
	cout<<s.smallestSubsequence("leetcode")<<endl;
	return 0;
}
