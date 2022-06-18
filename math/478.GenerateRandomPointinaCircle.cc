/*
   Given the radius and the position of the center of a circle, implement the function randPoint which generates a uniform random point inside the circle.

   Implement the Solution class:

   Solution(double radius, double x_center, double y_center) initializes the object with the radius of the circle radius and the position of the center (x_center, y_center).
   randPoint() returns a random point inside the circle. A point on the circumference of the circle is considered to be in the circle. The answer is returned as an array [x, y].



   Example 1:

   Input
   ["Solution", "randPoint", "randPoint", "randPoint"]
   [[1.0, 0.0, 0.0], [], [], []]
   Output
   [null, [-0.02493, -0.38077], [0.82314, 0.38945], [0.36572, 0.17248]]

   Explanation
   Solution solution = new Solution(1.0, 0.0, 0.0);
   solution.randPoint(); // return [-0.02493, -0.38077]
   solution.randPoint(); // return [0.82314, 0.38945]
   solution.randPoint(); // return [0.36572, 0.17248]



Constraints:

0 < radius <= 108
-107 <= x_center, y_center <= 107
At most 3 * 104 calls will be made to randPoint.

*/


#include"head.h"
#include<random>
#include<numbers>
class Solution {
    public:
        double r,x,y;
        mutable mt19937 re;
        Solution(double radius, double x_center, double y_center) {
            r=radius,x=x_center,y=y_center;
        }

        vector<double> randPoint() {
            uniform_real_distribution<double> ur(0,1),up(0,2*acos(-1.0));
            const double len=r*sqrt(ur(re)),ang=up(re);
                return {x+len*cos(ang),y+len*sin(ang)};
        }
};


int main() 
{
    Solution s(1.0,0.0,0.0);
    show(s.randPoint());
    show(s.randPoint());
    show(s.randPoint());
    return 0;
}
