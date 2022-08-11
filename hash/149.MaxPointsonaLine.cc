/*
   Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.



   Example 1:

Input: points = [[1,1],[2,2],[3,3]]
Output: 3

Example 2:

Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4



Constraints:

1 <= points.length <= 300
points[i].length == 2
-104 <= xi, yi <= 104
All the points are unique.

*/

#define c11
#include"head.h"
class Solution {
    public:
        int maxPoints(vector<vector<int>>& points) {
            if(points.size()<3) return points.size();

            int res=1,n=points.size();
            for(int i=0;i<n;i++)
            {
                unordered_map<long double,int> fre;
                int vertical=1,duplicate=0;
                for(int j=0;j<n;j++)
                {
                    if(i==j) continue;
                    if(points[i][0]==points[j][0])
                    {
                        vertical++;
                        if(points[i][1]==points[j][1])
                            duplicate++;
                    }
                }

                for(int j=0;j<n;j++)
                {
                    if(i==j) continue;
                    long double slope=(long double)(points[i][1]-points[j][1])/(points[i][0]-points[j][0]);
                    if(fre[slope]==0)
                        fre[slope]=2;
                    else
                        fre[slope]++;
                    res=max(res,fre[slope]+duplicate);

                }
                res=max(res,vertical);
            }
            return res;
        }
};


int main() 
{
    Solution s;
    vector<vector<int> > v={{1,1},{2,2},{3,3}};
    cout<<s.maxPoints(v)<<endl;
    v.clear();v={{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    cout<<s.maxPoints(v)<<endl;
    return 0;
}
