/*
   You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting vertices ai and bi.

   Return the number of complete connected components of the graph.

   A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.

   A connected component is said to be complete if there exists an edge between every pair of its vertices.



   Example 1:

Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
Output: 3
Explanation: From the picture above, one can see that all of the components of this graph are complete.

Example 2:

Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
Output: 1
Explanation: The component containing vertices 0, 1, and 2 is complete since there is an edge between every pair of two vertices. On the other hand, the component containing vertices 3, 4, and 5 is not complete since there is no edge between vertices 4 and 5. Thus, the number of complete components in this graph is 1.



Constraints:

1 <= n <= 50
0 <= edges.length <= n 1042.FlowerPlantingWithNoAdjacent.cc 1129.ShortestPathwithAlternatingColors 1129.ShortestPathwithAlternatingColors.cc 1334.FindtheCityWiththeSmallestNumberofNeighborsataThresholdDistance 1334.FindtheCityWiththeSmallestNumberofNeighborsataThresholdDistance.cc 133.CloneGraph 133.CloneGraph.cc 135.Candy 135.Candy.cc 1368.MinimumCosttoMakeatLeastOneValidPathinaGrid.cc 1436.DestinationCity.cc 1462.CourseScheduleIV.cc 1466.ReorderRoutestoMakeAllPathsLeadtotheCityZero.cc 1514.PathwithMaximumProbability 1514.PathwithMaximumProbability.cc 1519.NumberofNodesintheSub-TreeWiththeSameLabel 1519.NumberofNodesintheSub-TreeWiththeSameLabel.cc 1584.MinCosttoConnectAllPoints.cc 1615.MaximalNetworkRank 1615.MaximalNetworkRank.cc 1761.MinimumDegreeofaConnectedTrioinaGraph.cc 1786.NumberofRestrictedPathsFromFirsttoLastNode 1786.NumberofRestrictedPathsFromFirsttoLastNode.cc 1976.NumberofWaystoArriveatDestination 1976.NumberofWaystoArriveatDestination.cc 2039.TheTimeWhentheNetworkBecomesIdle.cc 2045.SecondMinimumTimetoReachDestination 2045.SecondMinimumTimetoReachDestination.cc 2065.MaximumPathQualityofaGraph 2065.MaximumPathQualityofaGraph.cc 207.CourseSchedule.cc 210.CourseScheduleII.cc 2203.MinimumWeightedSubgraphWiththeRequiredPaths.cc 2285.MaximumTotalImportanceofRoads.cc 2322.MinimumScoreAfterRemovalsonaTree.cc 2360.LongestCycleinaGraph.cc 2368.ReachableNodesWithRestrictions.cc 2492.MinimumScoreofaPathBetweenTwoCities.cc 2493.DivideNodesIntotheMaximumNumberofGroups.cc 2497.MaximumStarSumofaGraph.cc 2508.AddEdgestoMakeDegreesofAllNodesEven.cc 2581.CountNumberofPossibleRootNodes 2581.CountNumberofPossibleRootNodes.cc 2608.ShortestCycleinaGraph 2608.ShortestCycleinaGraph.cc 2642.DesignGraphWithShortestPathCalculator 2642.DesignGraphWithShortestPathCalculator.cc 2646.MinimizetheTotalPriceoftheTrips 2646.MinimizetheTotalPriceoftheTrips.cc 2662.MinimumCostofaPathWithSpecialRoads 2662.MinimumCostofaPathWithSpecialRoads.cc 2685.CounttheNumberofCompleteComponents.cc 399.EvaluateDivision 399.EvaluateDivision.cc 743.NetworkDelayTime.cc 753.CrackingtheSafe 753.CrackingtheSafe.cc 785.IsGraphBipartite.cc 787.CheapestFlightsWithinKStops.cc 802.FindEventualSafeStates.cc 834.SumofDistancesinTree 834.SumofDistancesinTree.cc 882.ReachableNodesInSubdividedGraph 882.ReachableNodesInSubdividedGraph.cc 924.MinimizeMalwareSpread 924.MinimizeMalwareSpread.cc 934.ShortestBridge 934.ShortestBridge.cc head.cc head.h head.o lib.a l.sh makefile (n - 1) / 2
edges[i].length == 2
0 <= ai, bi <= n - 1
ai != bi
There are no repeated edges.

*/


#include"head.h"
class Solution {
	public:
		vector<vector<int>> g;
		vector<bool> vis;
		int countCompleteComponents(int n, vector<vector<int>>& edges) {
			g.resize(n);
			for(int i=0;i<edges.size();i++)
			{
				int x=edges[i][0],y=edges[i][1];
				g[x].push_back(y);
				g[y].push_back(x);
			}
			vis.resize(n,false);

			int res=0;
			for(int i=0;i<n;i++)
				if(!vis[i])
					res+=check(i,n);
		}
		int check(int st,int n)
		{
			vis[st]=true;
			queue<int> q;
			q.push(st);

			int size=0,tot=0;
			while(!q.empty())
			{
				int u=q.front();
				q.pop();

				++size;
				tot+=g[u].size();

				for(int i=0;i<g[u].size();i++)
				{
					int v=g[u][i];
					if(!vis[v])
					{
						vis[v]=true;
						q.push(v);
					}
				}
			}
			return tot==size*(size-1);
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> edges = {{0,1},{0,2},{1,2},{3,4}};
	cout<<s.countCompleteComponents(6,edges)<<endl;
	edges.clear();edges = {{0,1},{0,2},{1,2},{3,4},{3,5}};
	cout<<s.countCompleteComponents(6,edges)<<endl;
	return 0;
}
