/*
   Given a 0-indexed n x n integer matrix grid, return the number of pairs (Ri, Cj) such that row Ri and column Cj are equal.

   A row and column pair is considered equal if they contain the same elements in the same order (i.e. an equal array).



   Example 1:

Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
Output: 1
Explanation: There is 1 equal row and column pair:
- (Row 2, Column 1): [2,7,7]

Example 2:

Input: grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
Output: 3
Explanation: There are 3 equal row and column pairs:
- (Row 0, Column 0): [3,1,2,2]
- (Row 2, Column 2): [2,4,2,2]
- (Row 3, Column 2): [2,4,2,2]



Constraints:

n == grid.length == grid[i].length
1 <= n <= 200
1 <= grid[i][j] <= 105

*/


#include"head.h"
class Solution {
    public:
        int equalPairs(vector<vector<int>>& grid) {
        const int n=grid.size();

        int res=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                bool ok=true;
                for(int k=0;k<n;k++)
                    if(grid[k][j]!=grid[i][k])
                    {
                        ok=false;
                    }

                if(ok)
                    res++;
            }

        return res;
        }
};


int main() 
{
    Solution s;
    vector<vector<int>> v={{3,2,1},{1,7,6},{2,7,7}};
    cout<<s.equalPairs(v)<<endl;
    v.clear();v={{3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2}};
    cout<<s.equalPairs(v)<<endl;
    return 0;
}
