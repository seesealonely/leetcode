/*
   You are given an n x n grid where you have placed some 1 x 1 x 1 cubes. Each value v = grid[i][j] represents a tower of v cubes placed on top of cell (i, j).

   After placing these cubes, you have decided to glue any directly adjacent cubes to each other, forming several irregular 3D shapes.

   Return the total surface area of the resulting shapes.

Note: The bottom face of each shape counts toward its surface area.



Example 1:

Input: grid = [[1,2],[3,4]]
Output: 34

Example 2:

Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
Output: 32

Example 3:

Input: grid = [[2,2,2],[2,1,2],[2,2,2]]
Output: 46



Constraints:

n == grid.length == grid[i].length
1 <= n <= 50
0 <= grid[i][j] <= 50

*/


#include"head.h"
class Solution {
    public:
        int surfaceArea(vector<vector<int>>& grid) {
            int res=0;
            for(int i=0;i<grid.size();i++)
                for(int j=0;j<grid[0].size();j++)
                {
                    int high=grid[i][j];
                    if(high>0)
                    {
                        res+=(high<<2)+2;
                        res-=i>0?min(high,grid[i-1][j])<<1:0;
                        res-=j>0?min(high,grid[i][j-1])<<1:0;
                    }
                }
            return res;
        }
};


int main() 
{
    Solution s;
    vector<vector<int>> v={{1,2},{3,4}};
    cout<<s.surfaceArea(v)<<endl;
    v.clear();v={{1,1,1},{1,0,1},{1,1,1}};
    cout<<s.surfaceArea(v)<<endl;
    v.clear();v={{2,2,2},{2,1,2},{2,2,2}};
    cout<<s.surfaceArea(v)<<endl;
    return 0;
}
