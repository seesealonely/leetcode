/*
   Given a 2D integer array circles where circles[i] = [xi, yi, ri] represents the center (xi, yi) and radius ri of the ith circle drawn on a grid, return the number of lattice points that are present inside at least one circle.

Note:

A lattice point is a point with integer coordinates.
Points that lie on the circumference of a circle are also considered to be inside it.



Example 1:

Input: circles = [[2,2,1]]
Output: 5
Explanation:
The figure above shows the given circle.
The lattice points present inside the circle are (1, 2), (2, 1), (2, 2), (2, 3), and (3, 2) and are shown in green.
Other points such as (1, 1) and (1, 3), which are shown in red, are not considered inside the circle.
Hence, the number of lattice points present inside at least one circle is 5.

Example 2:

Input: circles = [[2,2,2],[3,4,1]]
Output: 16
Explanation:
The figure above shows the given circles.
There are exactly 16 lattice points which are present inside at least one circle.
Some of them are (0, 2), (2, 0), (2, 4), (3, 2), and (4, 4).



Constraints:

1 <= circles.length <= 200
circles[i].length == 3
1 <= xi, yi <= 100
1 <= ri <= min(xi, yi)

*/


#include"head.h"
class Solution {
    public:
        int countLatticePoints(vector<vector<int>>& circles) {
        int res=0,maxx=0,maxy=0;

        for(int i=0;i<circles.size();i++)
        {
            maxx=max(maxx,circles[i][0]+circles[i][2]);
            maxy=max(maxy,circles[i][1]+circles[i][2]);
        }
        for(int x=0;x<=maxx;x++)
            for(int y=0;y<=maxy;y++)
            {
                for(int i=0;i<circles.size();i++)
                {
                    if(dis(x,y,circles[i][0],circles[i][1],circles[i][2]))
                    {
                        res++;
                        break;
                    }
                }
            }
        return res;
        }
        inline bool dis(int x,int y,int x0,int y0,int r)
        {
            return (x-x0)*(x-x0)+(y-y0)*(y-y0)<=r*r;
        }
};


int main() 
{
    Solution s;
    vector<vector<int> > v={{2,2,1}};
    cout<<s.countLatticePoints(v)<<endl;
    v.clear();v={{2,2,2},{3,4,1}};
    cout<<s.countLatticePoints(v)<<endl;
    return 0;
}
