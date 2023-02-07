/*
   You are given a 0-indexed m x n binary matrix grid. You can move from a cell (row, col) to any of the cells (row + 1, col) or (row, col + 1) that has the value 1. The matrix is disconnected if there is no path from (0, 0) to (m - 1, n - 1).

   You can flip the value of at most one (possibly none) cell. You cannot flip the cells (0, 0) and (m - 1, n - 1).

   Return true if it is possible to make the matrix disconnect or false otherwise.

   Note that flipping a cell changes its value from 0 to 1 or from 1 to 0.



   Example 1:

Input: grid = [[1,1,1],[1,0,0],[1,1,1]]
Output: true
Explanation: We can change the cell shown in the diagram above. There is no path from (0, 0) to (2, 2) in the resulting grid.

Example 2:

Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
Output: false
Explanation: It is not possible to change at most one cell such that there is not path from (0, 0) to (2, 2).



Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 1000
1 <= m * n <= 105
grid[i][j] is either 0 or 1.
grid[0][0] == grid[m - 1][n - 1] == 1

*/


#include"head.h"
class Solution {
    public:
        bool isPossibleToCutPath(vector<vector<int>>& grid) {
        const int r=grid.size(),c=grid[0].size();
        vector<vector<unsigned long long>> dpe(r,vector<unsigned long long>(c,0)),dps(r,vector<unsigned long long>(c,0));

        dpe[0][0]=1;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==0)
                    continue;

                if(i>0) dpe[i][j]+=dpe[i-1][j];
                if(j>0) dpe[i][j]+=dpe[i][j-1];
            }

        if(dpe[r-1][c-1]==0)
            return true;

        dps[r-1][c-1]=1;
        for(int i=r-1;i>=0;i--)
            for(int j=c-1;j>=0;j--)
            {
                if(grid[i][j]==0)
                    continue;

                if(i<r-1) dps[i][j]+=dps[i+1][j];
                if(j<c-1) dps[i][j]+=dps[i][j+1];
            }

        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
            {
                if(i==0&&j==0||i==r-1&&j==c-1)
                    continue;

                if(grid[i][j]==0)
                    continue;

                if(dpe[i][j]*dps[i][j]==dpe[r-1][c-1])
                    return true;
            }
        return false;
        }
};


int main() 
{
    Solution s;
    vector<vector<int>> v={{1,1,1},{1,0,0},{1,1,1}};
    cout<<s.isPossibleToCutPath(v)<<endl;
    v.clear();v={{1,1,1},{1,0,1},{1,1,1}};
    cout<<s.isPossibleToCutPath(v)<<endl;
    return 0;
}
