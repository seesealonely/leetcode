/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.



Example 1:

Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Example 2:

Input: heights = [2,4]
Output: 4



Constraints:

1 <= heights.length <= 105
0 <= heights[i] <= 104

*/
#include"84.LargestRectangleinHistogram.h"
int main() 
 {
 	 Solution s;
	 vector<int> v={2,1,5,6,2,3};
 	 cout<<s.largestRectangleArea(v)<<endl;
	 v.clear();v={2,4};
 	 cout<<s.largestRectangleArea(v)<<endl;
	 v.clear();v={2,1,2};
 	 cout<<s.largestRectangleArea(v)<<endl;
 	 return 0;
 }
