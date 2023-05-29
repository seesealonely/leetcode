/*
   Given a 1-indexed m x n integer matrix mat, you can select any cell in the matrix as your starting cell.

   From the starting cell, you can move to any other cell in the same row or column, but only if the value of the destination cell is strictly greater than the value of the current cell. You can repeat this process as many times as possible, moving from cell to cell until you can no longer make any moves.

   Your task is to find the maximum number of cells that you can visit in the matrix by starting from some cell.

   Return an integer denoting the maximum number of cells that can be visited.



   Example 1:

Input: mat = [[3,1],[3,4]]
Output: 2
Explanation: The image shows how we can visit 2 cells starting from row 1, column 2. It can be shown that we cannot visit more than 2 cells no matter where we start from, so the answer is 2. 

Example 2:

Input: mat = [[1,1],[1,1]]
Output: 1
Explanation: Since the cells must be strictly increasing, we can only visit one cell in this example. 

Example 3:

Input: mat = [[3,1,6],[-9,5,7]]
Output: 4
Explanation: The image above shows how we can visit 4 cells starting from row 2, column 1. It can be shown that we cannot visit more than 4 cells no matter where we start from, so the answer is 4. 



Constraints:

m == mat.length 
n == mat[i].length 
1 <= m, n <= 105
1 <= m * n <= 105
-105 <= mat[i][j] <= 105

*/


#include"head.h"
class Solution {
	public:
		int maxIncreasingCells(vector<vector<int>>& mat) {
			typedef pair<int,int> pii;
			#define f  first 
			#define s  second 
			const int r=mat.size(),c=mat[0].size();

			vector<pii> p(r*c);
			for(int i=0;i<r;i++)
				for(int j=0;j<c;j++)
					p[i*c+j]=make_pair(i,j);

			sort(p.begin(),p.end(),[&](const pii &i,const pii &j)
			{
				return mat[i.f][i.s]>mat[j.f][j.s];
			});

			vector<int> dp(r*c),row(r,0),col(c,0);

			int res=1;
			dp[0]=1;

			for(int i=1,j=0;i<r*c;i++)
			{
				if(mat[p[j].f][p[j].s]>mat[p[i].f][p[i].s])
					while(j<i)
					{
						row[p[j].f]=max(row[p[j].f],dp[j]);
						col[p[j].s]=max(col[p[j].s],dp[j]);
						j++;
					}

				dp[i]=max(row[p[i].f],col[p[i].s])+1;
				res=max(res,dp[i]);
			}

			return res;

		}
};


int main() 
{
	Solution s;
	vector<vector<int>> mat={{3,1},{3,4}};
	cout<<s.maxIncreasingCells(mat)<<endl;
	mat.clear();mat={{1,1},{1,1}};
	cout<<s.maxIncreasingCells(mat)<<endl;
	mat.clear();mat={{3,1,6},{-9,5,7}};
	cout<<s.maxIncreasingCells(mat)<<endl;
	return 0;
}
