/*
   On an n x n chessboard, a knight starts at the cell (row, column) and attempts to make exactly k moves. The rows and columns are 0-indexed, so the top-left cell is (0, 0), and the bottom-right cell is (n - 1, n - 1).

   A chess knight has eight possible moves it can make, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.

   Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.

   The knight continues moving until it has made exactly k moves or has moved off the chessboard.

   Return the probability that the knight remains on the board after it has stopped moving.



   Example 1:

Input: n = 3, k = 2, row = 0, column = 0
Output: 0.06250
Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
From each of those positions, there are also two moves that will keep the knight on the board.
The total probability the knight stays on the board is 0.0625.

Example 2:

Input: n = 1, k = 0, row = 0, column = 0
Output: 1.00000



Constraints:

1 <= n <= 25
0 <= k <= 100
0 <= row, column <= n

*/


#include"head.h"
class Solution {
    public:
        double knightProbability(int n, int k, int row, int column) {
            vector<vector<vector<double>>> p(26,vector<vector<double>>(26,vector<double>(101,0.0)));
            vector<vector<int>> dir={{2,1},{1,2},{-2,1},{-1,2},{2,-1},{1,-2},{-2,-1},{-1,-2}};
            return dfs(n,k,row,column,p,dir);            
        }
        double dfs(int n,int k,int r,int c,vector<vector<vector<double>>> &p,vector<vector<int>> &dir)
        {
            if(r>=n||r<0||c>=n||c<0)
                return 0.0;

            if(p[r][c][k]!=0.0)
                return p[r][c][k];

            if(!k)
                return 1.0;
            
            double res=0.0;
            for(int i=0;i<8;i++)
            {
                int x=r+dir[i][0],y=c+dir[i][1];
                res+=0.125*dfs(n,k-1,x,y,p,dir);
            }
            return p[r][c][k]=res;
        }
};


int main() 
{
    Solution s;
    cout<<s.knightProbability(3,2,0,0)<<endl;
    cout<<s.knightProbability(1,0,0,0)<<endl;
    return 0;
}
