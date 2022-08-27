/*
   You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

   The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

   Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.



   Example 1:

Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation:

We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.

Example 2:

Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18



Constraints:

1 <= points.length <= 1000
-106 <= xi, yi <= 106
All pairs (xi, yi) are distinct.

*/


#include"head.h"
class Solution {
    public:
        int minCostConnectPoints(vector<vector<int>>& points) {
        const int n=points.size();
        vector<int> distance(n,INT_MAX); distance[0]=0;
        vector<bool> vis(n,false);

        int res=0;
        for(int i=0;i<n;i++)
        {
            int mx=INT_MAX;
            int idx=-1;
            for(int j=0;j<n;j++)
                if(vis[j]==false&&mx>distance[j])
                {
                    mx=distance[j];
                    idx=j;
                }

            vis[idx]=true;
            res+=mx;
            for(int j=0;j<n;j++)
                distance[j]=min(distance[j],calc(points[idx],points[j]));
        }
        return res;
        }
        int calc(vector<int> &x,vector<int> &y)
        {
            return abs(x[0]-y[0])+abs(x[1]-y[1]);
        }
};


int main() 
{
    Solution s;
    vector<vector<int>> v={{0,0},{2,2},{3,10},{5,2},{7,0}};
    cout<<s.minCostConnectPoints(v)<<endl;
    v.clear();v={{3,12},{-2,5},{-4,1}};
    cout<<s.minCostConnectPoints(v)<<endl;
    v.clear();v={{0,0},{1,1},{1,0},{-1,1}};
    cout<<s.minCostConnectPoints(v)<<endl;
    v.clear();v={{-1000000,-1000000},{1000000,1000000}};
    cout<<s.minCostConnectPoints(v)<<endl;
    v.clear();v={{0,0}};
    cout<<s.minCostConnectPoints(v)<<endl;
    return 0;
}
