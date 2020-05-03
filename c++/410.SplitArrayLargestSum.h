/*
Given an array which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these m subarrays.

Note:
If n is the length of array, assume the following constraints are satisfied:

    1 ≤ n ≤ 1000
    1 ≤ m ≤ min(50, n)

Examples:

Input:
nums = [7,2,5,10,8]
m = 2

Output:
18

Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.

*/

#include"head.h"

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        
    }

    int dp(vector<int>& nums, int m) {
	vector<vector<int> > dp(m,vector<int>(nums.size(),0);
	for(int k=0;k<m)
	{
		dp[k][0]=INT_MIN;
	for(int i=0;i<num.size();i++)
	for(int j=i+1;
	}
	}
};
