/*
   You are given two 0-indexed strings source and target, both of length n and consisting of lowercase English letters. You are also given two 0-indexed character arrays original and changed, and an integer array cost, where cost[i] represents the cost of changing the character original[i] to the character changed[i].

   You start with the string source. In one operation, you can pick a character x from the string and change it to the character y at a cost of z if there exists any index j such that cost[j] == z, original[j] == x, and changed[j] == y.

   Return the minimum cost to convert the string source to the string target using any number of operations. If it is impossible to convert source to target, return -1.

   Note that there may exist indices i, j such that original[j] == original[i] and changed[j] == changed[i].



   Example 1:

Input: source = "abcd", target = "acbe", original = ["a","b","c","c","e","d"], changed = ["b","c","b","e","b","e"], cost = [2,5,5,1,2,20]
Output: 28
Explanation: To convert the string "abcd" to string "acbe":
- Change value at index 1 from 'b' to 'c' at a cost of 5.
- Change value at index 2 from 'c' to 'e' at a cost of 1.
- Change value at index 2 from 'e' to 'b' at a cost of 2.
- Change value at index 3 from 'd' to 'e' at a cost of 20.
The total cost incurred is 5 + 1 + 2 + 20 = 28.
It can be shown that this is the minimum possible cost.

Example 2:

Input: source = "aaaa", target = "bbbb", original = ["a","c"], changed = ["c","b"], cost = [1,2]
Output: 12
Explanation: To change the character 'a' to 'b' change the character 'a' to 'c' at a cost of 1, followed by changing the character 'c' to 'b' at a cost of 2, for a total cost of 1 + 2 = 3. To change all occurrences of 'a' to 'b', a total cost of 3 1042.FlowerPlantingWithNoAdjacent.cc 1129.ShortestPathwithAlternatingColors 1129.ShortestPathwithAlternatingColors.cc 1192.CriticalConnectionsinaNetwork 1192.CriticalConnectionsinaNetwork.cc 1334.FindtheCityWiththeSmallestNumberofNeighborsataThresholdDistance 1334.FindtheCityWiththeSmallestNumberofNeighborsataThresholdDistance.cc 133.CloneGraph 133.CloneGraph.cc 135.Candy 135.Candy.cc 1368.MinimumCosttoMakeatLeastOneValidPathinaGrid.cc 1436.DestinationCity.cc 1462.CourseScheduleIV.cc 1466.ReorderRoutestoMakeAllPathsLeadtotheCityZero.cc 1514.PathwithMaximumProbability 1514.PathwithMaximumProbability.cc 1519.NumberofNodesintheSub-TreeWiththeSameLabel 1519.NumberofNodesintheSub-TreeWiththeSameLabel.cc 1568.MinimumNumberofDaystoDisconnectIsland 1568.MinimumNumberofDaystoDisconnectIsland.cc 1584.MinCosttoConnectAllPoints.cc 1615.MaximalNetworkRank 1615.MaximalNetworkRank.cc 1761.MinimumDegreeofaConnectedTrioinaGraph.cc 1782.CountPairsOfNodes 1782.CountPairsOfNodes.cc 1786.NumberofRestrictedPathsFromFirsttoLastNode 1786.NumberofRestrictedPathsFromFirsttoLastNode.cc 1976.NumberofWaystoArriveatDestination 1976.NumberofWaystoArriveatDestination.cc 2003.SmallestMissingGeneticValueinEachSubtree 2003.SmallestMissingGeneticValueinEachSubtree.cc 2039.TheTimeWhentheNetworkBecomesIdle.cc 2045.SecondMinimumTimetoReachDestination 2045.SecondMinimumTimetoReachDestination.cc 2065.MaximumPathQualityofaGraph 2065.MaximumPathQualityofaGraph.cc 207.CourseSchedule.cc 2097.ValidArrangementofPairs 2097.ValidArrangementofPairs.cc 210.CourseScheduleII.cc 2203.MinimumWeightedSubgraphWiththeRequiredPaths.cc 2285.MaximumTotalImportanceofRoads.cc 2322.MinimumScoreAfterRemovalsonaTree.cc 2360.LongestCycleinaGraph.cc 2368.ReachableNodesWithRestrictions.cc 2492.MinimumScoreofaPathBetweenTwoCities.cc 2493.DivideNodesIntotheMaximumNumberofGroups.cc 2497.MaximumStarSumofaGraph.cc 2508.AddEdgestoMakeDegreesofAllNodesEven.cc 2581.CountNumberofPossibleRootNodes 2581.CountNumberofPossibleRootNodes.cc 2608.ShortestCycleinaGraph 2608.ShortestCycleinaGraph.cc 2642.DesignGraphWithShortestPathCalculator 2642.DesignGraphWithShortestPathCalculator.cc 2646.MinimizetheTotalPriceoftheTrips 2646.MinimizetheTotalPriceoftheTrips.cc 2662.MinimumCostofaPathWithSpecialRoads 2662.MinimumCostofaPathWithSpecialRoads.cc 2685.CounttheNumberofCompleteComponents 2685.CounttheNumberofCompleteComponents.cc 2699.ModifyGraphEdgeWeights 2699.ModifyGraphEdgeWeights.cc 2846.MinimumEdgeWeightEquilibriumQueriesinaTree 2846.MinimumEdgeWeightEquilibriumQueriesinaTree.cc 2858.MinimumEdgeReversalsSoEveryNodeIsReachable 2858.MinimumEdgeReversalsSoEveryNodeIsReachable.cc 2924.FindChampionII 2924.FindChampionII.cc 2976.MinimumCosttoConvertStringI.cc 399.EvaluateDivision 399.EvaluateDivision.cc 743.NetworkDelayTime.cc 753.CrackingtheSafe 753.CrackingtheSafe.cc 785.IsGraphBipartite.cc 787.CheapestFlightsWithinKStops.cc 802.FindEventualSafeStates.cc 834.SumofDistancesinTree 834.SumofDistancesinTree.cc 882.ReachableNodesInSubdividedGraph 882.ReachableNodesInSubdividedGraph.cc 924.MinimizeMalwareSpread 924.MinimizeMalwareSpread.cc 934.ShortestBridge 934.ShortestBridge.cc head.cc head.h head.o lib.a l.sh makefile 4 = 12 is incurred.

Example 3:

Input: source = "abcd", target = "abce", original = ["a"], changed = ["e"], cost = [10000]
Output: -1
Explanation: It is impossible to convert source to target because the value at index 3 cannot be changed from 'd' to 'e'.



Constraints:

1 <= source.length == target.length <= 105
source, target consist of lowercase English letters.
1 <= cost.length == original.length == changed.length <= 2000
original[i], changed[i] are lowercase English letters.
1 <= cost[i] <= 106
original[i] != changed[i]

*/


