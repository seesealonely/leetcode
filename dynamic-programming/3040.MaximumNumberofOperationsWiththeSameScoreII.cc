/*
   Given an array of integers called nums, you can perform any of the following operation while nums contains at least 2 elements:

   Choose the first two elements of nums and delete them.
   Choose the last two elements of nums and delete them.
   Choose the first and the last elements of nums and delete them.

   The score of the operation is the sum of the deleted elements.

   Your task is to find the maximum number of operations that can be performed, such that all operations have the same score.

   Return the maximum number of operations possible that satisfy the condition mentioned above.



   Example 1:

Input: nums = [3,2,1,2,3,4]
Output: 3
Explanation: We perform the following operations:
- Delete the first two elements, with score 3 + 2 = 5, nums = [1,2,3,4].
- Delete the first and the last elements, with score 1 + 4 = 5, nums = [2,3].
- Delete the first and the last elements, with score 2 + 3 = 5, nums = [].
We are unable to perform any more operations as nums is empty.

Example 2:

Input: nums = [3,2,6,1,4]
Output: 2
Explanation: We perform the following operations:
- Delete the first two elements, with score 3 + 2 = 5, nums = [6,1,4].
- Delete the last two elements, with score 1 + 4 = 5, nums = [6].
It can be proven that we can perform at most 2 operations.



Constraints:

2 <= nums.length <= 2000
1 <= nums[i] <= 1000

*/


#include"head.h"
class Solution {
	public:
		int maxOperations(vector<int>& nums) {
		const int n=nums.size();
		vector<vector<int>> mem(n,vector<int>(n,-1));
		int s1=dfs(2,n-1,mem,nums,nums[0]+nums[1]);
		int s2=dfs(1,n-2,mem,nums,nums[0]+nums[n-1]);
		int s3=dfs(0,n-3,mem,nums,nums[n-2]+nums[n-1]);
		return max(max(s1,s2),s3)+1;
		}
		int dfs(int s,int e,vector<vector<int>> &mem,vector<int>&nums,int target)
		{
		if(s>=e) return 0;

		int res=mem[s][e];
		if(res!=-1) return res;
		res=0;
		if(target==nums[s]+nums[s+1])
		res=max(res,dfs(s+2,e,mem,nums,nums[s]+nums[s+1])+1);
		if(target==nums[s]+nums[e])
		res=max(res,dfs(s+1,e-1,mem,nums , nums[s]+ nums[e])+1);
		if(target==nums[e-1]+nums[e])
		res=max(res,dfs(s,e-2,mem,nums, nums[e]+nums[e-1])+1);
		return mem[s][e]=res;
		}
};


int main() 
{
	Solution s;
	vector<int> nums = {3,2,1,2,3,4};
	cout<<s.maxOperations(nums)<<endl;
	nums.clear();nums={3,2,6,1,4};
	cout<<s.maxOperations(nums)<<endl;
	return 0;
}
