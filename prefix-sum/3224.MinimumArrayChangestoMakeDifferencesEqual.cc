/*
   You are given an integer array nums of size n where n is even, and an integer k.

   You can perform some changes on the array, where in one change you can replace any element in the array with any integer in the range from 0 to k.

   You need to perform some changes (possibly none) such that the final array satisfies the following condition:

   There exists an integer X such that abs(a[i] - a[n - i - 1]) = X for all (0 <= i < n).

   Return the minimum number of changes required to satisfy the above condition.



   Example 1:

Input: nums = [1,0,1,2,4,3], k = 4

Output: 2

Explanation:
We can perform the following changes:

Replace nums[1] by 2. The resulting array is nums = [1,2,1,2,4,3].
Replace nums[3] by 3. The resulting array is nums = [1,2,1,3,4,3].

The integer X will be 2.

Example 2:

Input: nums = [0,1,2,3,3,6,5,4], k = 6

Output: 2

Explanation:
We can perform the following operations:

Replace nums[3] by 0. The resulting array is nums = [0,1,2,0,3,6,5,4].
Replace nums[4] by 4. The resulting array is nums = [0,1,2,0,4,6,5,4].

The integer X will be 4.



Constraints:

2 <= n == nums.length <= 105
n is even.
0 <= nums[i] <= k <= 105

*/


#include"head.h"
class Solution {
	public:
		int minChanges(vector<int>& nums, int k) {
		const int n=nums.size();
		vector<int> cnt(k+2,0);

		for(int i=0;i<n/2;i++)
		{
			int x=nums[i],y=nums[n-i-1];
			int mx=max(max(x,k-x),max(y,k-y));
			cnt[0]++;cnt[mx+1]++;

			int cur=abs(x-y);
			if(cur<=mx)
				--cnt[cur],++cnt[cur+1];
			else
				cnt[cur]-=2,cnt[cur+1]+=2;
		}

		int res=cnt[0];
		for(int i=1;i<=k;i++)
		{
			cnt[i]+=cnt[i-1];
			res=min(res,cnt[i]);
		}
		return res;
		}
};


int main() 
{
	Solution s;
	vector<int> nums = {1,0,1,2,4,3};
	cout<<s.minChanges(nums,4)<<endl;
	nums.clear();nums = {0,1,2,3,3,6,5,4};
	cout<<s.minChanges(nums,6)<<endl;
	return 0;
}
