/*
   You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

   We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.



   Example 1:

Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2

Example 2:

Input: times = [[1,2,1]], n = 2, k = 1
Output: 1

Example 3:

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1



Constraints:

1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100
All the pairs (ui, vi) are unique. (i.e., no multiple edges.)

*/


#include"head.h"
class Solution {
    public:
        int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,INT_MAX);
        
        dist[k]=0;
        for(int i=1;i<=n;i++)
            for(int j=0;j<times.size();j++)
            {
                int u=times[j][0],v=times[j][1],w=times[j][2];
                if(dist[u]!=INT_MAX&&dist[v]>dist[u]+w)
                    dist[v]=dist[u]+w;
            }

        int res=0;
        for(int i=1;i<=n;i++)
            res=max(res,dist[i]);

        return res==INT_MAX?-1:res;
        }
};


int main() 
{
    Solution s;
    vector<vector<int>> v={{2,1,1},{2,3,1},{3,4,1}};
    cout<<s.networkDelayTime(v,4,2)<<endl;
    v.clear();v={{1,2,1}};
    cout<<s.networkDelayTime(v,2,1)<<endl;
    return 0;
}
