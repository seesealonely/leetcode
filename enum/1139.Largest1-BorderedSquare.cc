/*
   Given a 2D grid of 0s and 1s, return the number of elements in the largest square subgrid that has all 1s on its border, or 0 if such a subgrid doesn't exist in the grid.



   Example 1:

Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
Output: 9

Example 2:

Input: grid = [[1,1,0,0]]
Output: 1



Constraints:

1 <= grid.length <= 100
1 <= grid[0].length <= 100
grid[i][j] is 0 or 1
*/


#include"head.h"
class Solution {
    public:
        int largest1BorderedSquare(vector<vector<int>>& grid) {
        const int r=grid.size(),c=grid[0].size();

        vector<vector<int>> sumr(r+1,vector<int>(c+1,0));
        vector<vector<int>> sumc(c+1,vector<int>(r+1,0));

        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                sumr[i+1][j+1]=sumr[i+1][j]+grid[i][j];

        for(int i=0;i<c;i++)
            for(int j=0;j<r;j++)
                sumc[i+1][j+1]=sumc[i+1][j]+grid[j][i];

        for(int len=min(r,c);len>0;len--)
            for(int i=0;i<=r-len;i++)
                for(int j=0;j<=c-len;j++)
                {
                    int x=i+len-1,y=j+len-1;

                    if(sumr[i+1][y+1]-sumr[i+1][j]==len&&sumr[x+1][y+1]-sumr[x+1][j]==len&&
                        sumc[j+1][x+1]-sumc[j+1][i]==len&&sumc[y+1][x+1]-sumc[y+1][i]==len)
                        return len*len;
                }
        return 0;
        }
};


int main() 
{
    Solution s;
    vector<vector<int>> v={{1,1,1},{1,0,1},{1,1,1}};
    cout<<s.largest1BorderedSquare(v)<<endl;
    v.clear();v={{1,1,0,0}};
    cout<<s.largest1BorderedSquare(v)<<endl;
    return 0;
}
