/*
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

Example 1:

Input:s1 = "ab" s2 = "eidbaooo"
Output:True
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False

Note:

    The input strings only contain lower case letters.
    The length of both given strings is in range [1, 10,000].
*/

#include"head.h"

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
	if(s1.size()>s2.size()) return false;
	vector<int>map1(26,0),map2(26,0);        
	for(int i=0;i<s1.size();i++)
	{
		map1[s1[i]-'a']++;
		map2[s2[i]-'a']++;
	}
		if(map1==map2) return true;
	for(int i=0;i<s2.size()-s1.size();i++)
	{
		map2[s2[i]-'a']--;
		map2[s2[i+s1.size()]-'a']++;
		if(map1==map2) return true;
	}
		return false;
    }
};
