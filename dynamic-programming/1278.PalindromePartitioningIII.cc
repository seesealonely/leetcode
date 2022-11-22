/*
   You are given a string s containing lowercase letters and an integer k. You need to :

   First, change some characters of s to other lowercase English letters.
   Then divide s into k non-empty disjoint substrings such that each substring is a palindrome.

   Return the minimal number of characters that you need to change to divide the string.



   Example 1:

Input: s = "abc", k = 2
Output: 1
Explanation: You can split the string into "ab" and "c", and change 1 character in "ab" to make it palindrome.

Example 2:

Input: s = "aabbc", k = 3
Output: 0
Explanation: You can split the string into "aa", "bb" and "c", all of them are palindrome.

Example 3:

Input: s = "leetcode", k = 8
Output: 0



Constraints:

1 <= k <= s.length <= 100.
s only contains lowercase English letters.

*/


#include"head.h"
class Solution {
    public:
        int palindromePartition(string s, int k) {
            const int n=s.size();
            vector<vector<int>> pa(n,vector<int>(n,0));
            for(int i=n-1;i>=0;i--)
                for(int j=i+1;j<n;j++)
                    pa[i][j]+=getpalindromeNum(s,i,j);

            vector<vector<int>> dp(n+1,vector<int>(k+1,1001));

//            for(int i=0;i<=k;i++)
            dp[0][0]=0;
            for(int i=1;i<=n;i++)
                for(int j=1;j<=min(n,k);j++)
                    for(int m=0;m<i;m++)
                        dp[i][j]=min(dp[i][j],dp[m][j-1]+pa[m][i-1]);

            return dp[n][k];
        }
        int  getpalindromeNum(string &s,int l,int r)
        {
            int sum=0;
            for(int i=l,j=r;i<j;i++,j--)
                if(s[i]!=s[j])
                    sum++;
            return sum;
        }
};


int main() 
{
    Solution s;
    cout<<s.palindromePartition("abc",2)<<endl;
    cout<<s.palindromePartition("aabbc",3)<<endl;
    cout<<s.palindromePartition("leetcode",8)<<endl;
    cout<<s.palindromePartition("aea",2)<<endl;
    return 0;
}
