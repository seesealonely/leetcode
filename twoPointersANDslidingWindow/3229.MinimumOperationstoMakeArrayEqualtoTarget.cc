/*
   You are given two positive integer arrays nums and target, of the same length.

   In a single operation, you can select any
   subarray
   of nums and increment or decrement each element within that subarray by 1.

   Return the minimum number of operations required to make nums equal to the array target.



   Example 1:

Input: nums = [3,5,1,2], target = [4,6,2,4]

Output: 2

Explanation:

We will perform the following operations to make nums equal to target:
- Increment nums[0..3] by 1, nums = [4,6,2,3].
- Increment nums[3..3] by 1, nums = [4,6,2,4].

Example 2:

Input: nums = [1,3,2], target = [2,1,4]

Output: 5

Explanation:

We will perform the following operations to make nums equal to target:
- Increment nums[0..0] by 1, nums = [2,3,2].
- Decrement nums[1..1] by 1, nums = [2,2,2].
- Decrement nums[1..1] by 1, nums = [2,1,2].
- Increment nums[2..2] by 1, nums = [2,1,3].
- Increment nums[2..2] by 1, nums = [2,1,4].



Constraints:

1 <= nums.length == target.length <= 105
1 <= nums[i], target[i] <= 108

*/


#include"head.h"
class Solution {
	public:
		typedef long long ll;
		long long minimumOperations(vector<int>& nums, vector<int>& target) {
		const int n=nums.size();
		for(int i=0;i<n;i++)
			target[i]-=nums[i];
		ll res=0;
		for(int r=1,l=0;r<=n;r++)
		{
			if(r<n&&(target[r]<=0&&target[r-1]<=0||target[r]>=0&&target[r-1]>=0))
				continue;
			res+=solve(l,r-1,target);
			l=r;
		}
		return res;
		}
		ll solve(int l,int r,vector<int> &target)
		{
			for(int i=l;i<=r;i++)
				if(target[i]<0)
					target[i]=-target[i];
			ll res=target[l];
			for(int i=l;i<r;i++)
				res+=max(target[i+1]-target[i],0);
			return res;
		}
};


int main() 
{
	Solution s;
	vector<int> nums = {3,5,1,2}, target = {4,6,2,4};
	cout<<s.minimumOperations(nums,target)<<endl;
	nums.clear();target.clear();
	nums = {1,3,2}, target = {2,1,4};
	cout<<s.minimumOperations(nums,target)<<endl;
	return 0;
}
