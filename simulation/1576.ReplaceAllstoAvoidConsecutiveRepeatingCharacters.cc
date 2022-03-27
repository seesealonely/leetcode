/*
   Given a string s containing only lowercase English letters and the '?' character, convert all the '?' characters into lowercase letters such that the final string does not contain any consecutive repeating characters. You cannot modify the non '?' characters.

   It is guaranteed that there are no consecutive repeating characters in the given string except for '?'.

   Return the final string after all the conversions (possibly zero) have been made. If there is more than one solution, return any of them. It can be shown that an answer is always possible with the given constraints.



   Example 1:

Input: s = "?zs"
Output: "azs"
Explanation: There are 25 solutions for this problem. From "azs" to "yzs", all are valid. Only "z" is an invalid modification as the string will consist of consecutive repeating characters in "zzs".

Example 2:

Input: s = "ubv?w"
Output: "ubvaw"
Explanation: There are 24 solutions for this problem. Only "v" and "w" are invalid modifications as the strings will consist of consecutive repeating characters in "ubvvw" and "ubvww".



Constraints:

1 <= s.length <= 100
s consist of lowercase English letters and '?'.

*/


#include"head.h"
class Solution {
    public:
        string modifyString(string s) {
        
            for(int i=0;i<s.size();i++)
            {
                if(s[i]=='?')
                    s[i]=check(s,i);
            }

        return s;

        }
        char check(string &s,int pos)
        {
            const int n=s.size();
            for(char i='a';i<='z';i++)
            {
                if(pos>0&&i==s[pos-1])
                    continue;
                if(pos<n&&i==s[pos+1])
                    continue;
                return i;
            }
            return 'a';
        }
};


int main() 
{
    Solution s;
    cout<<s.modifyString("?zs")<<endl;
    cout<<s.modifyString("ubv?w")<<endl;
    return 0;
}