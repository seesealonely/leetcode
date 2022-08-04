/*
   You are given a 0-indexed binary string floor, which represents the colors of tiles on a floor:

   floor[i] = '0' denotes that the ith tile of the floor is colored black.
   On the other hand, floor[i] = '1' denotes that the ith tile of the floor is colored white.

   You are also given numCarpets and carpetLen. You have numCarpets black carpets, each of length carpetLen tiles. Cover the tiles with the given carpets such that the number of white tiles still visible is minimum. Carpets may overlap one another.

   Return the minimum number of white tiles still visible.



   Example 1:

Input: floor = "10110101", numCarpets = 2, carpetLen = 2
Output: 2
Explanation:
The figure above shows one way of covering the tiles with the carpets such that only 2 white tiles are visible.
No other way of covering the tiles with the carpets can leave less than 2 white tiles visible.

Example 2:

Input: floor = "11111", numCarpets = 2, carpetLen = 3
Output: 0
Explanation:
The figure above shows one way of covering the tiles with the carpets such that no white tiles are visible.
Note that the carpets are able to overlap one another.



Constraints:

1 <= carpetLen <= floor.length <= 1000
floor[i] is either '0' or '1'.
1 <= numCarpets <= 1000

*/


#include"head.h"
class Solution {
    public:
        int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        return dp1(floor,numCarpets,carpetLen);
        }
        int dp0(string f,int num,int len)
        {
            const int n=f.size();
            vector<vector<int>> dp(num+1,vector<int>(n+1,0));

            for(int i=1;i<=n;i++)
                dp[0][i]=dp[0][i-1]+(f[i-1]=='1');

            for(int i=1;i<=num;i++)
                for(int j=1;j<=n;j++)
                    dp[i][j]=min(dp[i][j-1]+(f[j-1]=='1'),dp[i-1][max(0,j-len)]);

            return dp[num][n];
        }

        int dp1(string f,int num,int len)
        {
            const int n=f.size();
            vector<vector<int>> dp(2,vector<int>(n+1,0));

            for(int i=1;i<=n;i++)
                dp[0][i]=dp[0][i-1]+(f[i-1]=='1');

            for(int i=1;i<=num;i++)
                for(int j=1;j<=n;j++)
                    dp[i&1][j]=min(dp[i&1][j-1]+(f[j-1]=='1'),dp[(i-1)&1][max(0,j-len)]);

            return dp[num&1][n];
        }
};


int main() 
{
    Solution s;
    cout<<s.minimumWhiteTiles("10110101",2,2)<<endl;
    cout<<s.minimumWhiteTiles("11111",2,3)<<endl;
    return 0;
}
