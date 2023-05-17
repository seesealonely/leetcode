/*
   Given an integer array nums and an integer k, return the number of good subarrays of nums.

   A good array is an array where the number of different integers in that array is exactly k.

   For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.

   A subarray is a contiguous part of an array.



   Example 1:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]

Example 2:

Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].



Constraints:

1 <= nums.length <= 2 * 104
1 <= nums[i], k <= nums.length

*/


#include"head.h"
class Solution {
	public:
		int subarraysWithKDistinct(vector<int>& nums, int k) {
		const int n=nums.size();
		vector<int> lower(n,0),upper(n,0);

		getLenK(lower,nums,k-1);
		getLenK(upper,nums,k);

		int res=0;
		for(int i=0;i<n;i++)
			res+=upper[i]-lower[i];

		return -res;

		}
		void getLenK(vector<int> &idx,const vector<int> &nums,int k)
		{
			const int n=nums.size();
			int l=0,cnt=0;
			vector<int> vis(n+1,0);
			for(int i=0;i<n;i++)
			{
				if(vis[nums[i]]==0)
					cnt++;
				vis[nums[i]]++;
				while(cnt==k+1)
				{
					if(vis[nums[l]]==1)
						cnt--;
					vis[nums[l]]--;
					l++;	
				}
				idx[i]=l;
			}
		}
};


int main() 
{
	Solution s;
	vector<int> nums={1,2,1,2,3};
	cout<<s.subarraysWithKDistinct(nums,2)<<endl;
	nums.clear();nums={1,2,1,3,4};
	cout<<s.subarraysWithKDistinct(nums,3)<<endl;
	return 0;
}
