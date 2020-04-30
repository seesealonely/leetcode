/*
 Given a sorted array consisting of only integers where every element appears twice except for one element which appears once. Find this single element that appears only once.

Example 1:

Input: [1,1,2,3,3,4,4,8,8]
Output: 2

Example 2:

Input: [3,3,7,7,10,11,11]
Output: 10

Note: Your solution should run in O(log n) time and O(1) space. 
*/

#include"head.h"

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
 	int n=nums.size(),l=0,h=n/2;
	while(l<h)
	{
		int m=(l+h)/2;
		if(nums[2*m]!=nums[2*m+1]) h=m;
		else l=m+1;
	}       
	return nums[2*l];
    }
};
