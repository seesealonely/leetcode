/*
   You are given a 0-indexed array nums of non-negative integers, and two integers l and r.

   Return the count of sub-multisets within nums where the sum of elements in each subset falls within the inclusive range of [l, r].

   Since the answer may be large, return it modulo 109 + 7.

   A sub-multiset is an unordered collection of elements of the array in which a given value x can occur 0, 1, ..., occ[x] times, where occ[x] is the number of occurrences of x in the array.

   Note that:

   Two sub-multisets are the same if sorting both sub-multisets results in identical multisets.
   The sum of an empty multiset is 0.



   Example 1:

Input: nums = [1,2,2,3], l = 6, r = 6
Output: 1
Explanation: The only subset of nums that has a sum of 6 is {1, 2, 3}.

Example 2:

Input: nums = [2,1,4,2,7], l = 1, r = 5
Output: 7
Explanation: The subsets of nums that have a sum within the range [1, 5] are {1}, {2}, {4}, {2, 2}, {1, 2}, {1, 4}, and {1, 2, 2}.

Example 3:

Input: nums = [1,2,1,3,5,2], l = 3, r = 5
Output: 9
Explanation: The subsets of nums that have a sum within the range [3, 5] are {3}, {5}, {1, 2}, {1, 3}, {2, 2}, {2, 3}, {1, 1, 2}, {1, 1, 3}, and {1, 2, 2}.



Constraints:

1 <= nums.length <= 2 * 104
0 <= nums[i] <= 2 * 104
Sum of nums does not exceed 2 * 104.
0 <= l <= r <= 2 * 104

*/


#include"head.h"
class Solution {
	public:
		int countSubMultisets(vector<int>& nums, int l, int r) {
		const int n=nums.size(),mod=1e9+7;

		int tot=accumulate(nums.begin(),nums.end(),0);
		unordered_map<int,int> cnt;
		for(int i=0;i<n;i++)
			cnt[nums[i]]++;

		if(l>tot)
			return 0;

		r=min(r,tot);
		vector<int> dp(r+1);
		dp[0]=cnt[0]+1;
		cnt.erase(0);

		int sum=0;
		for(unordered_map<int,int>::iterator it=cnt.begin();it!=cnt.end();it++)
		{
			vector<int> t=dp;
			sum=min(sum+it->first*it->second,r);
			for(int i=it->first;i<=sum;i++)
			{
				t[i]=(t[i]+t[i-it->first])%mod;
				if(i>=(it->second+1)*it->first)
						t[i]=(t[i]-dp[i-(it->second+1)*it->first]+mod)%mod;
			}
			dp=t;
		}
		int res=0;
		for(int i=l;i<=r;i++)
			res=(res+dp[i])%mod;
		return res;
		}
};


int main() 
{
	Solution s;
	vector<int> nums = {1,2,2,3};
	cout<<s.countSubMultisets(nums,6,6)<<endl;
	nums.clear();nums={2,1,4,2,7};
	cout<<s.countSubMultisets(nums,1,5)<<endl;
	nums.clear();nums={1,2,1,3,5,2};
	cout<<s.countSubMultisets(nums,3,5)<<endl;
	return 0;
}
