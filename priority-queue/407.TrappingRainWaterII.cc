/*
   Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.



   Example 1:

Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
Output: 4
Explanation: After the rain, water is trapped between the blocks.
We have two small ponds 1 and 3 units trapped.
The total volume of water trapped is 4.

Example 2:

Input: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
Output: 10



Constraints:

m == heightMap.length
n == heightMap[i].length
1 <= m, n <= 200
0 <= heightMap[i][j] <= 2 * 104

*/


#include"head.h"
class Node
{
	public:
		int x,y,f;
		Node(int x,int y,int f)
		{
			this->x=x;
			this->y=y;
			this->f=f;
		}
		bool operator <(const Node &p) const
		{
			return f>p.f;
		}
};
class Solution {
	public:
		int trapRainWater(vector<vector<int>>& heightMap) {
		const int r=heightMap.size(),c=heightMap[0].size();

		const int dx[4]={0, 1, 0, -1};
		const int dy[4]={1, 0, -1, 0};
		vector<vector<int>> f(r,vector<int>(c,INT_MAX));
		priority_queue<Node> pq;

		for(int i=0;i<r;i++)
		{
			f[i][0]=heightMap[i][0];
			f[i][c-1]=heightMap[i][c-1];
			pq.push(Node(i,0,f[i][0]));
			pq.push(Node(i,c-1,f[i][c-1]));
		}

		for(int i=0;i<c;i++)
		{
			f[0][i]=heightMap[0][i];
			f[r-1][i]=heightMap[r-1][i];
			pq.push(Node(0,i,f[0][i]));
			pq.push(Node(r-1,i,f[r-1][i]));
		}

			int res=0;
		while(!pq.empty())
		{
			Node u=pq.top();
			pq.pop();

			if(f[u.x][u.y]<u.f)
				continue;

			res+=f[u.x][u.y]-heightMap[u.x][u.y];

			for(int i=0;i<4;i++)
			{
				int vx=u.x+dx[i],vy=u.y+dy[i];

				if(vx<0||vx>=r||vy<0||vy>=c)
					continue;
				if(f[vx][vy]>max(heightMap[vx][vy],f[u.x][u.y]))
				{
					f[vx][vy]=max(heightMap[vx][vy],f[u.x][u.y]);
					pq.push(Node(vx,vy,f[vx][vy]));
				}
			}
		}
		return res;
		}
};


int main() 
{
	Solution s;
	vector<vector<int>>  heightMap = {{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};
	cout<<s.trapRainWater(heightMap)<<endl;
	heightMap.clear();heightMap = {{3,3,3,3,3},{3,2,2,2,3},{3,2,1,2,3},{3,2,2,2,3},{3,3,3,3,3}};
	cout<<s.trapRainWater(heightMap)<<endl;
	return 0;
}
