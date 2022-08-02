/*
   A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:

   It is ().
   It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
   It can be written as (A), where A is a valid parentheses string.

   You are given an m x n matrix of parentheses grid. A valid parentheses string path in the grid is a path satisfying all of the following conditions:

   The path starts from the upper left cell (0, 0).
   The path ends at the bottom-right cell (m - 1, n - 1).
   The path only ever moves down or right.
   The resulting parentheses string formed by the path is valid.

   Return true if there exists a valid parentheses string path in the grid. Otherwise, return false.



   Example 1:

Input: grid = [["(","(","("],[")","(",")"],["(","(",")"],["(","(",")"]]
Output: true
Explanation: The above diagram shows two possible paths that form valid parentheses strings.
The first path shown results in the valid parentheses string "()(())".
The second path shown results in the valid parentheses string "((()))".
Note that there may be other valid parentheses string paths.

Example 2:

Input: grid = [[")",")"],["(","("]]
Output: false
Explanation: The two possible paths form the parentheses strings "))(" and ")((". Since neither of them are valid parentheses strings, we return false.



Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 100
grid[i][j] is either '(' or ')'.

*/


#include"head.h"
class Solution {
    public:
        bool hasValidPath(vector<vector<char>>& grid) {
        const int r=grid.size(),c=grid[0].size();
        vector<vector<vector<bool>>> vis(r,vector<vector<bool>>(c,vector<bool>((r+c+1)>>1,false)));

        if((r-1+c-1+1)%2||grid[0][0]==')'||grid[r-1][c-1]=='(')
            return false;

        return dfs(vis,grid,0,0,0);
        }
        bool dfs(vector<vector<vector<bool>>> &vis,vector<vector<char>> &grid,int x,int y,int c)
        {
            int ro=grid.size(),co=grid[0].size();
            if(x==ro-1&&y==co-1)
                return c==1;
            if(c>ro-x+co-y-1) return false;
            if(vis[x][y][c]) return false;
            vis[x][y][c]=true;

            c+=grid[x][y]=='('?1:-1;
            return c>=0&&(x<ro-1&&dfs(vis,grid,x+1,y,c)||y<co-1&&dfs(vis,grid,x,y+1,c));

        }
};


int main() 
{
    Solution s;
    vector<vector<char>> v={{'(','(','('},{')','(',')'},{'(','(',')'},{'(','(',')'}};
    cout<<s.hasValidPath(v)<<endl;
    v.clear();v={{')',')'},{'(','('}};
    cout<<s.hasValidPath(v)<<endl;
    return 0;
}
