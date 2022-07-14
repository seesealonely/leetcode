/*
   Given a string s, return true if it is possible to split the string s into three non-empty palindromic substrings. Otherwise, return false.​​​​​

   A string is said to be palindrome if it the same string when reversed.



   Example 1:

Input: s = "abcbdd"
Output: true
Explanation: "abcbdd" = "a" + "bcb" + "dd", and all three substrings are palindromes.

Example 2:

Input: s = "bcbddxy"
Output: false
Explanation: s cannot be split into 3 palindromes.



Constraints:

3 <= s.length <= 2000
s​​​​​​ consists only of lowercase English letters.


*/


#include"head.h"
class Solution {
    public:
        bool checkPartitioning(string s) {
        const int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));

        for(int len=0;len<n;len++)
            for(int i=0;i<n-len;i++)
            {
                int j=i+len;
                if(s[i]==s[j]&&(j-i<=1||dp[i+1][j-1]))
                    dp[i][j]=true;
            }

        for(int i=1;i<n;i++)
            for(int j=i+1;j<n;j++)
                if(dp[0][i-1]&&dp[i][j-1]&&dp[j][n-1])
                    return true;
        return false;
        }
};


int main() 
{
    Solution s;
    cout<<s.checkPartitioning("abcbdd")<<endl ;
    cout<<s.checkPartitioning("bcbddxy")<<endl;
    return 0;
}
