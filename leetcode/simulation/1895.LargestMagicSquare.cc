/*
   A k x k magic square is a k x k grid filled with integers such that every row sum, every column sum, and both diagonal sums are all equal. The integers in the magic square do not have to be distinct. Every 1 x 1 grid is trivially a magic square.

   Given an m x n integer grid, return the size (i.e., the side length k) of the largest magic square that can be found within this grid.



   Example 1:

Input: grid = [[7,1,4,5,6],[2,5,1,6,4],[1,5,4,3,2],[1,2,7,3,4]]
Output: 3
Explanation: The largest magic square has a size of 3.
Every row sum, column sum, and diagonal sum of this magic square is equal to 12.
- Row sums: 5+1+6 = 5+4+3 = 2+7+3 = 12
- Column sums: 5+5+2 = 1+4+7 = 6+3+3 = 12
- Diagonal sums: 5+4+3 = 6+4+2 = 12

Example 2:

Input: grid = [[5,1,3,1],[9,3,3,1],[1,3,3,8]]
Output: 2



Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
1 <= grid[i][j] <= 106

*/
#include"head.h"
class Solution {
	public:
		int largestMagicSquare(vector<vector<int>>& grid) {
		int r=grid.size(),c=grid[0].size(),res=0;
		vector<vector<int> > rowsum(r,vector<int>(c+1,0));
		vector<vector<int> > colsum(r+1,vector<int>(c,0));
		
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
			{
				rowsum[i][j+1]=rowsum[i][j]+grid[i][j];
				colsum[i+1][j]=colsum[i][j]+grid[i][j];
			}

		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				for(int step=res;step+i<r&&step+j<c;step++)
				{
					if(check(grid,rowsum,colsum,i,j,step))
						res=step+1;
				}
		return res;
		}
		bool check(vector<vector<int> > & g,vector<vector<int> > &rs,vector<vector<int> > &cs,int r,int c,int s)
		{
			int diagsum=0,inversesum=0;
			for(int i=0;i<=s;i++)
			{
				diagsum+=g[r+i][c+i];	
				inversesum+=g[r+s-i][c+i];
			}
			if(diagsum!=inversesum) return false;

			for(int i=0;i<=s;i++)
			{
				if(diagsum!=rs[r+i][c+s+1]-rs[r+i][c]) return false;
				if(diagsum!=cs[r+s+1][c+i]-cs[r][c+i]) return false;
			}
			return true;
		}
};
int main() 
{
	Solution s;
	vector<vector<int> > v={{7,1,4,5,6},{2,5,1,6,4},{1,5,4,3,2},{1,2,7,3,4}};
	cout<<s.largestMagicSquare(v)<<endl;
	v.clear();v={{5,1,3,1},{9,3,3,1},{1,3,3,8}};
	cout<<s.largestMagicSquare(v)<<endl;
	return 0;
}
