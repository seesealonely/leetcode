/*
   There is a 1-based binary matrix where 0 represents land and 1 represents water. You are given integers row and col representing the number of rows and columns in the matrix, respectively.

   Initially on day 0, the entire matrix is land. However, each day a new cell becomes flooded with water. You are given a 1-based 2D array cells, where cells[i] = [ri, ci] represents that on the ith day, the cell on the rith row and cith column (1-based coordinates) will be covered with water (i.e., changed to 1).

   You want to find the last day that it is possible to walk from the top to the bottom by only walking on land cells. You can start from any cell in the top row and end at any cell in the bottom row. You can only travel in the four cardinal directions (left, right, up, and down).

   Return the last day where it is possible to walk from the top to the bottom by only walking on land cells.



   Example 1:

Input: row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]
Output: 2
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 2.

Example 2:

Input: row = 2, col = 2, cells = [[1,1],[1,2],[2,1],[2,2]]
Output: 1
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 1.

Example 3:

Input: row = 3, col = 3, cells = [[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]]
Output: 3
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 3.



Constraints:

2 <= row, col <= 2 * 104
4 <= row * col <= 2 * 104
cells.length == row * col
1 <= ri <= row
1 <= ci <= col
All the values of cells are unique.

*/


#include"head.h"
class Solution {
    public:
        int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        int l=col-1,r=row*col;

        while(l<r)
        {
            int mid=(l+r+1)>>1;
            if(check(mid,row,col,cells,dir))
                l=mid;
            else
                r=mid-1;
        }
         
        return l;
        }
        bool check(int day,int r,int c,const vector<vector<int>> &cells,const vector<vector<int>> &dir)
        {
            vector<vector<bool>> vis(r,vector<bool>(c,false));
            for(int i=0;i<day;i++)
                vis[cells[i][0]-1][cells[i][1]-1]=true;

            queue<pair<int,int>> q;
            for(int i=0;i<c;i++)
                if(!vis[0][i])
                {
                   q.push({0,i});
                   vis[0][i]=true;
                }

            while(!q.empty())
            {
                pair<int,int> cur=q.front();q.pop();
                if(cur.first==r-1)
                    return true;

                for(int i=0;i<4;i++)
                {
                    int x=cur.first+dir[i][0],y=cur.second+dir[i][1];
                    
                    if(x<0||x>=r||y<0||y>=c||vis[x][y])
                        continue;

                    vis[x][y]=true;
                    q.push({x,y});
                }
            }

            return false;
        }
};


int main() 
{
    Solution s;
    vector<vector<int>> v={{1,1},{2,1},{1,2},{2,2}};
    cout<<s.latestDayToCross(2,2,v)<<endl;
    v.clear();v={{1,1},{1,2},{2,1},{2,2}};
    cout<<s.latestDayToCross(2,2,v)<<endl;
    v.clear();v={{1,2},{2,1},{3,3},{2,2},{1,1},{1,3},{2,3},{3,2},{3,1}};
    cout<<s.latestDayToCross(3,3,v)<<endl;
    return 0;
}
