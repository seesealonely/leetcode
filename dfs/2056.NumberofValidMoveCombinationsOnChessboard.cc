/*
   There is an 8 x 8 chessboard containing n pieces (rooks, queens, or bishops). You are given a string array pieces of length n, where pieces[i] describes the type (rook, queen, or bishop) of the ith piece. In addition, you are given a 2D integer array positions also of length n, where positions[i] = [ri, ci] indicates that the ith piece is currently at the 1-based coordinate (ri, ci) on the chessboard.

   When making a move for a piece, you choose a destination square that the piece will travel toward and stop on.

   A rook can only travel horizontally or vertically from (r, c) to the direction of (r+1, c), (r-1, c), (r, c+1), or (r, c-1).
   A queen can only travel horizontally, vertically, or diagonally from (r, c) to the direction of (r+1, c), (r-1, c), (r, c+1), (r, c-1), (r+1, c+1), (r+1, c-1), (r-1, c+1), (r-1, c-1).
   A bishop can only travel diagonally from (r, c) to the direction of (r+1, c+1), (r+1, c-1), (r-1, c+1), (r-1, c-1).

   You must make a move for every piece on the board simultaneously. A move combination consists of all the moves performed on all the given pieces. Every second, each piece will instantaneously travel one square towards their destination if they are not already at it. All pieces start traveling at the 0th second. A move combination is invalid if, at a given time, two or more pieces occupy the same square.

   Return the number of valid move combinations​​​​​.

Notes:

No two pieces will start in the same square.
You may choose the square a piece is already on as its destination.
If two pieces are directly adjacent to each other, it is valid for them to move past each other and swap positions in one second.



Example 1:

Input: pieces = ["rook"], positions = [[1,1]]
Output: 15
Explanation: The image above shows the possible squares the piece can move to.

Example 2:

Input: pieces = ["queen"], positions = [[1,1]]
Output: 22
Explanation: The image above shows the possible squares the piece can move to.

Example 3:

Input: pieces = ["bishop"], positions = [[4,3]]
Output: 12
Explanation: The image above shows the possible squares the piece can move to.



Constraints:

n == pieces.length
n == positions.length
1 <= n <= 4
pieces only contains the strings "rook", "queen", and "bishop".
There will be at most one queen on the chessboard.
1 <= xi, yi <= 8
Each positions[i] is distinct.

*/


#include"head.h"
class Solution {
	public:
		const int dx[8] = {1,-1,0,0,1,-1,-1,1};
		const int dy[8] = {0,0,1,-1,1,-1,1,-1};
		int res;
		vector<vector<int>> pos;
		pair<int,int> m[4];
		int countCombinations(vector<string>& pieces, vector<vector<int>>& positions) {
		for(int i=0;i<positions.size();i++)
			--positions[i][0],--positions[i][1];
		pos=positions;
		dfs(0,pieces);

		return res;
		}
		void dfs(int i,vector<string> &pieces)
		{
			if(i==pieces.size()){ res+=dfs1();return;}
			int mx,mn;
			if(pieces[i][0]=='r') mn=0,mx=3;
			if(pieces[i][0]=='q') mn=0,mx=7;
			if(pieces[i][0]=='b') mn=4,mx=7;

			for(int d=mn;d<=mx;d++)
				for(int l=1;l<=8;l++)
				if(pos[i][0]+l*dx[d]>=0&&pos[i][0]+l*dx[d]<8
					&&pos[i][1]+l*dy[d]>=0&&pos[i][1]+l*dy[d]<8)
				{
					m[i].first=d;m[i].second=l;
					dfs(i+1,pieces);
				}
			m[i].first=0;
			m[i].second=0;
			dfs(i+1,pieces);
		}
		int dfs1()
		{
			int board[8][8];
			memset(board,0,sizeof(board));

			pair<int,int> move[4];
			int curpos[4][2];
			for(int i=0;i<pos.size();i++)
				move[i]=m[i],curpos[i][0]=pos[i][0],curpos[i][1]=pos[i][1];

			while(true)
			{
				bool moved=false;
				for(int i=0;i<pos.size();i++)
					if(move[i].second>0)
					{
						moved=true;
						--move[i].second;
						curpos[i][0]+=dx[move[i].first];
						curpos[i][1]+=dy[move[i].first];
					}
				if(moved==false) return 1;

				for(int i=0;i<pos.size();i++)
					if(++board[curpos[i][0]][curpos[i][1]]>1) return 0;

				for(int i=0;i<pos.size();i++)
					board[curpos[i][0]][curpos[i][1]]=0;
			}
		}
};


int main() 
{
	Solution s;
	vector<string> pieces={"rook"};
	vector<vector<int>> positions={{1,1}};
	cout<<s.countCombinations(pieces,positions)<<endl;
	pieces.clear();pieces={"queen"};
	positions.clear();positions={{1,1}};
	cout<<s.countCombinations(pieces,positions)<<endl;
	pieces.clear();pieces={"bishop"};
	positions.clear();positions={{4,3}};
	cout<<s.countCombinations(pieces,positions)<<endl;
	return 0;
}
