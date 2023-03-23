/*
   Given a 2D array of characters grid of size m x n, you need to find if there exists any cycle consisting of the same value in grid.

   A cycle is a path of length 4 or more in the grid that starts and ends at the same cell. From a given cell, you can move to one of the cells adjacent to it - in one of the four directions (up, down, left, or right), if it has the same value of the current cell.

   Also, you cannot move to the cell that you visited in your last move. For example, the cycle (1, 1) -> (1, 2) -> (1, 1) is invalid because from (1, 2) we visited (1, 1) which was the last visited cell.

   Return true if any cycle of the same value exists in grid, otherwise, return false.



   Example 1:

Input: grid = [["a","a","a","a"],["a","b","b","a"],["a","b","b","a"],["a","a","a","a"]]
Output: true
Explanation: There are two valid cycles shown in different colors in the image below:

Example 2:

Input: grid = [["c","c","c","a"],["c","d","c","c"],["c","c","e","c"],["f","c","c","c"]]
Output: true
Explanation: There is only one valid cycle highlighted in the image below:

Example 3:

Input: grid = [["a","b","b"],["b","z","b"],["b","b","a"]]
Output: false



Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 500
grid consists only of lowercase English letters.

*/


#include"head.h"
class Solution {
	public:
		vector<int > p;
		int n;
		bool containsCycle(vector<vector<char>>& grid) {
		const int r=grid.size(),c=grid[0].size();
		n=r*c;
		p.resize(n);
		uf();
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
			{
				char cur=grid[i][j];
				if(j+1<c&&cur==grid[i][j+1])
					if(merge(i*c+j,i*c+j+1))
						return true;

				if(i+1<r&&cur==grid[i+1][j])
					if(merge(i*c+j,(i+1)*c+j))
						return true;
			}
		return false;
		}
		void uf()
		{
			for(int i=0;i<n;i++)
				p[i]=i;
		}
		int find(int x)
		{
			return p[x]==x?p[x]:p[x]=find(p[x]);
		}

		bool merge(int x,int y)
		{
			int px=find(x),py=find(y);
			if(px==py)
				return true;
			if(px<py)
				p[py]=px;
			else
			p[px]=py;
			return false;
		}
};


int main() 
{
	Solution s;
	vector<vector<char>> v= {{'a','a','a','a'},{'a','b','b','a'},{'a','b','b','a'},{'a','a','a','a'}};
	cout<<s.containsCycle(v)<<endl;
	return 0;
}
