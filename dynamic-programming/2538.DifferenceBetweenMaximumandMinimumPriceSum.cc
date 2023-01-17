/*
   There exists an undirected and initially unrooted tree with n nodes indexed from 0 to n - 1. You are given the integer n and a 2D integer array edges of length n - 1, where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

   Each node has an associated price. You are given an integer array price, where price[i] is the price of the ith node.

   The price sum of a given path is the sum of the prices of all nodes lying on that path.

   The tree can be rooted at any node root of your choice. The incurred cost after choosing root is the difference between the maximum and minimum price sum amongst all paths starting at root.

   Return the maximum possible cost amongst all possible root choices.

    

   Example 1:

Input: n = 6, edges = [[0,1],[1,2],[1,3],[3,4],[3,5]], price = [9,8,7,6,10,5]
Output: 24
Explanation: The diagram above denotes the tree after rooting it at node 2. The first part (colored in red) shows the path with the maximum price sum. The second part (colored in blue) shows the path with the minimum price sum.
- The first path contains nodes [2,1,3,4]: the prices are [7,8,6,10], and the sum of the prices is 31.
- The second path contains the node [2] with the price [7].
The difference between the maximum and minimum price sum is 24. It can be proved that 24 is the maximum cost.

Example 2:

Input: n = 3, edges = [[0,1],[1,2]], price = [1,1,1]
Output: 2
Explanation: The diagram above denotes the tree after rooting it at node 0. The first part (colored in red) shows the path with the maximum price sum. The second part (colored in blue) shows the path with the minimum price sum.
- The first path contains nodes [0,1,2]: the prices are [1,1,1], and the sum of the prices is 3.
- The second path contains node [0] with a price [1].
The difference between the maximum and minimum price sum is 2. It can be proved that 2 is the maximum cost.

 

Constraints:

1 <= n <= 105
edges.length == n - 1
0 <= ai, bi <= n - 1
edges represents a valid tree.
price.length == n
1 <= price[i] <= 105

*/


#include"head.h"
class Solution {
    public:
        typedef long long ll;
        ll maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        const int m=price.size();
        vector<vector<int>> g(m);
        ll res=0LL;
        for(int i=0;i<edges.size();i++)
        {
            int x=edges[i][0],y=edges[i][1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        dfs(g,price,0,-1,res);
        return res;
        }
        pair<ll,ll> dfs(vector<vector<int>> &g,vector<int> &p,int u,int fa,ll &res)
        {
            ll withLeaf=p[u],noLeaf=0,root=p[u];
            for(int i=0;i<g[u].size();i++)
            {
                int v=g[u][i];
                if(v!=fa)
                {
                    pair<ll,ll> cur=dfs(g,p,v,u,res);
                    res=max(res,max(withLeaf+cur.second,noLeaf+cur.first));
                    withLeaf=max(withLeaf,cur.first+root);
                    noLeaf=max(noLeaf,cur.second+root);
                }
            }

            return {withLeaf,noLeaf};
        }
};


int main() 
{
    Solution s;
    vector<vector<int>> e={{0,1},{1,2},{1,3},{3,4},{3,5}};
    vector<int> p={9,8,7,6,10,5};
    cout<<s.maxOutput(6,e,p)<<endl;
    e.clear();e={{0,1},{1,2}};
    p.clear();p={1,1,1};
    cout<<s.maxOutput(3,e,p)<<endl;
    return 0;
}
