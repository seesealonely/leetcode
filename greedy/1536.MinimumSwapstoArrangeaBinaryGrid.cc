/*
   Given an n x n binary grid, in one step you can choose two adjacent rows of the grid and swap them.

   A grid is said to be valid if all the cells above the main diagonal are zeros.

   Return the minimum number of steps needed to make the grid valid, or -1 if the grid cannot be valid.

   The main diagonal of a grid is the diagonal that starts at cell (1, 1) and ends at cell (n, n).



   Example 1:

Input: grid = [[0,0,1],[1,1,0],[1,0,0]]
Output: 3

Example 2:

Input: grid = [[0,1,1,0],[0,1,1,0],[0,1,1,0],[0,1,1,0]]
Output: -1
Explanation: All rows are similar, swaps have no effect on the grid.

Example 3:

Input: grid = [[1,0,0],[1,1,0],[1,1,1]]
Output: 0



Constraints:

n == grid.length == grid[i].length
1 <= n <= 200
grid[i][j] is either 0 or 1

*/


#include"head.h"
class Solution {
    public:
        int minSwaps(vector<vector<int>>& grid) {
        const int n=grid.size();
        vector<int> idx1(n,0); //record first one from tail
        for(int i=0;i<grid.size();i++)
            for(int j=n-1;j>=0;j--)
                if(grid[i][j])
                {
                    idx1[i]=j;
                    break;
                }

        int res=0;
        for(int i=0;i<n;i++)
        {
            if(idx1[i]<=i)
                continue;

            int j=i;
            for(;j<n;j++)
            {
                if(idx1[j]<=i)
                    break;
            }
            if(j==n) return -1;
            for(int k=j;k>i;k--)
                swap(idx1[k],idx1[k-1]);
            res+=j-i;
        }
        return res;
        }
};


int main() 
{
    Solution s;
    vector<vector<int> > v={{0,0,1},{1,1,0},{1,0,0}};
    cout<<s.minSwaps(v)<<endl;
    v.clear();v={{0,1,1,0},{0,1,1,0},{0,1,1,0},{0,1,1,0}};
    cout<<s.minSwaps(v)<<endl;
    v.clear();v={{1,0,0},{1,1,0},{1,1,1}};
    cout<<s.minSwaps(v)<<endl;
    return 0;
}
