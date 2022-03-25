/*
   You are given an n x n grid where we place some 1 x 1 x 1 cubes that are axis-aligned with the x, y, and z axes.

   Each value v = grid[i][j] represents a tower of v cubes placed on top of the cell (i, j).

   We view the projection of these cubes onto the xy, yz, and zx planes.

   A projection is like a shadow, that maps our 3-dimensional figure to a 2-dimensional plane. We are viewing the "shadow" when looking at the cubes from the top, the front, and the side.

   Return the total area of all three projections.



   Example 1:

Input: grid = [[1,2],[3,4]]
Output: 17
Explanation: Here are the three projections ("shadows") of the shape made with each axis-aligned plane.

Example 2:

Input: grid = [[2]]
Output: 5

Example 3:

Input: grid = [[1,0],[0,2]]
Output: 8



Constraints:

n == grid.length == grid[i].length
1 <= n <= 50
0 <= grid[i][j] <= 50

*/


#include"head.h"
class Solution {
    public:
        int projectionArea(vector<vector<int>>& grid) {
            const int r=grid.size(),c=grid[0].size();
            int zero=0,res=0;
            vector<int> row(r,0),col(c,0);
            for(int i=0;i<r;i++)
                for(int j=0;j<c;j++)
                {
                    row[i]=max(row[i],grid[i][j]);
                    col[j]=max(col[j],grid[i][j]);
                    zero+=grid[i][j]>0?0:1;
                }

            for(int i=0;i<r;i++)
                res+=row[i];
            for(int i=0;i<c;i++)
                res+=col[i];
            return res+r*c-zero;
        }
        int projectionArea1(vector<vector<int>>& grid) {
            int res=0,x=0,y=0;
            for(int i=0;i<grid.size();i++)
            {
                x=0,y=0;
                for(int j=0;j<grid[0].size();j++)
                {
                    x=max(x,grid[i][j]);
                    y=max(y,grid[j][i]);
                    if(grid[i][j]) ++res;
                }
                res+=x+y;
            }
            return res;
        }
};


int main() 
{
    Solution s;
    vector<vector<int> > v={{1,2},{3,4}};
    cout<<s.projectionArea(v)<<endl;
    v.clear();v={{2}};
    cout<<s.projectionArea(v)<<endl;
    v.clear();v={{1,0},{0,2}};
    cout<<s.projectionArea(v)<<endl;
    v={{1,2},{3,4}};
    cout<<s.projectionArea1(v)<<endl;
    v.clear();v={{2}};
    cout<<s.projectionArea1(v)<<endl;
    v.clear();v={{1,0},{0,2}};
    cout<<s.projectionArea1(v)<<endl;
    return 0;
}
