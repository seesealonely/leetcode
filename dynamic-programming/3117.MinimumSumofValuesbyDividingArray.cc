/*
   You are given two arrays nums and andValues of length n and m respectively.

   The value of an array is equal to the last element of that array.

   You have to divide nums into m disjoint contiguous
   subarrays
   such that for the ith subarray [li, ri], the bitwise AND of the subarray elements is equal to andValues[i], in other words, nums[li] & nums[li + 1] & ... & nums[ri] == andValues[i] for all 1 <= i <= m, where & represents the bitwise AND operator.

   Return the minimum possible sum of the values of the m subarrays nums is divided into. If it is not possible to divide nums into m subarrays satisfying these conditions, return -1.



   Example 1:

Input: nums = [1,4,3,3,2], andValues = [0,3,3,2]

Output: 12

Explanation:

The only possible way to divide nums is:

[1,4] as 1 & 4 == 0.
[3] as the bitwise AND of a single element subarray is that element itself.
[3] as the bitwise AND of a single element subarray is that element itself.
[2] as the bitwise AND of a single element subarray is that element itself.

The sum of the values for these subarrays is 4 + 3 + 3 + 2 = 12.

Example 2:

Input: nums = [2,3,5,7,7,7,5], andValues = [0,7,5]

Output: 17

Explanation:

There are three ways to divide nums:

[[2,3,5],[7,7,7],[5]] with the sum of the values 5 + 7 + 5 == 17.
[[2,3,5,7],[7,7],[5]] with the sum of the values 7 + 7 + 5 == 19.
[[2,3,5,7,7],[7],[5]] with the sum of the values 7 + 7 + 5 == 19.

The minimum possible sum of the values is 17.

Example 3:

Input: nums = [1,2,3,4], andValues = [2]

Output: -1

Explanation:

The bitwise AND of the entire array nums is 0. As there is no possible way to divide nums into a single subarray to have the bitwise AND of elements 2, return -1.



Constraints:

1 <= n == nums.length <= 104
1 <= m == andValues.length <= min(n, 10)
1 <= nums[i] < 105
0 <= andValues[j] < 105

*/


#include"head.h"
class Solution {
	public:
		static const int M=11;
		int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
			const int n=nums.size(),m=andValues.size();
			unordered_map<int,int> dp[M];

			dp[0][nums[0]]=0;
			for(int i=1;i<n;i++)
			{
				unordered_map<int,int> cur[M];
				for(int j=0;j<min(m,i+1);j++)
				{
					if(j>0&&dp[j-1].count(andValues[j-1]))
						cur[j][nums[i]]=dp[j-1][andValues[j-1]]+nums[i-1];
					for(unordered_map<int,int>::iterator it=dp[j].begin();it!=dp[j].end();it++)
					{
						int t=it->first&nums[i];
						if(cur[j].count(t)==0||cur[j][t]>dp[j][it->first])
							cur[j][t]=dp[j][it->first];
					}
				}
				for(int j=0;j<min(m,i+1);j++)
					dp[j]=cur[j];
			}
			if(dp[m-1].count(andValues[m-1])==0)
				return -1;
			return dp[m-1][andValues[m-1]]+nums[n-1];	
		}
};


int main() 
{
	Solution s;
	vector<int>  nums = {1,4,3,3,2}, andValues = {0,3,3,2};
	cout<<s.minimumValueSum(nums,andValues)<<endl;
	nums.clear();andValues.clear();
	nums = {2,3,5,7,7,7,5}, andValues = {0,7,5};
	cout<<s.minimumValueSum(nums,andValues)<<endl;
	nums.clear();andValues.clear();
	nums = {1,2,3,4}, andValues = {2};
	cout<<s.minimumValueSum(nums,andValues)<<endl;
	return 0;
}
