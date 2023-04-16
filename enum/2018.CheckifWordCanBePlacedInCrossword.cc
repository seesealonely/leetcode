/*
   You are given an m x n matrix board, representing the current state of a crossword puzzle. The crossword contains lowercase English letters (from solved words), ' ' to represent any empty cells, and '#' to represent any blocked cells.

   A word can be placed horizontally (left to right or right to left) or vertically (top to bottom or bottom to top) in the board if:

   It does not occupy a cell containing the character '#'.
   The cell each letter is placed in must either be ' ' (empty) or match the letter already on the board.
   There must not be any empty cells ' ' or other lowercase letters directly left or right of the word if the word was placed horizontally.
   There must not be any empty cells ' ' or other lowercase letters directly above or below the word if the word was placed vertically.

   Given a string word, return true if word can be placed in board, or false otherwise.



   Example 1:

Input: board = [["#", " ", "#"], [" ", " ", "#"], ["#", "c", " "]], word = "abc"
Output: true
Explanation: The word "abc" can be placed as shown above (top to bottom).

Example 2:

Input: board = [[" ", "#", "a"], [" ", "#", "c"], [" ", "#", "a"]], word = "ac"
Output: false
Explanation: It is impossible to place the word because there will always be a space/letter above or below it.

Example 3:

Input: board = [["#", " ", "#"], [" ", " ", "#"], ["#", " ", "c"]], word = "ca"
Output: true
Explanation: The word "ca" can be placed as shown above (right to left). 



Constraints:

m == board.length
n == board[i].length
1 <= m * n <= 2 * 105
board[i][j] will be ' ', '#', or a lowercase English letter.
1 <= word.length <= max(m, n)
word will contain only lowercase English letters.

*/


#include"head.h"
class Solution {
	public:
		bool placeWordInCrossword(vector<vector<char>>& board, string word) {
			const int r=board.size(),c=board[0].size(),wl=word.size();
			for(int i=0;i<r;i++)
				for(int j=0;j<c;j++)
				{
					if(board[i][j]=='#') continue;

					int start=j;
					bool success1=true,success2=true;

					for(;j<c&&board[i][j]!='#';j++)
					{
						if(j-start>=wl||(board[i][j]!=' '&&board[i][j]!=word[j-start]))
							success1=false;

						if(j-start>=wl||(board[i][j]!=' '&&board[i][j]!=word[wl-1-(j-start)]))
							success2=false;
					}
					if((success1||success2)&&j-start==wl)
						return true;
				}
			for(int j=0;j<c;j++)
				for(int i=0;i<r;i++)
				{
					if(board[i][j]=='#') continue;

					int i0=i;
					bool success1=true,success2=true;
					for(;i<r&&board[i][j]!='#';i++)
					{
						if(i-i0>=wl||(board[i][j]!=' '&&board[i][j]!=word[i-i0]))
							success1=false;
						if(i-i0>=wl||(board[i][j]!=' '&&board[i][j]!=word[wl-1-(i-i0)]))
							success2=false;
					}
					if((success1||success2)&&i-i0==wl)
						return true;
				}
			return false;
		}
};


int main() 
{
	Solution s;
	vector<vector<char>> v={{'#', ' ', '#'}, {' ', ' ', '#'}, {'#', 'c', ' '}};
	cout<<s.placeWordInCrossword(v,"abc")<<endl;
	v.clear();v={{' ', '#', 'a'}, {' ', '#', 'c'}, {' ', '#', 'a'}};
	cout<<s.placeWordInCrossword(v,"ac")<<endl;
	v.clear();v={{'#', ' ', '#'}, {' ', ' ', '#'}, {'#', ' ', 'c'}};
	cout<<s.placeWordInCrossword(v,"ca")<<endl;
	return 0;
}
