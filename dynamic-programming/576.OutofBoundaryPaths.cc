/*
   There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.

   Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.



   Example 1:

Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
Output: 6

Example 2:

Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
Output: 12



Constraints:

1 <= m, n <= 50
0 <= maxMove <= 50
0 <= startRow < m
0 <= startColumn < n

*/


#include"head.h"
class Solution {
    public:
        int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        const int mod=1e9+7;
        vector<vector<vector<int>>> dp(maxMove+1,vector<vector<int>>(m,vector<int>(n,0)));
        vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
        for(int k=1;k<=maxMove;k++)
            for(int i=0;i<m;i++)
                for(int j=0;j<n;j++)
                for(int d=0;d<4;d++)
                {
                    int x=i+dir[d][0],y=j+dir[d][1];
                    if(x>=m||x<0||y>=n||y<0)
                        dp[k][i][j]++;
                    else
                    dp[k][i][j]=(dp[k][i][j]+dp[k-1][x][y])%mod;
                }
        return dp[maxMove][startRow][startColumn];
        }
};


int main() 
{
    Solution s;
    cout<<s.findPaths(2,2,2,0,0)<<endl;
    cout<<s.findPaths(1,3,3,0,1)<<endl;
    return 0;
}