#include"head.h"
class Solution {
	public:
		typedef long long ll;
		static const int N=26;
		static const int MAX=1e7;
		long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
			const int n=source.size();
			int dist[N][N];
			for(int i=0;i<N;i++)
			{
				for(int j=0;j<N;j++)
					dist[i][j]=MAX;
				dist[i][i]=0;
			}
			for(int i=0;i<original.size();i++)
			{
				int x=original[i]-'a',y=changed[i]-'a';
				dist[x][y]=min(dist[x][y],cost[i]);
			}
			for(int k=0;k<N;k++)
				for(int i=0;i<N;i++)
					for(int j=0;j<N;j++)
						dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			ll res=0;
			for(int i=0;i<n;i++)
			{
				if(dist[source[i]-'a'][target[i]-'a']==MAX)
					return -1;
				res+=dist[source[i]-'a'][target[i]-'a'];
			}
			return res;
		}
};


int main() 
{
	Solution s;
	vector<char> original = {'a','b','c','c','e','d'}, changed = {'b','c','b','e','b','e'};
	vector<int> cost={2,5,5,1,2,20};
	cout<<s.minimumCost("abcd","acbe",original,changed,cost)<<endl;
	original.clear();changed.clear();
	original={'a','c'},changed={'c','b'};
	cost.clear();
	cost={1,2};
	cout<<s.minimumCost("aaaa","bbbb",original,changed,cost)<<endl;
	return 0;
}
