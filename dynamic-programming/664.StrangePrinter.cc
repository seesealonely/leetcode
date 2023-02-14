/*
   There is a strange printer with the following two special properties:

   The printer can only print a sequence of the same character each time.
   At each turn, the printer can print new characters starting from and ending at any place and will cover the original existing characters.

   Given a string s, return the minimum number of turns the printer needed to print it.



   Example 1:

Input: s = "aaabbb"
Output: 2
Explanation: Print "aaa" first and then print "bbb".

Example 2:

Input: s = "aba"
Output: 2
Explanation: Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.



Constraints:

1 <= s.length <= 100
s consists of lowercase English letters.

*/


#include"head.h"
class Solution {
    public:
        int strangePrinter(string s) {
        if(s.empty()) return 0;
        const int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int len=1;len<=n;len++)
            for(int l=0;l+len-1<n;l++)
            {
                int r=l+len-1;
                dp[l][r]=dp[l+1][r]+1;

                for(int k=l+1;k<=r;k++)
                    if(s[l]==s[k])
                        dp[l][r]=min(dp[l][r],dp[l][k-1]+dp[k+1][r]);
                    else
                        dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]);
            }

            return dp[0][n-1];
        }
};


int main() 
{
    Solution s;
    cout<<s.strangePrinter("aaabbb")<<endl;
    cout<<s.strangePrinter("aba")<<endl;
    return 0;
}
