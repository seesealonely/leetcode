/*
   There is an undirected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.

   You are given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree. You are also given an integer array restricted which represents restricted nodes.

   Return the maximum number of nodes you can reach from node 0 without visiting a restricted node.

   Note that node 0 will not be a restricted node.



   Example 1:

Input: n = 7, edges = [[0,1],[1,2],[3,1],[4,0],[0,5],[5,6]], restricted = [4,5]
Output: 4
Explanation: The diagram above shows the tree.
We have that [0,1,2,3] are the only nodes that can be reached from node 0 without visiting a restricted node.

Example 2:

Input: n = 7, edges = [[0,1],[0,2],[0,5],[0,4],[3,2],[6,5]], restricted = [4,2,1]
Output: 3
Explanation: The diagram above shows the tree.
We have that [0,5,6] are the only nodes that can be reached from node 0 without visiting a restricted node.



Constraints:

2 <= n <= 105
edges.length == n - 1
edges[i].length == 2
0 <= ai, bi < n
ai != bi
edges represents a valid tree.
1 <= restricted.length < n
1 <= restricted[i] < n
All the values of restricted are unique.

*/

#define c11
#include"head.h"
class Solution {
    public:
        int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {

            for(int i=0;i<restricted.size();i++)
                restrict.insert(restricted[i]);

            g.resize(n);
            for(int i=0;i<edges.size();i++)
            {
                int u=edges[i][0],v=edges[i][1];
                g[u].push_back(v);
                g[v].push_back(u);
            }

            int res=0;
            calc(0,-1,res);
            return res;
        }
       void calc(int u,int father,int &res)
        {
            res++;
            for(int i=0;i<g[u].size();i++)
            {
                int v=g[u][i];
                if(v!=father&&restrict.find(v)==restrict.end())
                    calc(v,u,res);
            }
        }
    private:
        unordered_set<int> restrict;
        vector<vector<int>> g;
};


int main() 
{
    Solution s;
//    vector<vector<int>> e={{0,1},{1,2},{3,1},{4,0},{0,5},{5,6}};
 //   vector<int> r={4,5};
//    cout<<s.reachableNodes(7,e,r)<<endl;
    vector<vector<int>> e;//={{0,1},{1,2},{3,1},{4,0},{0,5},{5,6}};
    vector<int> r;//={4,5};
    e.clear();e={{0,1},{0,2},{0,5},{0,4},{3,2},{6,5}};
    r.clear();r={4,2,1};
    cout<<s.reachableNodes(7,e,r)<<endl;
    return 0;
}
