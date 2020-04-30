/*
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".

Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".

Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".

Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".

Note:

    1 <= S.length <= 200
    1 <= T.length <= 200
    S and T only contain lowercase letters and '#' characters.

Follow up:

    Can you solve it in O(N) time and O(1) space?


*/

#include"head.h"

class Solution {
public:
    bool backspaceCompare(string S, string T) {
	return erase(S)==erase(T);
    }
	stack<char> erase(string s)
	{
		stack<char> st;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='#'&&!st.empty())
			st.pop();
			else if(s[i]=='#'&&i==0);
			else if(s[i]!='#') st.push(s[i]);
		}
		return st;
	}
};
