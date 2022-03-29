/*
   Tic-tac-toe is played by two players A and B on a 3 x 3 grid. The rules of Tic-Tac-Toe are:

   Players take turns placing characters into empty squares ' '.
   The first player A always places 'X' characters, while the second player B always places 'O' characters.
   'X' and 'O' characters are always placed into empty squares, never on filled ones.
   The game ends when there are three of the same (non-empty) character filling any row, column, or diagonal.
   The game also ends if all squares are non-empty.
   No more moves can be played if the game is over.

   Given a 2D integer array moves where moves[i] = [rowi, coli] indicates that the ith move will be played on grid[rowi][coli]. return the winner of the game if it exists (A or B). In case the game ends in a draw return "Draw". If there are still movements to play return "Pending".

   You can assume that moves is valid (i.e., it follows the rules of Tic-Tac-Toe), the grid is initially empty, and A will play first.



   Example 1:

Input: moves = [[0,0],[2,0],[1,1],[2,1],[2,2]]
Output: "A"
Explanation: A wins, they always play first.

Example 2:

Input: moves = [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]
Output: "B"
Explanation: B wins.

Example 3:

Input: moves = [[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]
Output: "Draw"
Explanation: The game ends in a draw since there are no moves to make.



Constraints:

1 <= moves.length <= 9
moves[i].length == 2
0 <= rowi, coli <= 2
There are no repeated elements on moves.
moves follow the rules of tic tac toe.

*/

#define c11
#include"head.h"
class Solution {
    public:
        string tictactoe(vector<vector<int>>& moves) {
            #define m ((1<<0)+(1<<3)+(1<<6))
            unordered_map<int,int> h{{7,1},
                    {7<<3,1},
                    {7<<6,1},
                    {m,1},
                    {m<<1,1},
                    {m<<2,1},
                    {(1<<2)+(1<<4)+(1<<6),1},
                            {1+(1<<4)+(1<<8),1}};

                    int a=0,b=0;
                    for(int i=0;i<moves.size();i++)
                    {
                    if(i&1)
                    b^=1<<(3*moves[i][0]+moves[i][1]);
                    else
                    a^=1<<(3*moves[i][0]+moves[i][1]);
                    }

                    for(unordered_map<int,int>::iterator it=h.begin();it!=h.end();it++)
                    {
                    if((it->first&a)==it->first)
                        return "A";
                    if((it->first&b)==it->first)
                        return "B";
                    }
                    return moves.size()==9?"Draw":"Pending";
        }
};


int main() 
{
    Solution s;
    vector<vector<int> > v={{0,0},{2,0},{1,1},{2,1},{2,2}};
    cout<<s.tictactoe(v)<<endl;
    v.clear();v={{0,0},{1,1},{0,1},{0,2},{1,0},{2,0}};
    cout<<s.tictactoe(v)<<endl;
    v.clear();v={{0,0},{1,1},{2,0},{1,0},{1,2},{2,1},{0,1},{0,2},{2,2}};
    cout<<s.tictactoe(v)<<endl;
    return 0;
}
