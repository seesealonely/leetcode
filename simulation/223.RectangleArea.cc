/*
   Given the coordinates of two rectilinear rectangles in a 2D plane, return the total area covered by the two rectangles.

   The first rectangle is defined by its bottom-left corner (ax1, ay1) and its top-right corner (ax2, ay2).

   The second rectangle is defined by its bottom-left corner (bx1, by1) and its top-right corner (bx2, by2).



   Example 1:
   Rectangle Area

Input: ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2
Output: 45

Example 2:

Input: ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -2, by1 = -2, bx2 = 2, by2 = 2
Output: 16



Constraints:

-104 <= ax1, ay1, ax2, ay2, bx1, by1, bx2, by2 <= 104

*/


#include"head.h"
class Solution {
    public:
        int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area=abs(ax1-ax2)*abs(ay1-ay2)+abs(bx1-bx2)*abs(by1-by2);

        int x1=max(ax1,bx1);
        int y1=max(ay1,by1);
        int x2=min(ax2,bx2);
        int y2=min(ay2,by2);

        int cover=0;
        if(x1<x2&&y1<y2)
            cover=abs(x1-x2)*abs(y1-y2);

        return area-cover;
        }
};


int main() 
{
    Solution s;
    cout<<s.computeArea(-3,0,3,4,0,-1,9,2)<<endl;
    cout<<s.computeArea(-2,-2,2,2,-2,-2,2,2)<<endl;
    return 0;
}
