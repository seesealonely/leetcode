/*
   You are given a square board of characters. You can move on the board starting at the bottom right square marked with the character 'S'.

   You need to reach the top left square marked with the character 'E'. The rest of the squares are labeled either with a numeric character 1, 2, ..., 9 or with an obstacle 'X'. In one move you can go up, left or up-left (diagonally) only if there is no obstacle there.

   Return a list of two integers: the first integer is the maximum sum of numeric characters you can collect, and the second is the number of such paths that you can take to get that maximum sum, taken modulo 10^9 + 7.

   In case there is no path, return [0, 0].



   Example 1:

Input: board = ["E23","2X2","12S"]
Output: [7,1]

Example 2:

Input: board = ["E12","1X1","21S"]
Output: [4,2]

Example 3:

Input: board = ["E11","XXX","11S"]
Output: [0,0]



Constraints:

2 <= board.length == board[i].length <= 100
*/


#include"head.h"
class Solution {
	public:
		vector<int> pathsWithMaxScore(vector<string>& board) {
		const int n=board.size();
		vector<vector<int>> f(n,vector<int>(n,INT_MIN));
		vector<vector<int>> g(n,vector<int>(n,0));

		const int dx[]={0,-1,-1};
		const int dy[]={-1,-1,0};
		const int mod=1e9+7;

		board[n-1][n-1]='0';
		f[0][0]=0;
		g[0][0]=1;

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				if(board[i][j]=='X')
					continue;

				for(int k=0;k<3;k++)
				{
					int x=i+dx[k],y=j+dy[k];

					if(x<0||y<0||f[x][y]==INT_MIN)
						continue;

					if(f[i][j]<f[x][y]+board[i][j]-'0')
						f[i][j]=f[x][y]+board[i][j]-'0',
						g[i][j]=g[x][y];
					else if(f[i][j]==f[x][y]+board[i][j]-'0')
						g[i][j]=(g[i][j]+g[x][y])%mod;
				}
			}

		if(f[n-1][n-1]==INT_MIN)
		return {0,0};
		return {f[n-1][n-1],g[n-1][n-1]};
		}
};


int main() 
{
	Solution s;
	vector<string> v={"E23","2X2","12S"};
	show(s.pathsWithMaxScore(v));
	v.clear();v={"E12","1X1","21S"};
	show(s.pathsWithMaxScore(v));
	v.clear();v={"E11","XXX","11S"};
	show(s.pathsWithMaxScore(v));
	return 0;
}
