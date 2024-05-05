/*
   You are given an integer array nums of length n, and a positive integer k.

   The power of a
   subsequence
   is defined as the minimum absolute difference between any two elements in the subsequence.

   Return the sum of powers of all subsequences of nums which have length equal to k.

   Since the answer may be large, return it modulo 109 + 7.



   Example 1:

Input: nums = [1,2,3,4], k = 3

Output: 4

Explanation:

There are 4 subsequences in nums which have length 3: [1,2,3], [1,3,4], [1,2,4], and [2,3,4]. The sum of powers is |2 - 3| + |3 - 4| + |2 - 1| + |3 - 4| = 4.

Example 2:

Input: nums = [2,2], k = 2

Output: 0

Explanation:

The only subsequence in nums which has length 2 is [2,2]. The sum of powers is |2 - 2| = 0.

Example 3:

Input: nums = [4,3,-1], k = 2

Output: 10

Explanation:

There are 3 subsequences in nums which have length 2: [4,3], [4,-1], and [3,-1]. The sum of powers is |4 - 3| + |4 - (-1)| + |3 - (-1)| = 10.



Constraints:

2 <= n == nums.length <= 50
-108 <= nums[i] <= 108
2 <= k <= n

*/

#define c11
#include"head.h"
class Solution {
	public:
		typedef long long ll;
		int sumOfPowers(vector<int>& nums, int k) {
	
		unordered_map<int,ll> dp[N][N];
		const int n=nums.size();
		sort(nums.begin(),nums.end());

		for(int i=0;i<n;i++)
		{
			dp[i][1][mod]=1;
			for(int j=2;j<=k;j++)
				for(int e=0;e<i;e++)
					for(unordered_map<int,ll>::iterator it=dp[e][j-1].begin();it!=dp[e][j-1].end();it++)
					{
						int sub=min(it->first,nums[i]-nums[e]);
						dp[i][j][sub]=(dp[i][j][sub]+it->second)%mod;
					}
		}

		ll res=0;
		for(int i=0;i<n;i++)
			for(unordered_map<int,ll>::iterator it=dp[i][k].begin();it!=dp[i][k].end();it++)
				res=(res+it->second*it->first)%mod;
		return res;
		}
	private:
		static const int N=51;
		const int mod=1e9+7;
};


int main() 
{
	Solution s;
	vector<int> nums={1,2,3,4};
	cout<<s.sumOfPowers(nums,3)<<endl;
	nums.clear();nums={2,2};
	cout<<s.sumOfPowers(nums,2)<<endl;
	nums.clear();nums={4,3,-1};
	cout<<s.sumOfPowers(nums,2)<<endl;
	return 0;
}
