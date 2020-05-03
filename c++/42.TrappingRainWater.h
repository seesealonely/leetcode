/*
 Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6. 
The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
*/

#include"head.h"
class Solution {
public:
    int trap(vector<int>& height) {
        
    return usingStack(height) ;
    }
    int usingStack(vector<int>& height) {
       if(height.size()==0) return 0; 
	stack<int> st;
	int res=0;
	for(int i=0;i<height.size();)
	{
		if(st.empty()||height[i]<=height[st.top()])
		st.push(i++);
		else
		{
			int bottom=st.top();st.pop();
			res+=st.empty()?0:(min(height[st.top()],height[i])-height[bottom])*(i-st.top()-1);
		}
	}
	return res;
    }
};
