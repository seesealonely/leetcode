/*

   You are given a string s and a positive integer k.

   Select a set of non-overlapping substrings from the string s that satisfy the following conditions:

   The length of each substring is at least k.
   Each substring is a palindrome.

   Return the maximum number of substrings in an optimal selection.

   A substring is a contiguous sequence of characters within a string.

    

   Example 1:

Input: s = "abaccdbbd", k = 3
Output: 2
Explanation: We can select the substrings underlined in s = "abaccdbbd". Both "aba" and "dbbd" are palindromes and have a length of at least k = 3.
It can be shown that we cannot find a selection with more than two valid substrings.

Example 2:

Input: s = "adbcda", k = 2
Output: 0
Explanation: There is no palindrome substring of length at least 2 in the string.

 

Constraints:

1 <= k <= s.length <= 2000
s consists of lowercase English letters.

*/


#include"head.h"
class Solution {
    public:
        int maxPalindromes(string s, int k) {
        const int n=s.size();
        vector<vector<bool>> pa(n,vector<bool>(n,false));
        for(int i=n-1;i>=0;i--)
        {
            pa[i][i]=true;
            for(int j=i+1;j<n;j++)
                pa[i][j]=(s[i]==s[j]?(j-i>1?pa[i+1][j-1]:true):false);
        }

        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++)
        {
            dp[i]=dp[i-1];
            for(int j=i-k;j>=0;j--)
                if(pa[j][i-1])
                    dp[i]=max(dp[i],dp[j]+1);
        }

        return dp[n];
        }
};


int main() 
{
    Solution s;
    cout<<s.maxPalindromes("abaccdbbd",3)<<endl;
    cout<<s.maxPalindromes("adbcda",2)<<endl;
    return 0;
}
