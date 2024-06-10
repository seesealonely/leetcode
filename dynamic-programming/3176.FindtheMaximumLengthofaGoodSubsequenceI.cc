/*
   You are given an integer array nums and a non-negative integer k. A sequence of integers seq is called good if there are at most k indices i in the range [0, seq.length - 2] such that seq[i] != seq[i + 1].

   Return the maximum possible length of a good
   subsequence
   of nums.



   Example 1:

Input: nums = [1,2,1,1,3], k = 2

Output: 4

Explanation:

The maximum length subsequence is [1,2,1,1,3].

Example 2:

Input: nums = [1,2,3,4,5,1], k = 0

Output: 2

Explanation:

The maximum length subsequence is [1,2,3,4,5,1].



Constraints:

1 <= nums.length <= 500
1 <= nums[i] <= 109
0 <= k <= min(nums.length, 25)

*/


#include"head.h"
class Solution {
	public:
		static const int N=5005,K=51;
		int dp[K][N],pre[K][N];
		int maximumLength(vector<int>& nums, int k) {
		const int n=nums.size();
		int res=1;
		for(int i=0;i<=k;i++)
		{
			unordered_map<int,int> h;
			for(int j=0;j<n;j++)
			{
				dp[i][j]=1;
				if(i>0&&j>0)
					dp[i][j]=max(dp[i][j],pre[i-1][j-1]+1);
				if(h.count(nums[j]))
					dp[i][j]=max(dp[i][j],h[nums[j]]+1);
				if(i==0)
					pre[i][j]=1;
				else
					pre[i][j]=max(pre[i][j-1],dp[i][j]);
				h[nums[j]]=max(h[nums[j]],dp[i][j]);
				res=max(res,dp[i][j]);
			}
		}
		return res;
		}
};


int main() 
{
	Solution s;
	vector<int> nums={1,2,1,1,3};
	cout<<s.maximumLength(nums,2)<<endl;
	nums.clear();nums={1,2,3,4,5,1};
	cout<<s.maximumLength(nums,0)<<endl;
	return 0;
}
