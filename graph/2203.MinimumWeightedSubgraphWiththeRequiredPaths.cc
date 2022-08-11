/*
   You are given an integer n denoting the number of nodes of a weighted directed graph. The nodes are numbered from 0 to n - 1.

   You are also given a 2D integer array edges where edges[i] = [fromi, toi, weighti] denotes that there exists a directed edge from fromi to toi with weight weighti.

   Lastly, you are given three distinct integers src1, src2, and dest denoting three distinct nodes of the graph.

   Return the minimum weight of a subgraph of the graph such that it is possible to reach dest from both src1 and src2 via a set of edges of this subgraph. In case such a subgraph does not exist, return -1.

   A subgraph is a graph whose vertices and edges are subsets of the original graph. The weight of a subgraph is the sum of weights of its constituent edges.



   Example 1:

Input: n = 6, edges = [[0,2,2],[0,5,6],[1,0,3],[1,4,5],[2,1,1],[2,3,3],[2,3,4],[3,4,2],[4,5,1]], src1 = 0, src2 = 1, dest = 5
Output: 9
Explanation:
The above figure represents the input graph.
The blue edges represent one of the subgraphs that yield the optimal answer.
Note that the subgraph [[1,0,3],[0,5,6]] also yields the optimal answer. It is not possible to get a subgraph with less weight satisfying all the constraints.

Example 2:

Input: n = 3, edges = [[0,1,1],[2,1,1]], src1 = 0, src2 = 1, dest = 2
Output: -1
Explanation:
The above figure represents the input graph.
It can be seen that there does not exist any path from node 1 to node 2, hence there are no subgraphs satisfying all the constraints.



Constraints:

3 <= n <= 105
0 <= edges.length <= 105
edges[i].length == 3
0 <= fromi, toi, src1, src2, dest <= n - 1
fromi != toi
src1, src2, and dest are pairwise distinct.
1 <= weight[i] <= 105

*/


#include"head.h"
class Solution {
    public:
        long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {

        vector<vector<pair<int,int>>> g1(n),g2(n);
        for(int i=0;i<edges.size();i++)
        {
            int x=edges[i][0],y=edges[i][1],w=edges[i][2];
            g1[x].push_back({y,w});
            g2[y].push_back({x,w});
        }

        vector<long long> dx=shortestPath(n,g1,src1);
        vector<long long> dy=shortestPath(n,g1,src2);
        vector<long long> dt=shortestPath(n,g2,dest);

        long long res=LONG_LONG_MAX/3;
        for(int i=0;i<n;i++)
            res=min(res,dx[i]+dy[i]+dt[i]);

        if(res==LONG_LONG_MAX/3)
            return -1;

        return res;

        }
        vector<long long> shortestPath(int n,const vector<vector<pair<int,int>>> &g,int s)
        {

            priority_queue<pair<long long,int>> heap;
            vector<long long> dis(n,LONG_LONG_MAX/3);

            heap.push({0,s});
            dis[s]=0;
            while(!heap.empty())
            {
                auto top=heap.top();heap.pop();

                int x=top.second;
                long long d=-top.first;

                if(d!=dis[x])
                    continue;

                for(int i=0;i<g[x].size();i++)
                {
                    int y=g[x][i].first,w=g[x][i].second;
                    if(dis[y]>dis[x]+w)
                    {
                        dis[y]=dis[x]+w;
                        heap.push({-dis[y],y});
                    }
                }
            }

            return dis;

        }
};


int main() 
{
    Solution s;
    vector<vector<int>> v={{0,2,2},{0,5,6},{1,0,3},{1,4,5},{2,1,1},{2,3,3},{2,3,4},{3,4,2},{4,5,1}};
    cout<<s.minimumWeight(6,v,0,1,5)<<endl;
    v.clear();v={{0,1,1},{2,1,1}};
    cout<<s.minimumWeight(3,v,0,1,2)<<endl;
    return 0;
}
