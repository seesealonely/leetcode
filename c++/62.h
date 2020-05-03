#include<iostream>
using namespace std;
class Solution {
public:
    int uniquePaths(int m,int n) {
		int  res[101][101];
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		if(i==0||j==0)
			res[i][j]=1;
		else
			res[i][j]=res[i-1][j]+res[i][j-1];
		return res[m-1][n-1];
    }
};
