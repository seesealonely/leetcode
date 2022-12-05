/*
   Given a string s, return the number of different non-empty palindromic subsequences in s. Since the answer may be very large, return it modulo 109 + 7.

   A subsequence of a string is obtained by deleting zero or more characters from the string.

   A sequence is palindromic if it is equal to the sequence reversed.

   Two sequences a1, a2, ... and b1, b2, ... are different if there is some i for which ai != bi.

    

   Example 1:

Input: s = "bccb"
Output: 6
Explanation: The 6 different non-empty palindromic subsequences are 'b', 'c', 'bb', 'cc', 'bcb', 'bccb'.
Note that 'bcb' is counted only once, even though it occurs twice.

Example 2:

Input: s = "abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba"
Output: 104860361
Explanation: There are 3104860382 different non-empty palindromic subsequences, which is 104860361 modulo 109 + 7.

 

Constraints:

1 <= s.length <= 1000
s[i] is either 'a', 'b', 'c', or 'd'.

*/


#include"head.h"
class Solution {
    public:
        int countPalindromicSubsequences(string s) {
            const int n=s.size(),mod=1e9+7;
            vector<vector<int>> dp(n,vector<int>(n,0));
            for(int i=0;i<n;i++)
                dp[i][i]=1;

            for(int step=1;step<=n;step++)
            {
                for(int i=0;i<n-step;i++)
                {
                    const int j=i+step;
                    if(s[i]==s[j])
                    {
                        dp[i][j]=dp[i+1][j-1]*2;
                        int l=i+1,r=j-1;
                        while(l<=r&&s[l]!=s[i]) l++;
                        while(r<=r&&s[r]!=s[i]) r--;

                        if(l==r)
                            dp[i][j]+=1;
                        else if(l>r)
                            dp[i][j]+=2;
                        else
                            dp[i][j]-=dp[l+1][r-1];
                    }
                    else
                        dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];
                    dp[i][j]=dp[i][j]%mod;
                }
            }

            return dp[0][n-1];
        }
};


int main() 
{
    Solution s;
    cout<<s.countPalindromicSubsequences("bccb")<<endl;
    cout<<s.countPalindromicSubsequences("abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba")<<endl;
    return 0;
}
