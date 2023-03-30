/*
   A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

   Given a row x col grid of integers, how many 3 x 3 "magic square" subgrids are there? (Each subgrid is contiguous).



   Example 1:

Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
Output: 1
Explanation:
The following subgrid is a 3 x 3 magic square:

while this one is not:

In total, there is only one magic square inside the given grid.

Example 2:

Input: grid = [[8]]
Output: 0



Constraints:

row == grid.length
col == grid[i].length
1 <= row, col <= 10
0 <= grid[i][j] <= 15

*/

#define c11
#include"head.h"
class Solution {
	public:
		vector<vector<int>> g;
		int numMagicSquaresInside(vector<vector<int>>& grid) {
			g=grid;
			const int r=grid.size(),c=grid[0].size();
			int res=0;
			for(int i=0;i<=r-3;i++)
				for(int j=0;j<=c-3;j++)
					if(check(i,j))
						res++;
			return res;
		}
		bool check(int x,int y)
		{
			unordered_set<int> s;
			int sum=0;
			if(x+2>=g.size()||y+2>=g[0].size())
				return false;
			for(int i=x;i<x+3;i++)
			{
				sum=0;
				for(int j=y;j<y+3;j++)
				{
					int x=g[i][j];
					if(s.find(x)!=s.end()||x>=10)
							return false;
					s.insert(x);
					sum+=x;
				}

				if(sum!=15)
					return false;
			}

			s.clear();
			for(int i=y;i<y+3;i++)
			{
				sum=0;
				for(int j=x;j<x+3;j++)
				{
					int x=g[j][i];
					if(s.find(x)!=s.end()||x>=10)
							return false;
					s.insert(x);
					sum+=x;
				}
				if(sum!=15)
					return false;
			}

			if(g[x][y]+g[x+1][y+1]+g[x+2][y+2]!=15||g[x][y+2]+g[x+1][y+1]+g[x+2][y]!=15)
				return false;

			return true;
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> v={{4,3,8,4},{9,5,1,9},{2,7,6,2}};
	cout<<s.numMagicSquaresInside(v)<<endl;
	v.clear();v={{8}};
	cout<<s.numMagicSquaresInside(v)<<endl;
	v.clear();v={{5,5,5},{5,5,5},{5,5,5}};
	cout<<s.numMagicSquaresInside(v)<<endl;
	v.clear();v={{1,8,6},{10,5,0},{4,2,9}};
	cout<<s.numMagicSquaresInside(v)<<endl;
	return 0;
}
