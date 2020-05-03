/*
A rectangle is represented as a list [x1, y1, x2, y2], where (x1, y1) are the coordinates of its bottom-left corner, and (x2, y2) are the coordinates of its top-right corner.

Two rectangles overlap if the area of their intersection is positive.  To be clear, two rectangles that only touch at the corner or edges do not overlap.

Given two (axis-aligned) rectangles, return whether they overlap.

Example 1:

Input: rec1 = [0,0,2,2], rec2 = [1,1,3,3]
Output: true

Example 2:

Input: rec1 = [0,0,1,1], rec2 = [1,0,2,1]
Output: false

Notes:

    Both rectangles rec1 and rec2 are lists of 4 integers.
    All coordinates in rectangles will be between -10^9 and 10^9.
*/

#include"836.RectangleOverlap.h"

int main()
{
	int vvv1[]={0,0,1,1};
	int vvv2[]={1,0,2,1};
	int vv1[]={0,0,1,1};
	int vv2[]={1,0,2,1};
	vector<int> v1(vv1,vv1+4),v2(vv2,vv2+4),v3(vvv1,vvv1+4),v4(vvv2,vvv2+4);
	Solution s;
	cout<<s.isRectangleOverlap(v3,v4)<<endl;
	cout<<s.isRectangleOverlap(v1,v2)<<endl;
	return 0;
}
