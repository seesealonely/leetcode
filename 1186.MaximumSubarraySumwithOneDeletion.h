/*
Given an array of integers, return the maximum sum for a non-empty subarray (contiguous elements) with at most one element deletion. In other words, you want to choose a subarray and optionally delete one element from it so that there is still at least one element left and the sum of the remaining elements is maximum possible.

Note that the subarray needs to be non-empty after deleting one element.

 

Example 1:

Input: arr = [1,-2,0,3]
Output: 4
Explanation: Because we can choose [1, -2, 0, 3] and drop -2, thus the subarray [1, 0, 3] becomes the maximum value.

Example 2:

Input: arr = [1,-2,-2,3]
Output: 3
Explanation: We just choose [3] and it's the maximum sum.

Example 3:

Input: arr = [-1,-1,-1,-1]
Output: -1
Explanation: The final subarray needs to be non-empty. You can't choose [-1] and delete -1 from it, then get an empty subarray to make the sum equals to 0.

 

Constraints:

    1 <= arr.length <= 10^5
    -10^4 <= arr[i] <= 10^4
*/

#include"head.h"

class Solution {
public:
    int maximumSum(vector<int>& arr) {
	if(arr.size()==1) return arr[0];
	int maxval=INT_MIN;
	vector<int> dp1(arr.size()),dp2(arr.size());
	dp1[0]=arr[0];dp2[arr.size()-1]=arr[arr.size()-1];
	for(int i=1;i<=arr.size()-1;i++)
	{
		dp1[i]=dp1[i-1]>=0?dp1[i-1]+arr[i]:arr[i];
		maxval=max(maxval,dp1[i]);
	}        
	for(int i=arr.size()-2;i>=0;i--)
		dp2[i]=dp2[i+1]>=0?dp2[i+1]+arr[i]:arr[i];
	for(int i=1;i<arr.size()-1;i++)
	if(arr[i]<0)
		maxval=max(maxval,dp1[i-1]+dp2[i+1]);
	return maxval;
    }
};
