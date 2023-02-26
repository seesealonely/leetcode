/*
   You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle). You can move up, down, left, or right from and to an empty cell in one step.

   Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1) given that you can eliminate at most k obstacles. If it is not possible to find such walk return -1.



   Example 1:

Input: grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], k = 1
Output: 6
Explanation: 
The shortest path without eliminating any obstacle is 10.
The shortest path with one obstacle elimination at position (3,2) is 6. Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).

Example 2:

Input: grid = [[0,1,1],[1,1,1],[1,0,0]], k = 1
Output: -1
Explanation: We need to eliminate at least two obstacles to find such a walk.



Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 40
1 <= k <= m * n
grid[i][j] is either 0 or 1.
grid[0][0] == grid[m - 1][n - 1] == 0

*/


#include"head.h"
class Solution {
    public:
        int shortestPath(vector<vector<int>>& grid, int k) {
        vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        int r=grid.size(),c=grid[0].size();
        const int MX=r*c+1;
        struct node{
            int x,y,b;
            node (int xx,int yy,int bb):x(xx),y(yy),b(bb){};
        };

        vector<vector<vector<int>>> dis(r,vector<vector<int>>(c,vector<int>(r*c+1,MX)));

        queue<node> q;
        q.push(node(0,0,0));

        dis[0][0][0]=0;

        while(!q.empty())
        {
            node a=q.front();q.pop();
            if(a.x==r-1&&a.y==c-1)
                return dis[a.x][a.y][a.b];

            for(int i=0;i<4;i++)
            {
                int x=a.x+dir[i][0],y=a.y+dir[i][1];
                if(x<0||y<0||x>=r||y>=c)
                    continue;

                if(grid[x][y]==1)
                {
                    if(a.b<k&&dis[x][y][a.b+1]>dis[a.x][a.y][a.b]+1)
                    {
                        dis[x][y][a.b+1]=dis[a.x][a.y][a.b]+1;
                        q.push(node(x,y,a.b+1));
                    }
                }
                else
                {
                    if(dis[x][y][a.b]>dis[a.x][a.y][a.b]+1)
                    {
                        dis[x][y][a.b]=dis[a.x][a.y][a.b]+1;
                        q.push(node(x,y,a.b));
                    }
                }
            }
        }

        return -1;

        }
};


int main() 
{
    Solution s;
    vector<vector<int>> v={{0,0,0},{1,1,0},{0,0,0},{0,1,1},{0,0,0}};
    cout<<s.shortestPath(v,1)<<endl;
    v.clear();v={{0,1,1},{1,1,1},{1,0,1}};
    cout<<s.shortestPath(v,1)<<endl;
    return 0;
}
