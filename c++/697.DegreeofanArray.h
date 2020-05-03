/*
Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

Example 1:

Input: [1, 2, 2, 3, 1]
Output: 2
Explanation: 
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.

Example 2:

Input: [1,2,2,3,1,4,2]
Output: 6

Note:
nums.length will be between 1 and 50,000.
nums[i] will be an integer between 0 and 49,999.
*/
#define c11
#include"head.h"
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
	unordered_map<int,vector<int> > hash;
	int degree=0;
	int res=INT_MAX;
	for(int i=0;i<nums.size();i++)
		hash[nums[i]].push_back(i);        
	for(unordered_map<int,vector<int> >::iterator it=hash.begin();it!=hash.end();it++)
		degree=max(degree,(int)it->second.size());
	for(unordered_map<int,vector<int> >::iterator it=hash.begin();it!=hash.end();it++)
		if(it->second.size()==degree)
		res=min(res,it->second[degree-1]-it->second[0]+1);
	return res;	
    }
};
