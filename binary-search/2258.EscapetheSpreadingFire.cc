/*
   You are given a 0-indexed 2D integer array grid of size m x n which represents a field. Each cell has one of three values:

   0 represents grass,
   1 represents fire,
   2 represents a wall that you and fire cannot pass through.

   You are situated in the top-left cell, (0, 0), and you want to travel to the safehouse at the bottom-right cell, (m - 1, n - 1). Every minute, you may move to an adjacent grass cell. After your move, every fire cell will spread to all adjacent cells that are not walls.

   Return the maximum number of minutes that you can stay in your initial position before moving while still safely reaching the safehouse. If this is impossible, return -1. If you can always reach the safehouse regardless of the minutes stayed, return 109.

   Note that even if the fire spreads to the safehouse immediately after you have reached it, it will be counted as safely reaching the safehouse.

   A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).



   Example 1:

Input: grid = [[0,2,0,0,0,0,0],[0,0,0,2,2,1,0],[0,2,0,0,1,2,0],[0,0,2,2,2,0,2],[0,0,0,0,0,0,0]]
Output: 3
Explanation: The figure above shows the scenario where you stay in the initial position for 3 minutes.
You will still be able to safely reach the safehouse.
Staying for more than 3 minutes will not allow you to safely reach the safehouse.

Example 2:

Input: grid = [[0,0,0,0],[0,1,2,0],[0,2,0,0]]
Output: -1
Explanation: The figure above shows the scenario where you immediately move towards the safehouse.
Fire will spread to any cell you move towards and it is impossible to safely reach the safehouse.
Thus, -1 is returned.

Example 3:

Input: grid = [[0,0,0],[2,2,0],[1,2,0]]
Output: 1000000000
Explanation: The figure above shows the initial grid.
Notice that the fire is contained by walls and you will always be able to safely reach the safehouse.
Thus, 109 is returned.



Constraints:

m == grid.length
n == grid[i].length
2 <= m, n <= 300
4 <= m * n <= 2 * 104
grid[i][j] is either 0, 1, or 2.
grid[0][0] == grid[m - 1][n - 1] == 0

*/


#include"head.h"
class Solution {
    public:
        int maximumMinutes(vector<vector<int>>& grid) {
        const int r=grid.size(),c=grid[0].size();
        vector<vector<int>> fire(r,vector<int>(c,INT_MAX));
        vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<int,int>> q;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
            if(grid[i][j]==1)
            {
                q.push({i,j});
                fire[i][j]=0;
            }

        while(!q.empty())
        {
           pair<int,int> cur=q.front();q.pop();
           for(int i=0;i<4;i++)
           {
               int x=cur.first+dir[i][0],y=cur.second+dir[i][1];
               if(x<0||x>=r||y<0||y>=c||grid[x][y]==2)
                   continue;

               if(fire[x][y]>fire[cur.first][cur.second]+1)
               {
                   fire[x][y]=fire[cur.first][cur.second]+1;
                   q.push({x,y});
               }
           }
        }

        int l=0,ri=r*c;
        while(l<ri)
        {
            int mid=(l+ri+1)>>1;
            if(check(mid,grid,dir,fire)) l=mid;
            else
                ri=mid-1;
        }

        bool ok=check(l,grid,dir,fire);
        if(l==0&&!ok)
            return -1;

        if(l==r*c&&ok)
            return 1000000000;

        return l;
        }
        bool check(int time,const vector<vector<int>> &g,const vector<vector<int>> &d,const vector<vector<int>> &fire)
        {
            if(time>=fire[0][0])
                return false;

            vector<vector<int>> dis(g.size(),vector<int>(g[0].size(),INT_MAX));
            dis[0][0]=time;
            queue<pair<int,int>> q;q.push({0,0});

            while(!q.empty())
            {
                pair<int,int> cur=q.front();q.pop();

                for(int i=0;i<4;i++)
                {
                    int x=cur.first+d[i][0],y=cur.second+d[i][1];
                    if(x==g.size()-1&&y==g[0].size()-1)
                        return dis[cur.first][cur.second]+1<=fire[x][y];

                    if(x<0||x>=g.size()||y<0||y>=g[0].size()||g[x][y]==2)
                        continue;

                    if(dis[cur.first][cur.second]+1>=fire[x][y])
                        continue;

                    if(dis[x][y]>dis[cur.first][cur.second]+1)
                    {
                        dis[x][y]=dis[cur.first][cur.second]+1;
                        q.push({x,y});
                    }
                }
            }

            return false;
        }
};


int main() 
{
    Solution s;
    vector<vector<int>> v={{0,2,0,0,0,0,0},{0,0,0,2,2,1,0},{0,2,0,0,1,2,0},{0,0,2,2,2,0,2},{0,0,0,0,0,0,0}};
    cout<<s.maximumMinutes(v)<<endl;
    v.clear();v={{0,0,0,0},{0,1,2,0},{0,2,0,0}};
    cout<<s.maximumMinutes(v)<<endl;
    v.clear();v={{0,0,0},{2,2,0},{1,2,0}};
    cout<<s.maximumMinutes(v)<<endl;
    return 0;
}
