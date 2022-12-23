/*
   You are given an undirected graph. You are given an integer n which is the number of nodes in the graph and an array edges, where each edges[i] = [ui, vi] indicates that there is an undirected edge between ui and vi.

   A connected trio is a set of three nodes where there is an edge between every pair of them.

   The degree of a connected trio is the number of edges where one endpoint is in the trio, and the other is not.

   Return the minimum degree of a connected trio in the graph, or -1 if the graph has no connected trios.

    

   Example 1:

Input: n = 6, edges = [[1,2],[1,3],[3,2],[4,1],[5,2],[3,6]]
Output: 3
Explanation: There is exactly one trio, which is [1,2,3]. The edges that form its degree are bolded in the figure above.

Example 2:

Input: n = 7, edges = [[1,3],[4,1],[4,3],[2,5],[5,6],[6,7],[7,5],[2,6]]
Output: 0
Explanation: There are exactly three trios:
1) [1,4,3] with degree 0.
2) [2,5,6] with degree 2.
3) [5,6,7] with degree 2.

 

Constraints:

2 <= n <= 400
edges[i].length == 2
1 <= edges.length <= n 1042.FlowerPlantingWithNoAdjacent 1042.FlowerPlantingWithNoAdjacent.cc 1368.MinimumCosttoMakeatLeastOneValidPathinaGrid 1368.MinimumCosttoMakeatLeastOneValidPathinaGrid.cc 1436.DestinationCity 1436.DestinationCity.cc 1462.CourseScheduleIV 1462.CourseScheduleIV.cc 1466.ReorderRoutestoMakeAllPathsLeadtotheCityZero 1466.ReorderRoutestoMakeAllPathsLeadtotheCityZero.cc 1584.MinCosttoConnectAllPoints 1584.MinCosttoConnectAllPoints.cc 1761.MinimumDegreeofaConnectedTrioinaGraph.cc 2039.TheTimeWhentheNetworkBecomesIdle 2039.TheTimeWhentheNetworkBecomesIdle.cc 207.CourseSchedule 207.CourseSchedule.cc 210.CourseScheduleII 210.CourseScheduleII.cc 2192.AllAncestorsofaNodeinaDirectedAcyclicGraph 2192.AllAncestorsofaNodeinaDirectedAcyclicGraph.cc 2203.MinimumWeightedSubgraphWiththeRequiredPaths 2203.MinimumWeightedSubgraphWiththeRequiredPaths.cc 2285.MaximumTotalImportanceofRoads 2285.MaximumTotalImportanceofRoads.cc 2322.MinimumScoreAfterRemovalsonaTree 2322.MinimumScoreAfterRemovalsonaTree.cc 2360.LongestCycleinaGraph 2360.LongestCycleinaGraph.cc 2368.ReachableNodesWithRestrictions 2368.ReachableNodesWithRestrictions.cc 2440.CreateComponentsWithSameValue 2440.CreateComponentsWithSameValue.cc 2492.MinimumScoreofaPathBetweenTwoCities 2492.MinimumScoreofaPathBetweenTwoCities.cc 2493.DivideNodesIntotheMaximumNumberofGroups 2493.DivideNodesIntotheMaximumNumberofGroups.cc 2497.MaximumStarSumofaGraph 2497.MaximumStarSumofaGraph.cc 2508.AddEdgestoMakeDegreesofAllNodesEven 2508.AddEdgestoMakeDegreesofAllNodesEven.cc 743.NetworkDelayTime 743.NetworkDelayTime.cc 785.IsGraphBipartite 785.IsGraphBipartite.cc 787.CheapestFlightsWithinKStops 787.CheapestFlightsWithinKStops.cc 802.FindEventualSafeStates 802.FindEventualSafeStates.cc head.cc head.h head.o lib.a l.sh makefile (n-1) / 2
1 <= ui, vi <= n
ui != vi
There are no repeated edges.

*/


#include"head.h"
class Solution {
    public:
        int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<bool>> hash(n+1,vector<bool> (n+1,false));
        vector<vector<int>> g(n+1);
        vector<int> indegree(n+1,0);
        for(int i=0;i<edges.size();i++)
        {
            int x=edges[i][0],y=edges[i][1];
            hash[x][y]=hash[y][x]=true;
            g[x].push_back(y);
            g[y].push_back(x);
            indegree[x]++,indegree[y]++;
        }

        int res=INT_MAX;
        for(int i=1;i<=n;i++)
        {
            sort(g[i].begin(),g[i].end());
            for(int j=0;j<g[i].size();j++)
            {
                if(g[i][j]<i)continue;
                for(int k=j+1;k<g[i].size();k++)
                {
                    int x=g[i][j],y=g[i][k];
                    if(hash[x][y]&&res>indegree[i]+indegree[x]+indegree[y]-6)
                        res=indegree[i]+indegree[x]+indegree[y]-6;
                }
            }
        }
        
        return res==INT_MAX?-1:res;
        }
};


int main() 
{
    Solution s;
    vector<vector<int>> v={{1,2},{1,3},{3,2},{4,1},{5,2},{3,6}};
    cout<<s.minTrioDegree(6,v)<<endl;
    v.clear();v={{1,3},{4,1},{4,3},{2,5},{5,6},{6,7},{7,5},{2,6}};
    cout<<s.minTrioDegree(7,v)<<endl;
    return 0;
}
