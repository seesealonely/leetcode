/*
   There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

   You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.



   Example 1:

Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.

Example 2:

Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.

Example 3:

Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph is shown above.
The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.



Constraints:

1 <= n <= 100
0 <= flights.length <= (n * (n - 1) / 2)
flights[i].length == 3
0 <= fromi, toi < n
fromi != toi
1 <= pricei <= 104
There will not be any multiple flights between two cities.
0 <= src, dst, k < n
src != dst

*/


#include"head.h"
class Solution {
    public:
        int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> g(n);

        for(int i=0;i<flights.size();i++)
            g[flights[i][0]].push_back({flights[i][1],flights[i][2]});

        k++;
        vector<vector<int>> dist(k+1,vector<int>(n,INT_MAX-10000));

        dist[0][src]=0;
        for(int i=1;i<=k;i++)
            for(int v=0;v<n;v++)
                for(int j=0;j<g[v].size();j++)
                    dist[i][g[v][j].first]=min(dist[i][g[v][j].first],dist[i-1][v]+g[v][j].second);

        int res=INT_MAX-10000;
        for(int i=0;i<=k;i++)
            res=min(res,dist[i][dst]);

        return res==INT_MAX-10000?-1:res;
        }
};


int main() 
{
    Solution s;
    vector<vector<int>> v={{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    cout<<s.findCheapestPrice(4,v,0,3,1)<<endl;
    v.clear();v={{0,1,100},{1,2,100},{0,2,500}};
    cout<<s.findCheapestPrice(3,v,0,2,1)<<endl;
    v.clear();v={{0,1,100},{1,2,100},{0,2,500}};
    cout<<s.findCheapestPrice(3,v,0,2,0)<<endl;
    return 0;
}
