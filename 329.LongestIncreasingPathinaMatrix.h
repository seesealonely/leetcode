/*
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

Input: nums = 
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
] 
Output: 4 
Explanation: The longest increasing path is [1, 2, 6, 9].

Example 2:

Input: nums = 
[
  [3,4,5],
  [3,2,6],
  [2,2,1]
] 
Output: 4 
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

*/
#include"head.h"

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
	if(!matrix.size() ) return 0;
	vector<vector<int> > dirs={{0,1},{1,0},{0,-1},{-1,0}};
	vector<vector<int> > v(matrix.size(),vector<int> (matrix[0].size(),0));
	int res=0;
	for(int i=0;i<matrix.size();i++)
		for(int j=0;j<matrix[0].size();j++)
		res=max(res,help(dirs,matrix,v,i,j,matrix.size()-1,matrix[0].size()-1));

	return res;
    }
	int help(vector<vector<int> > &d,vector<vector<int> > &m,vector<vector<int> > &visit,int r,int c,int mr,int mc)
	{
		if(visit[r][c]) return visit[r][c];
		int res=1,len=1;
		for(int i=0;i<d.size();i++)
		{
			int x=r+d[i][0],y=c+d[i][1];
			if(x<0||y<0||x>mr||y>mc||m[r][c]>=m[x][y]) continue;
			len=1+help(d,m,visit,x,y,mr,mc);
			res=max(res,len);
		}	
		visit[r][c]=res;
		return res;
	}
};
