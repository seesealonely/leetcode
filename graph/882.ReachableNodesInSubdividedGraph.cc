/*
   You are given an undirected graph (the "original graph") with n nodes labeled from 0 to n - 1. You decide to subdivide each edge in the graph into a chain of nodes, with the number of new nodes varying between each edge.

   The graph is given as a 2D array of edges where edges[i] = [ui, vi, cnti] indicates that there is an edge between nodes ui and vi in the original graph, and cnti is the total number of new nodes that you will subdivide the edge into. Note that cnti == 0 means you will not subdivide the edge.

   To subdivide the edge [ui, vi], replace it with (cnti + 1) new edges and cnti new nodes. The new nodes are x1, x2, ..., xcnti, and the new edges are [ui, x1], [x1, x2], [x2, x3], ..., [xcnti-1, xcnti], [xcnti, vi].

   In this new graph, you want to know how many nodes are reachable from the node 0, where a node is reachable if the distance is maxMoves or less.

   Given the original graph and maxMoves, return the number of nodes that are reachable from node 0 in the new graph.



   Example 1:

Input: edges = [[0,1,10],[0,2,1],[1,2,2]], maxMoves = 6, n = 3
Output: 13
Explanation: The edge subdivisions are shown in the image above.
The nodes that are reachable are highlighted in yellow.

Example 2:

Input: edges = [[0,1,4],[1,2,6],[0,2,8],[1,3,1]], maxMoves = 10, n = 4
Output: 23

Example 3:

Input: edges = [[1,2,4],[1,4,5],[1,3,1],[2,3,4],[3,4,5]], maxMoves = 17, n = 5
Output: 1
Explanation: Node 0 is disconnected from the rest of the graph, so only node 0 is reachable.



Constraints:

0 <= edges.length <= min(n 1042.FlowerPlantingWithNoAdjacent.cc 1129.ShortestPathwithAlternatingColors 1129.ShortestPathwithAlternatingColors.cc 1334.FindtheCityWiththeSmallestNumberofNeighborsataThresholdDistance 1334.FindtheCityWiththeSmallestNumberofNeighborsataThresholdDistance.cc 133.CloneGraph 133.CloneGraph.cc 135.Candy 135.Candy.cc 1368.MinimumCosttoMakeatLeastOneValidPathinaGrid.cc 1436.DestinationCity.cc 1462.CourseScheduleIV.cc 1466.ReorderRoutestoMakeAllPathsLeadtotheCityZero.cc 1514.PathwithMaximumProbability 1514.PathwithMaximumProbability.cc 1519.NumberofNodesintheSub-TreeWiththeSameLabel 1519.NumberofNodesintheSub-TreeWiththeSameLabel.cc 1584.MinCosttoConnectAllPoints.cc 1615.MaximalNetworkRank 1615.MaximalNetworkRank.cc 1761.MinimumDegreeofaConnectedTrioinaGraph.cc 1786.NumberofRestrictedPathsFromFirsttoLastNode 1786.NumberofRestrictedPathsFromFirsttoLastNode.cc 1976.NumberofWaystoArriveatDestination 1976.NumberofWaystoArriveatDestination.cc 2039.TheTimeWhentheNetworkBecomesIdle.cc 2045.SecondMinimumTimetoReachDestination 2045.SecondMinimumTimetoReachDestination.cc 2065.MaximumPathQualityofaGraph 2065.MaximumPathQualityofaGraph.cc 207.CourseSchedule.cc 210.CourseScheduleII.cc 2203.MinimumWeightedSubgraphWiththeRequiredPaths.cc 2285.MaximumTotalImportanceofRoads.cc 2322.MinimumScoreAfterRemovalsonaTree.cc 2360.LongestCycleinaGraph.cc 2368.ReachableNodesWithRestrictions.cc 2492.MinimumScoreofaPathBetweenTwoCities.cc 2493.DivideNodesIntotheMaximumNumberofGroups.cc 2497.MaximumStarSumofaGraph.cc 2508.AddEdgestoMakeDegreesofAllNodesEven.cc 2581.CountNumberofPossibleRootNodes 2581.CountNumberofPossibleRootNodes.cc 2608.ShortestCycleinaGraph 2608.ShortestCycleinaGraph.cc 2642.DesignGraphWithShortestPathCalculator 2642.DesignGraphWithShortestPathCalculator.cc 2646.MinimizetheTotalPriceoftheTrips 2646.MinimizetheTotalPriceoftheTrips.cc 399.EvaluateDivision 399.EvaluateDivision.cc 743.NetworkDelayTime.cc 753.CrackingtheSafe 753.CrackingtheSafe.cc 785.IsGraphBipartite.cc 787.CheapestFlightsWithinKStops.cc 802.FindEventualSafeStates.cc 834.SumofDistancesinTree 834.SumofDistancesinTree.cc 882.ReachableNodesInSubdividedGraph.cc 934.ShortestBridge 934.ShortestBridge.cc head.cc head.h head.o lib.a l.sh makefile (n - 1) / 2, 104)
edges[i].length == 3
0 <= ui < vi < n
There are no multiple edges in the graph.
0 <= cnti <= 104
0 <= maxMoves <= 109
1 <= n <= 3000

*/


#include"head.h"
class Solution {
	public:
		class Node
		{
			public:
				int x,d;
				Node (int _x,int _d):x(_x),d(_d){}
				bool operator <(const Node &cur) const 
				{
					return cur.d<d;
				}
		};
		void dijkstra(const vector<vector<pair<int,int>>> &e,int N,vector<int> &dis)
		{
			priority_queue<Node> pq;
			dis[0]=0;
			pq.push(Node(0,0));

			while(!pq.empty())
			{
				Node cur(pq.top());
				pq.pop();

				if(cur.d>dis[cur.x])
					continue;

				for(int i=0;i<e[cur.x].size();i++)
				{
				int f=e[cur.x][i].first,s=e[cur.x][i].second;
				if(dis[f]>dis[cur.x]+s)
				{
					dis[f]=dis[cur.x]+s;
					pq.push(Node(f,dis[f]));
				}
				}
			}
		}
		int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
		const int m=edges.size();
		const int inf=2e8;
		vector<vector<pair<int,int>>> e(m);

		for(int i=0;i<edges.size();i++)
		{
			int x=edges[i][0],y=edges[i][1],w=edges[i][2];
			e[x].push_back({y,w+1});
			e[y].push_back({x,w+1});
		}

		vector<int> dis(n,inf);
		dijkstra(e,n,dis);

		int res=0;
		for(int i=0;i<n;i++)
			res+=dis[i]<=maxMoves;

		for(int i=0;i<edges.size();i++)
		{
			int x=edges[i][0],y=edges[i][1];
			if(dis[x]<=maxMoves&&dis[y]<=maxMoves)
				res+=min(edges[i][2],2*maxMoves-dis[x]-dis[y]);
			else if(dis[x]<=maxMoves&&dis[y]>maxMoves)
				res+=min(edges[i][2],maxMoves-dis[x]);
			else if(dis[y]<=maxMoves&&dis[x]>maxMoves)
				res+=min(edges[i][2],maxMoves-dis[y]);
		}

		return res;
		}
};

int main() 
{
	Solution s;
	vector<vector<int>> edges = {{0,1,10},{0,2,1},{1,2,2}};
	cout<<s.reachableNodes(edges,6,3)<<endl;
	edges.clear();edges = {{0,1,4},{1,2,6},{0,2,8},{1,3,1}};
	cout<<s.reachableNodes(edges,10,4)<<endl;
	return 0;
}
