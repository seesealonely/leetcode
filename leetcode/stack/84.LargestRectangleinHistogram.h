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
#include"head.h"
class Solution {
	public:
		int largestRectangleArea(vector<int>& heights) {
			int res=0,n=heights.size(),top=0;
			stack<int> stl,str; //record index
			vector<int> left(n,0),right(n,0);
			for(int i=0;i<n;i++)
			{
				while(!stl.empty()&&heights[stl.top()]>=heights[i])
					stl.pop();
				left[i]=stl.empty()?-1:stl.top();
				stl.push(i);
			}

			for(int i=n-1;i>=0;i--)
			{
				while(!str.empty()&&heights[str.top()]>=heights[i])
					str.pop();
				right[i]=str.empty()?n:str.top();
				str.push(i);
			}

			for(int i=0;i<n;i++)
			{
				res=max(res,heights[i]*(right[i]-left[i]-1));
			}
			return res;
		}
};
