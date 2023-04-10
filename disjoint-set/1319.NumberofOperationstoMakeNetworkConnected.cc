/*
   There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

   You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

   Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.



   Example 1:

Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.

Example 2:

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2

Example 3:

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
Explanation: There are not enough cables.



Constraints:

1 <= n <= 105
1 <= connections.length <= min(n * (n - 1) / 2, 105)
connections[i].length == 2
0 <= ai, bi < n
ai != bi
There are no repeated connections.
No two computers are connected by more than one cable.

*/


#include"head.h"
class Solution {
	public:
		class uf
		{
			public:
				vector<int> p,size;
				uf(int n)
				{
					p.resize(n);
					size.resize(n);
					for(int i=0;i<n;i++)
						p[i]=i;
				}
				int find(int x)
				{
					return p[x]=(x==p[x]?x:find(p[x]));
				}
				void merge(int x,int y)
				{
					int px=find(x),py=find(y);
					if(px!=py)
					{
						if(size[px]<size[py])
						{
							p[px]=py;
							size[py]+=size[px];
						}
						else
						{
							p[py]=px;
							size[px]+=size[py];
						}
					}
				}
		};
		int makeConnected(int n, vector<vector<int>>& connections) {
		if(connections.size()<n-1)
			return -1;

		uf u(n);
		for(int i=0;i<connections.size();i++)
			u.merge(connections[i][0],connections[i][1]);

		int res=0;
		for(int i=0;i<n;i++)
			if(u.find(i)==i)
				res++;
		return res-1;
		


		}
};


int main() 
{
	Solution s;
	vector<vector<int>> c={{0,1},{0,2},{1,2}};
	cout<<s.makeConnected(4,c)<<endl;
	c.push_back({0,3});
	c.push_back({1,3});
	cout<<s.makeConnected(6,c)<<endl;
	c.clear();c={{0,1},{0,2},{1,2},{0,3}};
	cout<<s.makeConnected(6,c)<<endl;
	return 0;
}
