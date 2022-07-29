/*
   You have n gardens, labeled from 1 to n, and an array paths where paths[i] = [xi, yi] describes a bidirectional path between garden xi to garden yi. In each garden, you want to plant one of 4 types of flowers.

   All gardens have at most 3 paths coming into or leaving it.

   Your task is to choose a flower type for each garden such that, for any two gardens connected by a path, they have different types of flowers.

   Return any such a choice as an array answer, where answer[i] is the type of flower planted in the (i+1)th garden. The flower types are denoted 1, 2, 3, or 4. It is guaranteed an answer exists.



   Example 1:

Input: n = 3, paths = [[1,2],[2,3],[3,1]]
Output: [1,2,3]
Explanation:
Gardens 1 and 2 have different types.
Gardens 2 and 3 have different types.
Gardens 3 and 1 have different types.
Hence, [1,2,3] is a valid answer. Other valid answers include [1,2,4], [1,4,2], and [3,2,1].

Example 2:

Input: n = 4, paths = [[1,2],[3,4]]
Output: [1,2,1,2]

Example 3:

Input: n = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
Output: [1,2,3,4]



Constraints:

1 <= n <= 104
0 <= paths.length <= 2 * 104
paths[i].length == 2
1 <= xi, yi <= n
xi != yi
Every garden has at most 3 paths coming into or leaving it.

*/

#define c11
#include"head.h"
class Solution {
    public:
        vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> g(n);
        for(int i=0;i<paths.size();i++)
        {
            int u=paths[i][0]-1,v=paths[i][1]-1;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> res(n,0);
        for(int i=0;i<n;i++)
        {
            vector<bool> vis(5,false);

            for(int j=0;j<g[i].size();j++)
                vis[res[g[i][j]]]=true;

            for(int j=1;j<=4;j++)
            {
                   if(vis[j]==false)
                   {
                       res[i]=j;
                       break;
                   }
            }
        }
        
        return res;
        }
};


int main() 
{
    Solution s;
    vector<vector<int>> v={{1,2},{2,3},{3,1}};
    show(s.gardenNoAdj(3,v));
    v.clear();v={{1,2},{3,4}};
    show(s.gardenNoAdj(4,v));
    v.clear();v={{1,2},{2,3},{3,4},{4,1},{1,3},{2,4}};
    show(s.gardenNoAdj(4,v));
    return 0;
}
