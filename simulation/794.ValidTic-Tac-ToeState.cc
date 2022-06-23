/*
   Given a Tic-Tac-Toe board as a string array board, return true if and only if it is possible to reach this board position during the course of a valid tic-tac-toe game.

   The board is a 3 x 3 array that consists of characters ' ', 'X', and 'O'. The ' ' character represents an empty square.

   Here are the rules of Tic-Tac-Toe:

   Players take turns placing characters into empty squares ' '.
   The first player always places 'X' characters, while the second player always places 'O' characters.
   'X' and 'O' characters are always placed into empty squares, never filled ones.
   The game ends when there are three of the same (non-empty) character filling any row, column, or diagonal.
   The game also ends if all squares are non-empty.
   No more moves can be played if the game is over.



   Example 1:

Input: board = ["O "," "," "]
Output: false
Explanation: The first player always plays "X".

Example 2:

Input: board = ["XOX"," X "," "]
Output: false
Explanation: Players take turns making moves.

Example 3:

Input: board = ["XOX","O O","XOX"]
Output: true



Constraints:

board.length == 3
board[i].length == 3
board[i][j] is either 'X', 'O', or ' '.

*/


#include"head.h"
class Solution {
    public:
        bool validTicTacToe(vector<string>& board) {
        int o=cnt(board,'O'),x=cnt(board,'X');
        if(x<o||x>o+1) return false;

        bool wino=false,winx=false;

        for(int i=0;i<3;i++)
        {
            if(board[i]=="OOO") wino=true;
            if(board[i]=="XXX") winx=true;
            if(board[0][i]=='O'&&board[1][i]=='O'&&board[2][i]=='O')  wino=true;
            if(board[0][i]=='X'&&board[1][i]=='X'&&board[2][i]=='X')  winx=true;
        }
        
        if(board[0][0]=='X'&&board[1][1]=='X'&&board[2][2]=='X') winx=true;
        if(board[0][0]=='O'&&board[1][1]=='O'&&board[2][2]=='O') wino=true;
        if(board[2][0]=='X'&&board[1][1]=='X'&&board[0][2]=='X') winx=true;
        if(board[2][0]=='O'&&board[1][1]=='O'&&board[0][2]=='O') wino=true;

        if(wino&&winx) return false;
        if(winx&&x==o) return false;
        if(wino&&x>o) return false;

        return true;
        }
        int cnt(vector<string>&b,char c)
        {
            int res=0;
            for(int i=0;i<3;i++)
                for(int j=0;j<3;j++)
                    res+=b[i][j]==c;

            return res;
        }
};


int main() 
{
    Solution s;
    vector<string> v={"O  ","   ","   "};
    cout<<s.validTicTacToe(v)<<endl;
    v.clear();v={"XOX"," X ","   "};
    cout<<s.validTicTacToe(v)<<endl;
    v.clear();v={"XOX","O O","XOX"};
    cout<<s.validTicTacToe(v)<<endl;
    return 0;
}
