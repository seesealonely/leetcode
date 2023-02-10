/*
   Given an n x n integer matrix grid, return the minimum sum of a falling path with non-zero shifts.

   A falling path with non-zero shifts is a choice of exactly one element from each row of grid such that no two elements chosen in adjacent rows are in the same column.



   Example 1:

Input: arr = [[1,2,3],[4,5,6],[7,8,9]]
Output: 13
Explanation:
The possible falling paths are:
[1,5,9], [1,5,7], [1,6,7], [1,6,8],
[2,4,8], [2,4,9], [2,6,7], [2,6,8],
[3,4,8], [3,4,9], [3,5,7], [3,5,9]
The falling path with the smallest sum is [1,5,7], so the answer is 13.

Example 2:

Input: grid = [[7]]
Output: 7



Constraints:

n == grid.length == grid[i].length
1 <= n <= 200
-99 <= grid[i][j] <= 99

*/


#include"head.h"
class Solution {
    public:
        int minFallingPathSum(vector<vector<int>>& grid) {
            const int r=grid.size(),c=grid[0].size();
            vector<int> pre(grid[0].begin(),grid[0].end());
            for(int i=1;i<r;i++)
            {
                vector<int> cur(c,INT_MAX);
                for(int j=0;j<c;j++)
                    for(int k=0;k<c;k++)
                        if(j!=k)
                            cur[j]=min(cur[j],pre[k]+grid[i][j]);
                pre=cur;
            }


            return *min_element(pre.begin(),pre.end());
        }
};


int main() 
{
    Solution s;
    vector<vector<int>> v={{1,2,3},{4,5,6},{7,8,9}};
    cout<<s.minFallingPathSum(v)<<endl; 
    return 0;
}
