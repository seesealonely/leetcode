/*
   An alphabetical continuous string is a string consisting of consecutive letters in the alphabet. In other words, it is any substring of the string "abcdefghijklmnopqrstuvwxyz".

   For example, "abc" is an alphabetical continuous string, while "acb" and "za" are not.

   Given a string s consisting of lowercase letters only, return the length of the longest alphabetical continuous substring.

    

   Example 1:

Input: s = "abacaba"
Output: 2
Explanation: There are 4 distinct continuous substrings: "a", "b", "c" and "ab".
"ab" is the longest continuous substring.

Example 2:

Input: s = "abcde"
Output: 5
Explanation: "abcde" is the longest continuous substring.

 

Constraints:

1 <= s.length <= 105
s consists of only English lowercase letters.

*/


#include"head.h"
class Solution {
    public:
        int longestContinuousSubstring(string s) {
        int res=0,n=s.size();
        for(int l=0,r=0;l<n;)
        {
            r=l+1;
            while(s[r]==s[r-1]+1)
                r++;
            res=max(res,r-l);
            l=r;
        }
        return res;
        }
};


int main() 
{
    Solution s;
    cout<<s.longestContinuousSubstring("abacaba")<<endl;
    cout<<s.longestContinuousSubstring("abcde")<<endl;
    return 0;
}
