/*
Given a non-empty integer array, find the minimum number of moves required to make all array elements equal, where a move is incrementing a selected element by 1 or decrementing a selected element by 1.

You may assume the array's length is at most 10,000.

Example:

Input:
[1,2,3]

Output:
2

Explanation:
Only two moves are needed (remember each move increments or decrements one element):

[1,2,3]  =>  [2,2,3]  =>  [2,2,2]

*/
#include"head.h"

class Solution {
public:
    int minMoves2(vector<int>& nums) {
 	int sum=0;
	int median=quickSelect(nums,nums.size()/2+1,0,nums.size()-1);
	for(int i=0;i<nums.size();++i) sum+=abs(nums[i]-median);
	return sum;
    }
	int quickSelect(vector<int> &nums,int m,int start,int end)
	{
		int l=start,r=end;
		int pivot=nums[(l+r)/2];
		while(l<=r)
		{
			while(nums[l]<pivot) l++;
			while(nums[r]>pivot) r--;
			if(l>=r) break;
			swap(nums,l++,r--);
		}
		if(l-start+1>m)  return quickSelect(nums,m,start,l-1);
		else if(l-start+1==m) return nums[l];
		return quickSelect(nums,m,l+1,end);
	}
	void swap(vector<int> &nums,int i,int j)
	{
		int temp=nums[i];
		nums[i]=nums[j];
		nums[j]=temp;
	}
};
