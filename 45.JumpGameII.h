/*
 Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps. 
*/
/*
 For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.
*/
#include"head.h"
class Solution {//greedy
public:
    int jump(vector<int>& nums) {
	int res=0,curEnd=0,curFarthest=0; 	       
		for(int i=0;i<nums.size()-1;++i)
		{
			curFarthest=max(curFarthest,i+nums[i]);
			if(i==curEnd)
			{
			++res;
			curEnd=curFarthest;
			}
		}
		return res;
    }
};
/*
class Solution {//BFS
public:
    int jump(vector<int>& nums) {
	int maxIndex=nums.size()-1,res=0,start=0,end=0,farthest;
	while(end<maxIndex)
	{
		++res;
	farthest=end+1;
		for(int i=start;i<=end;i++)
		{
			if(i+nums[i]>=maxIndex) return res;
			farthest=max(farthest,i+nums[i]);
		}	
		start=end+1;
		end=farthest;
	}
		return res;
    }
};
*/
