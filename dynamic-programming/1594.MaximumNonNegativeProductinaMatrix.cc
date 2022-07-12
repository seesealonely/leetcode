/*
   You are given a m x n matrix grid. Initially, you are located at the top-left corner (0, 0), and in each step, you can only move right or down in the matrix.

   Among all possible paths starting from the top-left corner (0, 0) and ending in the bottom-right corner (m - 1, n - 1), find the path with the maximum non-negative product. The product of a path is the product of all integers in the grid cells visited along the path.

   Return the maximum non-negative product modulo 109 + 7. If the maximum product is negative, return -1.

   Notice that the modulo is performed after getting the maximum product.



   Example 1:

Input: grid = [[-1,-2,-3],[-2,-3,-3],[-3,-3,-2]]
Output: -1
Explanation: It is not possible to get non-negative product in the path from (0, 0) to (2, 2), so return -1.

Example 2:

Input: grid = [[1,-2,1],[1,-2,1],[3,-4,1]]
Output: 8
Explanation: Maximum non-negative product is shown (1 * 1 * -2 * -4 * 1 = 8).

Example 3:

Input: grid = [[1,3],[0,-4]]
Output: 0
Explanation: Maximum non-negative product is shown (1 * 0 * -4 = 0).



Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 15
-4 <= grid[i][j] <= 4


*/


#include"head.h"
class Solution {
    public:
        int maxProductPath(vector<vector<int>>& grid) {
        #define ll long long 
       const int mod=1e9+7,r=grid.size(),c=grid[0].size();
        vector<vector<ll>> mx(r,vector<ll>(c,0)),mn(r,vector<ll>(c,0));

        mx[0][0]=mn[0][0]=grid[0][0];
        for(int i=1;i<=r;i++)
            mx[i][0]=mn[i][0]=grid[i-1][0];
        for(int i=1;i<=c;i++)
            mx[0][i]=mn[0][i]=grid[0][i-1];
        }
};


int main() 
{
    Solution s;
//    s.maxProductPath();
    return 0;
}
