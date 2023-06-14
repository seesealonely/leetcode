/*
   A farmer has a rectangular grid of land with m rows and n columns that can be divided into unit cells. Each cell is either fertile (represented by a 1) or barren (represented by a 0). All cells outside the grid are considered barren.

   A pyramidal plot of land can be defined as a set of cells with the following criteria:

   The number of cells in the set has to be greater than 1 and all cells must be fertile.
   The apex of a pyramid is the topmost cell of the pyramid. The height of a pyramid is the number of rows it covers. Let (r, c) be the apex of the pyramid, and its height be h. Then, the plot comprises of cells (i, j) where r <= i <= r + h - 1 and c - (i - r) <= j <= c + (i - r).

   An inverse pyramidal plot of land can be defined as a set of cells with similar criteria:

   The number of cells in the set has to be greater than 1 and all cells must be fertile.
   The apex of an inverse pyramid is the bottommost cell of the inverse pyramid. The height of an inverse pyramid is the number of rows it covers. Let (r, c) be the apex of the pyramid, and its height be h. Then, the plot comprises of cells (i, j) where r - h + 1 <= i <= r and c - (r - i) <= j <= c + (r - i).

   Some examples of valid and invalid pyramidal (and inverse pyramidal) plots are shown below. Black cells indicate fertile cells.

   Given a 0-indexed m x n binary matrix grid representing the farmland, return the total number of pyramidal and inverse pyramidal plots that can be found in grid.



   Example 1:

Input: grid = [[0,1,1,0],[1,1,1,1]]
Output: 2
Explanation: The 2 possible pyramidal plots are shown in blue and red respectively.
There are no inverse pyramidal plots in this grid. 
Hence total number of pyramidal and inverse pyramidal plots is 2 + 0 = 2.

Example 2:

Input: grid = [[1,1,1],[1,1,1]]
Output: 2
Explanation: The pyramidal plot is shown in blue, and the inverse pyramidal plot is shown in red. 
Hence the total number of plots is 1 + 1 = 2.

Example 3:

Input: grid = [[1,1,1,1,0],[1,1,1,1,1],[1,1,1,1,1],[0,1,0,0,1]]
Output: 13
Explanation: There are 7 pyramidal plots, 3 of which are shown in the 2nd and 3rd figures.
There are 6 inverse pyramidal plots, 2 of which are shown in the last figure.
The total number of plots is 7 + 6 = 13.



Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 1000
1 <= m * n <= 105
grid[i][j] is either 0 or 1.

*/


#include"head.h"
class Solution {
	public:
		vector<vector<int>> s;
		bool check(const vector<int> &sum,int l,int r)
		{
			if(l<0||r>=sum.size())
				return false;
			return (l==0?sum[r]:sum[r]-sum[l-1])>=r-l+1;
		}

		int count(const vector<vector<int>> &grid)
		{
			const int r=grid.size(),c=grid[0].size();
			int res=0;
			vector<int> f(c,0),g(c);

			for(int i=0;i<r-1;i++)
			{
				for(int j=0;j<c;j++)
				{
					if(grid[i][j]==0)
						continue;
					int k=max(i,f[j]);
					if(j>0) k=max(k,f[j-1]);
					if(j<c-1) k=max(k,f[j+1]);

					res+=k-i;
					for(k++;k<r;k++)
						if(check(s[k],j-(k-i),j+(k-i))) res++;
						else break;

					g[j]=k-1;
				}
				f=g;
			}
			return res;
		}
		int countPyramids(vector<vector<int>>& grid) {
		const int r=grid.size(),c=grid[0].size();
		s.resize(r,vector<int>(c));

		for(int i=0;i<r;i++)
		{
			s[i][0]=grid[i][0];
			for(int j=1;j<c;j++)
				s[i][j]=s[i][j-1]+grid[i][j];
		}

		int res=count(grid);
		reverse(grid.begin(),grid.end());
		reverse(s.begin(),s.end());

		return res+count(grid);
		}
};


int main() 
{
	Solution s;
	vector<vector<int> > grid = {{0,1,1,0},{1,1,1,1}};
	cout<<s.countPyramids(grid)<<endl;
	grid.clear();grid={{1,1,1},{1,1,1}};
	cout<<s.countPyramids(grid)<<endl;
	grid.clear();grid = {{1,1,1,1,0},{1,1,1,1,1},{1,1,1,1,1},{0,1,0,0,1}};
	cout<<s.countPyramids(grid)<<endl;
	return 0;
}
