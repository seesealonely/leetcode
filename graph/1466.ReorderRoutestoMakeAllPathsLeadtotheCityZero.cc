/*
   There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

   Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.

   This year, there will be a big event in the capital (city 0), and many people want to travel to this city.

   Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.

   It's guaranteed that each city can reach city 0 after reorder.



   Example 1:

Input: n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
Output: 3
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).

Example 2:

Input: n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
Output: 2
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).

Example 3:

Input: n = 3, connections = [[1,0],[2,0]]
Output: 0



Constraints:

2 <= n <= 5 1436.DestinationCity 1436.DestinationCity.cc 1466.ReorderRoutestoMakeAllPathsLeadtotheCityZero.cc 1584.MinCosttoConnectAllPoints 1584.MinCosttoConnectAllPoints.cc head.cc head.h head.o lib.a l.sh makefile 104
connections.length == n - 1
connections[i].length == 2
0 <= ai, bi <= n - 1
ai != bi

*/


#include"head.h"
class Solution {
    public:
        int minReorder(int n, vector<vector<int>>& connections) {
            vector<vector<pair<int,bool>>> g(n);
            for(int i=0;i<connections.size();i++)
            {
                vector<int> c=connections[i];
                g[c[0]].push_back({c[1],true});
                g[c[1]].push_back({c[0],false});
            }

            vector<bool> vis(n,false);vis[0]=true;
            queue<int> q;q.push(0);
            int res=0;
            while(!q.empty())
            {
                int i=q.front();q.pop();
                for(int j=0;j<g[i].size();j++)
                {
                    if(!vis[g[i][j].first])
                    {
                        vis[g[i][j].first]=true;
                        res+=g[i][j].second;
                        q.push(g[i][j].first);
                    }
                }
            }
            return res;
        }
};


int main() 
{
    Solution s;
    vector<vector<int>> v={{0,1},{1,3},{2,3},{4,0},{4,5}};
    cout<<s.minReorder(6,v)<<endl;
    v.clear();v={{1,0},{1,2},{3,2},{3,4}};
    cout<<s.minReorder(5,v)<<endl;
    v.clear();v={{1,0},{2,0}};
    cout<<s.minReorder(3,v)<<endl;
    return 0;
}
