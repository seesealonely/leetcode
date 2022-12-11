/*
There is an undirected graph consisting of n nodes numbered from 0 to n - 1. You are given a 0-indexed integer array vals of length n where vals[i] denotes the value of the ith node.

You are also given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

A star graph is a subgraph of the given graph having a center node containing 0 or more neighbors. In other words, it is a subset of edges of the given graph such that there exists a common node for all edges.

The image below shows star graphs with 3 and 4 neighbors respectively, centered at the blue node.

The star sum is the sum of the values of all the nodes present in the star graph.

Given an integer k, return the maximum star sum of a star graph containing at most k edges.

 

Example 1:

Input: vals = [1,2,3,4,10,-10,-20], edges = [[0,1],[1,2],[1,3],[3,4],[3,5],[3,6]], k = 2
Output: 16
Explanation: The above diagram represents the input graph.
The star graph with the maximum star sum is denoted by blue. It is centered at 3 and includes its neighbors 1 and 4.
It can be shown it is not possible to get a star graph with a sum greater than 16.

Example 2:

Input: vals = [-5], edges = [], k = 0
Output: -5
Explanation: There is only one possible star graph, which is node 0 itself.
Hence, we return -5.

 

Constraints:

    n == vals.length
    1 <= n <= 105
    -104 <= vals[i] <= 104
    0 <= edges.length <= min(n * (n - 1) / 2, 105)
    edges[i].length == 2
    0 <= ai, bi <= n - 1
    ai != bi
    0 <= k <= n - 1

*/


#include"head.h"
class Solution {
    public:
        int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
            const int n=vals.size();
            vector<vector<int>> g(n);
            for(int i=0;i<edges.size();i++)
            {
                int x=edges[i][0],y=edges[i][1];
                g[x].push_back(y);
                g[y].push_back(x);
            }

            for(int i=0;i<n;i++)
                sort(g[i].begin(),g[i].end(),[&](const int x,const int y)
                {
                    return vals[x]>vals[y];
                });
            int res=INT_MIN;
            for(int i=0;i<n;i++)
            {
                int sum=vals[i]+solve(g,vals,i,k);
                res=max(res,sum);
            }
            return res;
        }
        int solve(vector<vector<int>> &g,vector<int> &vals,int v,int k)
        {
            int sum=0,cnt=0;
            for(int i=0;i<g[v].size();i++)
            {
                if(vals[g[v][i]]<=0) break;
                if(++cnt>k) break;
                sum+=vals[g[v][i]];
            }
            return sum;
        }
    private:
};


int main() 
{
    Solution s;
    vector<int> v={1,2,3,4,10,-10,-20};
    vector<vector<int>> e={{0,1},{1,2},{1,3},{3,4},{3,5},{3,6}};
    cout<<s.maxStarSum(v,e,2)<<endl;

    v.clear();v={-5};
    e.clear();
    cout<<s.maxStarSum(v,e,0)<<endl;
    v.clear();v={-1,0};
    e.clear();
    cout<<s.maxStarSum(v,e,1)<<endl;
    v.clear();v={1,-8,0};
    e.clear();e={{1,0},{2,1}};
    cout<<s.maxStarSum(v,e,2)<<endl;
    v.clear();v={6,-27,-44,-64,59,-7,21,-57};
    e.clear();e={{7,5},{4,0},{4,3},{6,1},{0,2},{7,3},{0,3},{0,5},{1,3},{4,2},{3,6},{0,1},{2,1},{5,4},{5,6},{5,2},{6,4},{5,1},{6,0},{6,7},{0,7},{3,5}};
    cout<<s.maxStarSum(v,e,5)<<endl;
    return 0;
}
