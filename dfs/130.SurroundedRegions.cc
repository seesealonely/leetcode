/*
   Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

   A region is captured by flipping all 'O's into 'X's in that surrounded region.



   Example 1:

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Notice that an 'O' should not be flipped if:
- It is on the border, or
- It is adjacent to an 'O' that should not be flipped.
The bottom 'O' is on the border, so it is not flipped.
The other three 'O' form a surrounded region, so they are flipped.

Example 2:

Input: board = [["X"]]
Output: [["X"]]



Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is 'X' or 'O'.

*/


#include"head.h"
class Solution {
    public:
        void solve(vector<vector<char>>& board) {
            if(board.empty()) return ;
            vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
            int r=board.size(),c=board[0].size();

            for(int i=0;i<r;i++)
            {
                if(board[i][0]=='O')
                    dfs(dir,board,i,0);
                if(board[i][c-1]=='O')
                    dfs(dir,board,i,c-1);
            }

            for(int i=0;i<c;i++)
            {
                if(board[0][i]=='O')
                    dfs(dir,board,0,i);
                if(board[r-1][i]=='O')
                    dfs(dir,board,r-1,i);
            }

            for(int i=0;i<r;i++)
                for(int j=0;j<c;j++)
                    if(board[i][j]=='O')
                        board[i][j]='X';
                    else if(board[i][j]=='E')
                        board[i][j]='O';
        }
        void dfs(vector<vector<int>> &d,vector<vector<char>> &b,int x,int y)
        {
            if(b[x][y]=='O')
                b[x][y]='E';
            for(int i=0;i<4;i++)
            {
                int xx=x+d[i][0],yy=y+d[i][1];
                if(xx>=0&&xx<b.size()&&yy>=0&&yy<b[0].size()&&b[xx][yy]=='O')
                    dfs(d,b,xx,yy);
            }
        }
};


int main() 
{
    Solution s;
    vector<vector<char>> v={{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    s.solve(v);
    show(v);

    cout<<"####################"<<endl;
    v.clear();v={{'X'}};
    s.solve(v);
    show(v);
    v.clear();v={{'O','O'},{'O','O'}};
    s.solve(v);
    show(v);
    return 0;
}
