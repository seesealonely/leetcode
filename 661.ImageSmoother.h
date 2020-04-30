/*
Given a 2D integer matrix M representing the gray scale of an image, you need to design a smoother to make the gray scale of each cell becomes the average gray scale (rounding down) of all the 8 surrounding cells and itself. If a cell has less than 8 surrounding cells, then use as many as you can.

Example 1:

Input:
[[1,1,1],
 [1,0,1],
 [1,1,1]]
Output:
[[0, 0, 0],
 [0, 0, 0],
 [0, 0, 0]]
Explanation:
For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
For the point (1,1): floor(8/9) = floor(0.88888889) = 0

Note:

    The value in the given matrix is in the range of [0, 255].
    The length and width of the given matrix are in the range of [1, 150].

*/

#include"head.h"

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
	if(M.empty()||M[0].empty()) return {{}};
	int mr=M.size(),mc=M[0].size();
	vector<vector<int> > dirs={{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
	for(int i=0;i<mr;i++)
		for(int j=0;j<mc;j++)
		{
			int sum=M[i][j],count=1;
			for(int k=0;k<dirs.size();k++)
			{
			int x=i+dirs[k][0],y=j+dirs[k][1];
			if(round(mr,mc,x,y))
			{
				sum+=M[x][y]&0xFF;
				count++;	
			}
			}
			M[i][j]|=((sum/count)<<8);
		}
	for(int i=0;i<mr;i++)
		for(int j=0;j<mc;j++)
		M[i][j]>>=8;
	return M;
    }
	bool round(int mr,int mc,int r,int c)
	{
		if(r<0||c<0||r>=mr||c>=mc) return false;
		return true;
	}
};
