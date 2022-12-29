/*
   You are given an n x n grid representing a field of cherries, each cell is one of three possible integers.

   0 means the cell is empty, so you can pass through,
   1 means the cell contains a cherry that you can pick up and pass through, or
   -1 means the cell contains a thorn that blocks your way.

   Return the maximum number of cherries you can collect by following the rules below:

   Starting at the position (0, 0) and reaching (n - 1, n - 1) by moving right or down through valid path cells (cells with value 0 or 1).
   After reaching (n - 1, n - 1), returning to (0, 0) by moving left or up through valid path cells.
   When passing through a path cell containing a cherry, you pick it up, and the cell becomes an empty cell 0.
   If there is no valid path between (0, 0) and (n - 1, n - 1), then no cherries can be collected.

    

   Example 1:

Input: grid = [[0,1,-1],[1,0,-1],[1,1,1]]
Output: 5
Explanation: The player started at (0, 0) and went down, down, right right to reach (2, 2).
4 cherries were picked up during this single trip, and the matrix becomes [[0,1,-1],[0,0,-1],[0,0,0]].
Then, the player went left, up, up, left to return home, picking up one more cherry.
The total number of cherries picked up is 5, and this is the maximum possible.

Example 2:

Input: grid = [[1,1,-1],[1,-1,1],[-1,1,1]]
Output: 0

 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 50
grid[i][j] is -1, 0, or 1.
grid[0][0] != -1
grid[n - 1][n - 1] != -1

*/


#include"head.h"
class Solution {
    public:
        int cherryPickup(vector<vector<int>>& grid) {
        const int n=grid.size();
        vector<vector<vector<int>>> dp(2*n-1,vector<vector<int>>(n,vector<int>(n,INT_MIN)));
        dp[0][0][0]=grid[0][0];

        for(int s=1;s<2*n-1;s++)
            for(int x1=0;x1<n;x1++)
                for(int x2=0;x2<n;x2++)
                {
                    int y1=s-x1,y2=s-x2;
                    if(y1<0||y1>=n||y2<0||y2>=n)
                        continue;

                    if(grid[x1][y1]==-1||grid[x2][y2]==-1)
                         continue;
                    int v=grid[x1][y1]+grid[x2][y2];
                    if(x1==x2&&v>0)
                        v--;

                    dp[s][x1][x2]=dp[s-1][x1][x2]+v;

                    if(x1>0)
                        dp[s][x1][x2]=max(dp[s][x1][x2],dp[s-1][x1-1][x2]+v);
                    if(x2>0)
                        dp[s][x1][x2]=max(dp[s][x1][x2],dp[s-1][x1][x2-1]+v);

                    if(x1>0&&x2>0)
                        dp[s][x1][x2]=max(dp[s][x1][x2],dp[s-1][x1-1][x2-1]+v);
                }
        return max(0,dp[2*n-2][n-1][n-1]);
        }
};


int main() 
{
    Solution s;
    vector<vector<int>> v={{0, 1, -1},
 {1, 0, -1},
 {1, 1,  1}};
    cout<<s.cherryPickup(v)<<endl;
    return 0;
}
