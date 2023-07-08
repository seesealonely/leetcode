/*
   You are given an m x n grid grid where:

   '.' is an empty cell.
   '#' is a wall.
   '@' is the starting point.
   Lowercase letters represent keys.
   Uppercase letters represent locks.

   You start at the starting point and one move consists of walking one space in one of the four cardinal directions. You cannot walk outside the grid, or walk into a wall.

   If you walk over a key, you can pick it up and you cannot walk over a lock unless you have its corresponding key.

   For some 1 <= k <= 6, there is exactly one lowercase and one uppercase letter of the first k letters of the English alphabet in the grid. This means that there is exactly one key for each lock, and one lock for each key; and also that the letters used to represent the keys and locks were chosen in the same order as the English alphabet.

   Return the lowest number of moves to acquire all keys. If it is impossible, return -1.



   Example 1:

Input: grid = ["@.a..","###.#","b.A.B"]
Output: 8
Explanation: Note that the goal is to obtain all the keys not to open all the locks.

Example 2:

Input: grid = ["@..aA","..B#.","....b"]
Output: 6

Example 3:

Input: grid = ["@Aa"]
Output: -1



Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 30
grid[i][j] is either an English letter, '.', '#', or '@'.
There is exactly one '@' in the grid.
The number of keys in the grid is in the range [1, 6].
Each key in the grid is unique.
Each key in the grid has a matching lock.

*/


#include"head.h"
class Node
{
	public:
		int x,y,mask;
		Node(int x,int y,int mask)
		{
			this->x=x;
			this->y=y;
			this->mask=mask;
		}
};
class Solution {
	public:
		int shortestPathAllKeys(vector<string>& grid) {
			const int r=grid.size(),c=grid[0].size();

			vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
			int cnt=0;
			queue<Node> q;

			vector<vector<vector<int>>> dis(r,vector<vector<int>>(c,vector<int>(1<<6,1<<7)));
			for(int i=0;i<r;i++)
				for(int j=0;j<c;j++)
					if(grid[i][j]=='@')
					{
						q.push(Node(i,j,0));
						dis[i][j][0]=0;
					}
					else if(grid[i][j]>='a'&&grid[i][j]<='f')
						cnt++;

			while(!q.empty())
			{
				Node s=q.front();
				q.pop();
				for(int i=0;i<4;i++)
				{
					int x=s.x+dir[i][0],y=s.y+dir[i][1];
					if(x<0||y<0||x>=r||y>=c||grid[x][y]=='#')
						continue;

					if(grid[x][y]>='A'&&grid[x][y]<='F'&&!(s.mask&(1<<(grid[x][y]-'A'))))
						continue;

					int nextmask=s.mask;
					if(grid[x][y]>='a'&&grid[x][y]<='f')
						nextmask|=1<<(grid[x][y]-'a');

					Node next(x,y,nextmask);
					if(dis[x][y][nextmask]>dis[s.x][s.y][s.mask]+1)
					{
						dis[x][y][nextmask]=dis[s.x][s.y][s.mask]+1;
						q.push(next);
					}
				}
			}

			int res=(1<<7);
			for(int i=0;i<r;i++)
				for(int j=0;j<c;j++)
					res=min(res,dis[i][j][(1<<cnt)-1]);

			return res==(1<<7)?-1:res;
		}
};


int main() 
{
	Solution s;
	vector<string> grid={"@.a.#","###.#","b.A.B"};
	cout<<s.shortestPathAllKeys(grid)<<endl;
	grid.clear();grid={"@..aA","..B#.","....b"};
	cout<<s.shortestPathAllKeys(grid)<<endl;
	return 0;
}
