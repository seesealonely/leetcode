/*
   There is an undirected tree with n nodes labeled from 0 to n - 1. You are given the integer n and a 2D integer array edges of length n - 1, where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

   You are also given a 0-indexed integer array values of length n, where values[i] is the value associated with the ith node, and an integer k.

   A valid split of the tree is obtained by removing any set of edges, possibly empty, from the tree such that the resulting components all have values that are divisible by k, where the value of a connected component is the sum of the values of its nodes.

   Return the maximum number of components in any valid split.



   Example 1:

Input: n = 5, edges = [[0,2],[1,2],[1,3],[2,4]], values = [1,8,1,4,4], k = 6
Output: 2
Explanation: We remove the edge connecting node 1 with 2. The resulting split is valid because:
- The value of the component containing nodes 1 and 3 is values[1] + values[3] = 12.
- The value of the component containing nodes 0, 2, and 4 is values[0] + values[2] + values[4] = 6.
It can be shown that no other valid split has more than 2 connected components.

Example 2:

Input: n = 7, edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]], values = [3,0,6,1,5,2,1], k = 3
Output: 3
Explanation: We remove the edge connecting node 0 with 2, and the edge connecting node 0 with 1. The resulting split is valid because:
- The value of the component containing node 0 is values[0] = 3.
- The value of the component containing nodes 2, 5, and 6 is values[2] + values[5] + values[6] = 9.
- The value of the component containing nodes 1, 3, and 4 is values[1] + values[3] + values[4] = 6.
It can be shown that no other valid split has more than 3 connected components.



Constraints:

1 <= n <= 3 1034.ColoringABorder 1034.ColoringABorder.cc 1080.InsufficientNodesinRoottoLeafPaths 1080.InsufficientNodesinRoottoLeafPaths.cc 1140.StoneGameII.cc 1240.TilingaRectanglewiththeFewestSquares 1240.TilingaRectanglewiththeFewestSquares.cc 1307.VerbalArithmeticPuzzle 1307.VerbalArithmeticPuzzle.cc 130.SurroundedRegions.cc 1340.JumpGameV 1340.JumpGameV.cc 1376.TimeNeededtoInformAllEmployees 1376.TimeNeededtoInformAllEmployees.cc 1553.MinimumNumberofDaystoEatNOranges.cc 1569.NumberofWaystoReorderArraytoGetSameBST 1569.NumberofWaystoReorderArraytoGetSameBST.cc 1617.CountSubtreesWithMaxDistanceBetweenCities 1617.CountSubtreesWithMaxDistanceBetweenCities.cc 1900.TheEarliestandLatestRoundsWherePlayersCompete 1900.TheEarliestandLatestRoundsWherePlayersCompete.cc 2056.NumberofValidMoveCombinationsOnChessboard 2056.NumberofValidMoveCombinationsOnChessboard.cc 2151.MaximumGoodPeopleBasedonStatements 2151.MaximumGoodPeopleBasedonStatements.cc 2267.CheckifThereIsaValidParenthesesStringPath.cc 2658.MaximumNumberofFishinaGrid 2658.MaximumNumberofFishinaGrid.cc 2673.MakeCostsofPathsEqualinaBinaryTree 2673.MakeCostsofPathsEqualinaBinaryTree.cc 2698.FindthePunishmentNumberofanInteger 2698.FindthePunishmentNumberofanInteger.cc 273.IntegertoEnglishWords 273.IntegertoEnglishWords.cc 2741.SpecialPermutations 2741.SpecialPermutations.cc 2767.PartitionStringIntoMinimumBeautifulSubstrings 2767.PartitionStringIntoMinimumBeautifulSubstrings.cc 2816.DoubleaNumberRepresentedasaLinkedList.cc 2872.MaximumNumberofK-DivisibleComponents.cc 332.ReconstructItinerary 332.ReconstructItinerary.cc 385.MiniParser 385.MiniParser.cc 417.PacificAtlanticWaterFlow 417.PacificAtlanticWaterFlow.cc 430.FlattenaMultilevelDoublyLinkedList 430.FlattenaMultilevelDoublyLinkedList.cc 529.Minesweeper 529.Minesweeper.cc 679.24Game 679.24Game.cc 827.MakingALargeIsland 827.MakingALargeIsland.cc 964.LeastOperatorstoExpressNumber 964.LeastOperatorstoExpressNumber.cc head.cc head.h head.o lib.a l.sh makefile 104
edges.length == n - 1
edges[i].length == 2
0 <= ai, bi < n
values.length == n
0 <= values[i] <= 109
1 <= k <= 109
Sum of values is divisible by k.
The input is generated such that edges represents a valid tree.

*/


#include"head.h"
class Solution {
	public:
		int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
			vector<vector<int>> g(n);
			for(int i=0;i<edges.size();i++)
			{
				int x=edges[i][0],y=edges[i][1];
				g[x].push_back(y);
				g[y].push_back(x);
			}
			int res=0;
			dfs(res,0,-1,values,g,k);
			return res;
		}
		int dfs(int &res,int u,int pa,vector<int> &values,vector<vector<int>> &g,int k)
		{
			int sum=values[u]%k;
			for(int i=0;i<g[u].size();i++)
			{
				int v=g[u][i];
				if(v==pa)
					continue;

				int cur=dfs(res,v,u,values,g,k);
				sum=(sum+cur)%k;
			}
			if(sum==0)
				++res;
			return sum;
		}
};


int main() 
{
	Solution s;
	vector<vector<int>>  edges = {{0,2},{1,2},{1,3},{2,4}};
	vector<int> values={1,8,1,4,4};
	cout<<s.maxKDivisibleComponents(5,edges,values,6)<<endl;
	edges.clear();edges = {{0,1},{0,2},{1,3},{1,4},{2,5},{2,6}};
	values.clear();values={3,0,6,1,5,2,1};
	cout<<s.maxKDivisibleComponents(7,edges,values,3)<<endl;
	return 0;
}
