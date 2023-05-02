/*
   Given an undirected tree consisting of n vertices numbered from 1 to n. A frog starts jumping from vertex 1. In one second, the frog jumps from its current vertex to another unvisited vertex if they are directly connected. The frog can not jump back to a visited vertex. In case the frog can jump to several vertices, it jumps randomly to one of them with the same probability. Otherwise, when the frog can not jump to any unvisited vertex, it jumps forever on the same vertex.

   The edges of the undirected tree are given in the array edges, where edges[i] = [ai, bi] means that exists an edge connecting the vertices ai and bi.

   Return the probability that after t seconds the frog is on the vertex target. Answers within 10-5 of the actual answer will be accepted.



   Example 1:

Input: n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 2, target = 4
Output: 0.16666666666666666
Explanation: The figure above shows the given graph. The frog starts at vertex 1, jumping with 1/3 probability to the vertex 2 after second 1 and then jumping with 1/2 probability to vertex 4 after second 2. Thus the probability for the frog is on the vertex 4 after 2 seconds is 1/3 1293.ShortestPathinaGridwithObstaclesElimination 1293.ShortestPathinaGridwithObstaclesElimination.cc 1311.GetWatchedVideosbyYourFriends 1311.GetWatchedVideosbyYourFriends.cc 1377.FrogPositionAfterTSeconds.cc 1609.EvenOddTree.cc 1654.MinimumJumpstoReachHome 1654.MinimumJumpstoReachHome.cc 1926.NearestExitfromEntranceinMaze.cc 2146.KHighestRankedItemsWithinaPriceRange 2146.KHighestRankedItemsWithinaPriceRange.cc 2359.FindClosestNodetoGivenTwoNodes.cc 2617.MinimumNumberofVisitedCellsinaGrid 2617.MinimumNumberofVisitedCellsinaGrid.cc 286.WallsandGates.cc 403.FrogJump.cc 690.EmployeeImportance.cc 773.SlidingPuzzle 773.SlidingPuzzle.cc 815.BusRoutes.cc 818.RaceCar 818.RaceCar.cc head.cc head.h head.o lib.a l.sh makefile 1/2 = 1/6 = 0.16666666666666666.

Example 2:

Input: n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 1, target = 7
Output: 0.3333333333333333
Explanation: The figure above shows the given graph. The frog starts at vertex 1, jumping with 1/3 = 0.3333333333333333 probability to the vertex 7 after second 1.



Constraints:

1 <= n <= 100
edges.length == n - 1
edges[i].length == 2
1 <= ai, bi <= n
1 <= t <= 50
1 <= target <= n

*/


#include"head.h"
class Solution {
	public:
		double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
		vector<vector<int>> tree(n+1);

		for(int i=0;i<edges.size();i++)
		{
			int x=edges[i][0],y=edges[i][1];
			tree[x].push_back(y);
			tree[y].push_back(x);
		}

		vector<pair<int,double>> dis(n+1,{INT_MAX,0});
		queue<int>q;

		q.push(1);
		dis[1].first=0;
		dis[1].second=1.0;

		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			if(dis[u].first>=t)
				continue;

			for(int i=0;i<tree[u].size();i++)
			{
				int v=tree[u][i];
				if(dis[v].first>dis[u].first+1)
				{
					dis[v].first=dis[u].first+1;
					dis[v].second=dis[u].second/(tree[u].size()-(int)(u!=1));
					q.push(v);
				}
			}
		}

		if(dis[target].first<t)
		{
			if(target==1&&tree[1].size()>0||tree[target].size()>1)
				return 0;
		}

		return dis[target].second;
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> v={{1,2},{1,3},{1,7},{2,4},{2,6},{3,5}};
	cout<<s.frogPosition(7,v,2,4)<<endl;
	v.clear();v={{1,2},{1,3},{1,7},{2,4},{2,6},{3,5}};
	cout<<s.frogPosition(7,v,1,7)<<endl;
	return 0;
}
