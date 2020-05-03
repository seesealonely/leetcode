/*
*/

#include"832.FlippinganImage.h"

int main()
{
	int e1[3][3]={{1,1,0},{1,0,1},{0,0,0}};
	vector<vector<int> > v1(3,vector<int>(3,0));
	for(int i=0;i<3;i++)	
	for(int j=0;j<3;j++)	
		v1[i][j]=e1[i][j];
	int e2[4][4]={{1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0}};	
	vector<vector<int> > v2(4,vector<int>(4,0));
	for(int i=0;i<4;i++)	
	for(int j=0;j<4;j++)	
		v2[i][j]=e2[i][j];
	Solution s;
	show(s.flipAndInvertImage(v1));
	show(s.flipAndInvertImage(v2));
	return 0;
}
