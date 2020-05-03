/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

    Each of the digits 1-9 must occur exactly once in each row.
    Each of the digits 1-9 must occur exactly once in each column.
    Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.

Empty cells are indicated by the character '.'.


A sudoku puzzle...


...and its solution numbers marked in red.

Note:

    The given board contain only digits 1-9 and the character '.'.
    You may assume that the given Sudoku puzzle will have a single unique solution.
    The given board size is always 9x9.
*/

#include"37.SudokuSolver.h"

int main()
{
	Solution s;
	vector<vector<char> > v(9,vector<char> (9,'.'));
	v[0][0]='5';v[0][1]='3';v[0][4]='7';
	v[1][0]='6';v[1][3]='1';v[1][4]='9';v[1][5]='5';
	v[2][1]='9';v[2][2]='8';v[2][7]='6';
	v[3][0]='8';v[3][4]='6';v[3][8]='3';
	v[4][0]='4';v[4][3]='8';v[4][5]='3';v[4][8]='1';
	v[5][0]='7';v[5][4]='2';v[5][8]='6';
	v[6][1]='6';v[6][6]='2';v[6][7]='8';
	v[7][3]='4';v[7][4]='1';v[7][5]='9';v[7][8]='5';
	v[8][4]='8';v[8][7]='7';v[8][8]='9';
	show(v);
	s.solveSudoku(v);
	cout<<"###############################"<<endl;
	show(v);
	return 0;
}
