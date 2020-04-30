/*
Given an integer array, return the k-th smallest distance among all the pairs. The distance of a pair (A, B) is defined as the absolute difference between A and B.

Example 1:

Input:
nums = [1,3,1]
k = 1
Output: 0 
Explanation:
Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.

Note:

    2 <= len(nums) <= 10000.
    0 <= nums[i] < 1000000.
    1 <= k <= len(nums) * (len(nums) - 1) / 2.

*/

#include"head.h"

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
	sort(nums.begin(),nums.end());
	show(nums);
	int l=nums[1]-nums[0];
	for(int i=0;i<nums.size()-1;i++)
	l=min(l,nums[i+1]-nums[i]);
	int r=nums[nums.size()-1]-nums[0];
	while(l<r)
	{
		int mid=(l+r)/2;
		if(countPair1(nums,mid)<k)
		l=mid+1;
		else
		r=mid;
	}
	return l;
    }
	int countPair(vector<int> &nums,int mid)
	{
		int res=0,len=nums.size();
		for(int i=0;i<len;i++)
		{
			int j=i;
			while(j<len&&nums[j]-nums[i]<=mid) j++;
			res+=j-i-1;
		}
		return res;
	}
	int countPair1(vector<int> &nums,int mid)
	{
		int n=nums.size(),res=0;
		for(int i=0;i<n;i++)
		res+=bound(nums,nums[i]+mid,i,n-1)-i-1;
		return res;
	}
	int bound(vector<int> &a,int key,int l,int r)
	{
		if(a[r]<=key) return r+1;
		while(l<r)
		{
			int mid=l+(r-l)/2;
			if(key>=a[mid])
				l=mid+1;
			else
				r=mid;
		}
		return l;
	}
};
