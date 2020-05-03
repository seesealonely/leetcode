/*
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:

Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

Note:

    Then length of the input array is in range [1, 10,000].
    The input array may contain duplicates, so ascending order here means <=.

*/

#include"head.h"

int bruteForce(vector<int> &nums)
{
	int l=nums.size(),r=0;
	for(int i=0;i<nums.size();i++)
	for(int j=i+1;j<nums.size();j++)
		if(nums[i]>nums[j])
		{
			r=max(r,j);	
			l=min(l,i);
		}
	return l<r? r-l+1:0;
}
int usingSort(vector<int> &nums)
{
	vector<int> tmp(nums);	
	sort(tmp.begin(),tmp.end());
	int l=nums.size(),r=0;
	for(int i=0;i<nums.size();i++)
	{
		if(tmp[i]!=nums[i])
		{
		l=min(l,i);
		r=max(r,i);
		}
	}
	return r>l? r-l+1:0;
}

int usingStack(vector<int> &nums)
{
	int l=nums.size(),r=0;
	stack<int> st;
	for(int i=0;i<nums.size();i++)
	{
		while(!st.empty()&&nums[st.top()]>nums[i])
		{
			l=min(l,st.top());
			st.pop();
		}
		st.push(i);
	}
	while(!st.empty()) st.pop();
	for(int i=nums.size()-1;i>=0;i--)
	{
		while(!st.empty()&&nums[st.top()]<nums[i])
		{
			r=max(r,st.top());
			st.pop();
		}
		st.push(i);
	}
	return r>l? r-l+1:0;
}

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
//	return bruteForce(nums);        
//	return usingSort(nums);
	return usingStack(nums);
    }
};
