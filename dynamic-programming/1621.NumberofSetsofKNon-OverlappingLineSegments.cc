/*
   Given n points on a 1-D plane, where the ith point (from 0 to n-1) is at x = i, find the number of ways we can draw exactly k non-overlapping line segments such that each segment covers two or more points. The endpoints of each segment must have integral coordinates. The k line segments do not have to cover all n points, and they are allowed to share endpoints.

   Return the number of ways we can draw k non-overlapping line segments. Since this number can be huge, return it modulo 109 + 7.



   Example 1:

Input: n = 4, k = 2
Output: 5
Explanation: The two line segments are shown in red and blue.
The image above shows the 5 different ways {(0,2),(2,3)}, {(0,1),(1,3)}, {(0,1),(2,3)}, {(1,2),(2,3)}, {(0,1),(1,2)}.

Example 2:

Input: n = 3, k = 1
Output: 3
Explanation: The 3 ways are {(0,1)}, {(0,2)}, {(1,2)}.

Example 3:

Input: n = 30, k = 7
Output: 796297179
Explanation: The total number of possible ways to draw 7 line segments is 3796297200. Taking this number modulo 109 + 7 gives us 796297179.



Constraints:

2 <= n <= 1000
1 <= k <= n-1

*/

//dp[0][0][0]=1 
//dp[i][k][0]=dp[i-1][k][0]+dp[i-1][k][1]  0 is not contained current i
//dp[i][k][1]=dp[i-1][k][1] 1 is contained current i
//dp[i][k][1]+=dp[i-1][k-1][0]+dp[i-1][k-1][1] 1 is contained current i
//res=dp[n][k][0]+dp[n][k][1]
#include"head.h"
class Solution {
    public:
        int dp[1000][1001][2];
        int numberOfSets(int n, int k) {
        //vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(2,0)));
        const int mod=1e9+7;
        #define ll (long long int)
        
        dp[0][0][0]=1;
        for(int i=1;i<n;i++)
            for(int j=0;j<=k;j++)
            {
                    dp[i][j][0]=(ll dp[i-1][j][0]+dp[i-1][j][1])%mod;
                    dp[i][j][1]=dp[i-1][j][1];
                    if(j>0)
                    dp[i][j][1]=(ll dp[i][j][1]+dp[i-1][j-1][0]+dp[i-1][j-1][1])%mod;
            }
        return (ll dp[n-1][k][0]+dp[n-1][k][1])%mod;
        }
};


int main() 
{
    Solution s;
    cout<<s.numberOfSets(4,2)<<endl;
    cout<<s.numberOfSets(3,1)<<endl;
    cout<<s.numberOfSets(30,7)<<endl;
    return 0;
}
