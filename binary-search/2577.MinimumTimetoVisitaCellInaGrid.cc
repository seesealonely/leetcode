/*
   You are given a m x n matrix grid consisting of non-negative integers where grid[row][col] represents the minimum time required to be able to visit the cell (row, col), which means you can visit the cell (row, col) only when the time you visit it is greater than or equal to grid[row][col].

   You are standing in the top-left cell of the matrix in the 0th second, and you must move to any adjacent cell in the four directions: up, down, left, and right. Each move you make takes 1 second.

   Return the minimum time required in which you can visit the bottom-right cell of the matrix. If you cannot visit the bottom-right cell, then return -1.



   Example 1:

Input: grid = [[0,1,3,2],[5,1,2,5],[4,3,8,6]]
Output: 7
Explanation: One of the paths that we can take is the following:
- at t = 0, we are on the cell (0,0).
- at t = 1, we move to the cell (0,1). It is possible because grid[0][1] <= 1.
- at t = 2, we move to the cell (1,1). It is possible because grid[1][1] <= 2.
- at t = 3, we move to the cell (1,2). It is possible because grid[1][2] <= 3.
- at t = 4, we move to the cell (1,1). It is possible because grid[1][1] <= 4.
- at t = 5, we move to the cell (1,2). It is possible because grid[1][2] <= 5.
- at t = 6, we move to the cell (1,3). It is possible because grid[1][3] <= 6.
- at t = 7, we move to the cell (2,3). It is possible because grid[1][3] <= 7.
The final time is 7. It can be shown that it is the minimum time possible.

Example 2:

Input: grid = [[0,2,4],[3,2,1],[1,0,4]]
Output: -1
Explanation: There is no path from the top left to the bottom-right cell.



Constraints:

m == grid.length
n == grid[i].length
2 <= m, n <= 1000
4 <= m * n <= 105
0 <= grid[i][j] <= 105
grid[0][0] == 0
*/


#include"head.h"
class Solution {
    public:
        int minimumTime(vector<vector<int>>& grid) {
        if(grid[0][1]>1&&grid[1][0]>1)
            return -1;

        int l=0,r=50000;
        while(l<r)
        {
            int m=(l+r)>>1;
            if(binary(grid,2*m)==-1)
                l=m+1;
            else
                r=m;
        }

        return binary(grid,2*l);
        }
        int binary(vector<vector<int>> &g,int m)
        {
            vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
            const int r=g.size(),c=g[0].size();
            vector<vector<int>> d(r,vector<int>(c,INT_MAX));
            queue<pair<int,int>> q;
            q.push({0,0});
            d[0][0]=m;

            while(!q.empty())
            {
                pair<int,int> u=q.front();q.pop();

                if(u.first==r-1&&u.second==c-1)
                    return d[u.first][u.second];

                for(int i=0;i<4;i++)
                {
                    int x=u.first+dir[i][0],y=u.second+dir[i][1];
                    if(x<0||y<0||x>=r||y>=c)
                        continue;

                    if(g[x][y]>d[u.first][u.second]+1)
                        continue;

                    if(d[x][y]>d[u.first][u.second]+1)
                    {
                        d[x][y]=d[u.first][u.second]+1;
                        q.push({x,y});
                    }
                }
            }

            return -1;
        }
};


int main() 
{
    Solution s;
    vector<vector<int>> v={{0,1,3,2},{5,1,2,5},{4,3,8,6}};
    cout<<s.minimumTime(v)<<endl;
    v.clear();v={{0,2,4},{3,2,1},{1,0,4}};
    cout<<s.minimumTime(v)<<endl;
    return 0;
}
