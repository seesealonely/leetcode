/*
   Given an integer array arr and a target value target, return the integer value such that when we change all the integers larger than value in the given array to be equal to value, the sum of the array gets as close as possible (in absolute difference) to target.

   In case of a tie, return the minimum such integer.

   Notice that the answer is not neccesarilly a number from arr.



   Example 1:

Input: arr = [4,9,3], target = 10
Output: 3
Explanation: When using 3 arr converts to [3, 3, 3] which sums 9 and that's the optimal answer.

Example 2:

Input: arr = [2,3,5], target = 10
Output: 5

Example 3:

Input: arr = [60864,25176,27249,21296,20204], target = 56803
Output: 11361



Constraints:

1 <= arr.length <= 104
1 <= arr[i], target <= 105

*/
#include"head.h"
class Solution {
	public:
		int findBestValue(vector<int>& arr, int target) {
		return usingSort(arr,target);
		}
		int usingSort(vector<int> &arr,int target)
		{
			int res=0,i=0,n=arr.size();
			sort(arr.begin(),arr.end());
			for(;i<n&&arr[i]*(n-i)<target;i++)
					target-=arr[i];
			if(i==n) return arr[n-1];
			res=target/(n-i);
			if(target-(n-i)*res>(res+1)*(n-i)-target)
			res++;
			return res;
		}
};
