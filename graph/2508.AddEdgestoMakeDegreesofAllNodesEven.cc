/*

   There is an undirected graph consisting of n nodes numbered from 1 to n. You are given the integer n and a 2D array edges where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi. The graph can be disconnected.

   You can add at most two additional edges (possibly none) to this graph so that there are no repeated edges and no self-loops.

   Return true if it is possible to make the degree of each node in the graph even, otherwise return false.

   The degree of a node is the number of edges connected to it.

    

   Example 1:

Input: n = 5, edges = [[1,2],[2,3],[3,4],[4,2],[1,4],[2,5]]
Output: true
Explanation: The above diagram shows a valid way of adding an edge.
Every node in the resulting graph is connected to an even number of edges.

Example 2:

Input: n = 4, edges = [[1,2],[3,4]]
Output: true
Explanation: The above diagram shows a valid way of adding two edges.

Example 3:

Input: n = 4, edges = [[1,2],[1,3],[1,4]]
Output: false
Explanation: It is not possible to obtain a valid graph with adding at most 2 edges.

 

Constraints:

3 <= n <= 105
2 <= edges.length <= 105
edges[i].length == 2
1 <= ai, bi <= n
ai != bi
There are no repeated edges.

*/

#define c11
#include"head.h"
class Solution {
    public:
        bool isPossible(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> g(n);
        vector<int> degree(n,0);

        for(int i=0;i<edges.size();i++)
        {
            int x=edges[i][0]-1,y=edges[i][1]-1;
            g[x].insert(y);
            g[y].insert(x);

            degree[x]++;
            degree[y]++;
        }

        vector<int> odd;
        for(int i=0;i<n;i++)
            if(degree[i]%2)
                odd.push_back(i);

        if(odd.empty())
            return true;

        if(odd.size()>4)
            return false;

        if(odd.size()==2)
        {
            int x=odd[0],y=odd[1];
            if(g[x].find(y)==g[x].end())
                return true;

            for(int i=0;i<n;i++)
            {
                if(i==x||i==y)
                    continue;
                if(g[i].find(x)!=g[i].end())
                    continue;
                if(g[i].find(y)!=g[i].end())
                    continue;

                return true;
            }
            return false;
        }

        else if(odd.size()==3)
            return false;

        else
        {
            int x0=odd[0],x1=odd[1],x2=odd[2],x3=odd[3];
            if(g[x0].find(x1)==g[x0].end()&&g[x2].find(x3)==g[x2].end())
                return true;
            if(g[x0].find(x2)==g[x0].end()&&g[x1].find(x3)==g[x1].end())
                return true;
            if(g[x0].find(x3)==g[x0].end()&&g[x2].find(x3)==g[x2].end())
                return true;
        }

        return false;
        }
};


int main() 
{
    Solution s;
    vector<vector<int>> v={{1,2},{2,3},{3,4},{4,2},{1,4},{2,5}};
    cout<<s.isPossible(5,v)<<endl;
    v.clear();v={{1,2},{3,4}};
    cout<<s.isPossible(4,v)<<endl;
    v.clear();v={{1,2},{1,3},{1,4}};
    cout<<s.isPossible(4,v)<<endl;
    return 0;
}
