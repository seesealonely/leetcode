/*
   The chess knight has a unique movement, it may move two squares vertically and one square horizontally, or two squares horizontally and one square vertically (with both forming the shape of an L). The possible movements of chess knight are shown in this diagaram:

   A chess knight can move as indicated in the chess diagram below:

   We have a chess knight and a phone pad as shown below, the knight can only stand on a numeric cell (i.e. blue cell).

   Given an integer n, return how many distinct phone numbers of length n we can dial.

   You are allowed to place the knight on any numeric cell initially and then you should perform n - 1 jumps to dial a number of length n. All jumps should be valid knight jumps.

   As the answer may be very large, return the answer modulo 109 + 7.



   Example 1:

Input: n = 1
Output: 10
Explanation: We need to dial a number of length 1, so placing the knight over any numeric cell of the 10 cells is sufficient.

Example 2:

Input: n = 2
Output: 20
Explanation: All the valid number we can dial are [04, 06, 16, 18, 27, 29, 34, 38, 40, 43, 49, 60, 61, 67, 72, 76, 81, 83, 92, 94]

Example 3:

Input: n = 3131
Output: 136006598
Explanation: Please take care of the mod.



Constraints:

1 <= n <= 5000

*/


#include"head.h"
class Solution {
    public:
        int knightDialer(int n) {
        vector<vector<int>> a(10);
        a[0].push_back(4); a[0].push_back(6);
        a[1].push_back(6); a[1].push_back(8);
        a[2].push_back(7); a[2].push_back(9);
        a[3].push_back(4); a[3].push_back(8);
        a[4].push_back(3); a[4].push_back(9); a[4].push_back(0);
        a[6].push_back(1); a[6].push_back(7); a[6].push_back(0);
        a[7].push_back(2); a[7].push_back(6);
        a[8].push_back(1); a[8].push_back(3);
        a[9].push_back(2); a[9].push_back(4);

        vector<vector<int>> dp(n,vector<int>(10,0));
        int mod=1e9+7;

        for(int i=0;i<10;i++)
            dp[0][i]=1;

        for(int i=1;i<n;i++)
            for(int j=0;j<10;j++)
                for(int k=0;k<a[j].size();k++)
                    dp[i][j]=(dp[i][j]+dp[i-1][a[j][k]])%mod;

        int res=0;
        for(int i=0;i<10;i++)
            res=(res+dp[n-1][i])%mod;

        return res;
        }
};


int main() 
{
    Solution s;
    cout<<s.knightDialer(1)<<endl;
    cout<<s.knightDialer(2)<<endl;
    cout<<s.knightDialer(3131)<<endl;
    return 0;
}
