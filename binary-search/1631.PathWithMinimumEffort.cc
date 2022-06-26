/*
   You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

   A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

   Return the minimum effort required to travel from the top-left cell to the bottom-right cell.



   Example 1:

Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.

Example 2:

Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].

Example 3:

Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.



Constraints:

rows == heights.length
columns == heights[i].length
1 <= rows, columns <= 100
1 <= heights[i][j] <= 106
*/


#include"head.h"
class Solution {
    public:
        int minimumEffortPath(vector<vector<int>>& heights) {
            int l=0,r=1e6;
            while(l<r)
            {
                int m=(l+r)>>1;
                if(check(m,heights))
                    r=m;
                else
                    l=m+1;                    
            }
            return l;
        }
        int check(int m,vector<vector<int>> &h)
        {
            const int r=h.size(),c=h[0].size();
            vector<vector<bool>> vis(r,vector<bool>(c,false)); vis[0][0]=true;
            queue<pair<int,int>> q;q.push({0,0});
            vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};

            while(!q.empty())
            {
                int x=q.front().first,y=q.front().second; q.pop();
                for(int i=0;i<4;i++)
                {
                    int xx=x+dir[i][0],yy=y+dir[i][1];
                    if(xx>=r||xx<0||yy>=c||yy<0)
                        continue;

                    if(abs(h[x][y]-h[xx][yy])>m)
                        continue;

                    if(vis[xx][yy]==false)
                    {
                    vis[xx][yy]=true;
                    q.push({xx,yy});
                    }
                }
            }
            return vis[r-1][c-1];
        }
};


int main() 
{
    Solution s;
    vector<vector<int>> v={{1,2,2},{3,8,2},{5,3,5}};
    cout<<s.minimumEffortPath(v)<<endl;
    v.clear();v={{1,2,3},{3,8,4},{5,3,5}};
    cout<<s.minimumEffortPath(v)<<endl;
    v.clear();v={{1,2,1,1,1},{1,2,1,2,1},{1,2,1,2,1},{1,2,1,2,1},{1,1,1,2,1}};
    cout<<s.minimumEffortPath(v)<<endl;
    return 0;
}
