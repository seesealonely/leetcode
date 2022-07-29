/*
   You are given an array of points in the X-Y plane points where points[i] = [xi, yi].

   Return the minimum area of any rectangle formed from these points, with sides not necessarily parallel to the X and Y axes. If there is not any such rectangle, return 0.

   Answers within 10-5 of the actual answer will be accepted.



   Example 1:

Input: points = [[1,2],[2,1],[1,0],[0,1]]
Output: 2.00000
Explanation: The minimum area rectangle occurs at [1,2],[2,1],[1,0],[0,1], with an area of 2.

Example 2:

Input: points = [[0,1],[2,1],[1,1],[1,0],[2,0]]
Output: 1.00000
Explanation: The minimum area rectangle occurs at [1,0],[1,1],[2,1],[2,0], with an area of 1.

Example 3:

Input: points = [[0,3],[1,2],[3,1],[1,3],[2,1]]
Output: 0
Explanation: There is no possible rectangle to form from these points.



Constraints:

1 <= points.length <= 50
points[i].length == 2
0 <= xi, yi <= 4 * 104
All the given points are unique.

*/

#define c11
#include"head.h"
class Solution {
    public:
        double minAreaFreeRect(vector<vector<int>>& points) {
        const int n=points.size();
        unordered_set<string> h;
        
        for(int i=0;i<n;i++)
            h.insert(to_string(points[i][0])+" "+to_string(points[i][1]));

        double res=40001*40001;

        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                for(int k=j+1;k<n;k++)
                {
                    compute(points[i],points[j],points[k],res,h);
                    compute(points[j],points[i],points[k],res,h);
                    compute(points[k],points[i],points[j],res,h);
                }
        return res==40001*40001?0:res;
        }
        void compute(vector<int> &a,vector<int> &b,vector<int> &c,double &res,unordered_set<string> &h)
        {
            vector<int> c1(2),c2(2),c3(2);

            c1[0]=a[0]-b[0];
            c1[1]=a[1]-b[1];

            c2[0]=a[0]-c[0];
            c2[1]=a[1]-c[1];
            if(c1[0]*c2[0]+c1[1]*c2[1]==0)
            {
                c3[0]=c[0]-c1[0];
                c3[1]=c[1]-c1[1];
                if(h.find(to_string(c3[0])+" "+to_string(c3[1]))!=h.end())
                    res=min(res,sqrt(c1[0]*c1[0]+c1[1]*c1[1])*sqrt(c2[0]*c2[0]+c2[1]*c2[1]));
            }
        }
};


int main() 
{
    Solution s;
    vector<vector<int>> v={{1,2},{2,1},{1,0},{0,1}};
    cout<<s.minAreaFreeRect(v)<<endl;
    v.clear();v={{0,1},{2,1},{1,1},{1,0},{2,0}};
    cout<<s.minAreaFreeRect(v)<<endl;
    v.clear();v={{0,3},{1,2},{3,1},{1,3},{2,1}};
    cout<<s.minAreaFreeRect(v)<<endl;
    return 0;
}
