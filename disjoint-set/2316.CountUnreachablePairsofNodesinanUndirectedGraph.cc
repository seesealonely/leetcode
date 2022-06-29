/*
   You are given an integer n. There is an undirected graph with n nodes, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

   Return the number of pairs of different nodes that are unreachable from each other.



   Example 1:

Input: n = 3, edges = [[0,1],[0,2],[1,2]]
Output: 0
Explanation: There are no pairs of nodes that are unreachable from each other. Therefore, we return 0.

Example 2:

Input: n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
Output: 14
Explanation: There are 14 pairs of nodes that are unreachable from each other:
[[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]].
Therefore, we return 14.



Constraints:

1 <= n <= 105
0 <= edges.length <= 2 * 105
edges[i].length == 2
0 <= ai, bi < n
ai != bi
There are no repeated edges.

*/


#include"head.h"
class Solution {
    public:
        long long countPairs(int n, vector<vector<int>>& edges) {
        #define ll long long
        uf(n);
        for(int i=0;i<edges.size();i++)
            merge(edges[i][0],edges[i][1]);

        ll  res=(ll)n*(n-1)/2;

        for(int i=0;i<n;i++)
            if(i==find(i))
                res-=(ll)size[find(i)]*(size[find(i)]-1)/2;

        return res;
        }

        void uf(int n)
        {
            p.resize(n); size.resize(n);
            for(int i=0;i<n;i++)
                p[i]=i,size[i]=1;
        }

        int find(int c)
        {
            if(p[c]!=c)
                return p[c]=find(p[c]);
            return c;
        }

        void merge(int u,int v)
        {
            int pu=find(u),pv=find(v);

            if(pu==pv)
                return;

            if(size[pu]<size[pv])
                p[pu]=pv,size[pv]+=size[pu];
            else
                p[pv]=pu,size[pu]+=size[pv];

        }
    private:
        vector<int> p;
        vector<int> size;
};


int main() 
{
    Solution s;
    vector<vector<int>> v={{0,1},{0,2},{1,2}};
    cout<<s.countPairs(3,v)<<endl;
    v.clear();v={{0,2},{0,5},{2,4},{1,6},{5,4}};
    cout<<s.countPairs(7,v)<<endl;
    return 0;
}
