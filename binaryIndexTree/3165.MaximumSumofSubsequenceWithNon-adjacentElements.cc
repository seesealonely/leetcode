/*
   You are given an array nums consisting of integers. You are also given a 2D array queries, where queries[i] = [posi, xi].

   For query i, we first set nums[posi] equal to xi, then we calculate the answer to query i which is the maximum sum of a
   subsequence
   of nums where no two adjacent elements are selected.

   Return the sum of the answers to all queries.

   Since the final answer may be very large, return it modulo 109 + 7.

   A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.



   Example 1:

Input: nums = [3,5,9], queries = [[1,-2],[0,-3]]

Output: 21

Explanation:
After the 1st query, nums = [3,-2,9] and the maximum sum of a subsequence with non-adjacent elements is 3 + 9 = 12.
After the 2nd query, nums = [-3,-2,9] and the maximum sum of a subsequence with non-adjacent elements is 9.

Example 2:

Input: nums = [0,-1], queries = [[0,-5]]

Output: 0

Explanation:
After the 1st query, nums = [-5,-1] and the maximum sum of a subsequence with non-adjacent elements is 0 (choosing an empty subsequence).



Constraints:

1 <= nums.length <= 5 * 104
-105 <= nums[i] <= 105
1 <= queries.length <= 5 * 104
queries[i] == [posi, xi]
0 <= posi <= nums.length - 1
-105 <= xi <= 105

*/


#include"head.h"
class Solution {
	public:
		int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
			const int n=nums.size(),mod=1e9+7;
			build(nums,1,0,n-1);
			long long res=0,q=queries.size();
			for(int i=0;i<q;i++)
			{
				update(1,0,n-1,queries[i][0],queries[i][1]);
				res=(res+tree[1][3])%mod;
			}
			return res;
		}
	private:
		static const int N=500005;
		int tree[N][4];
		void check(int o)
		{
			int *p=tree[o<<1],*q=tree[o<<1|1];
			tree[o][0]=max(p[0]+q[2],p[1]+q[0]);
			tree[o][1]=max(p[0]+q[3],p[1]+q[1]);
			tree[o][2]=max(p[2]+q[2],p[3]+q[0]);
			tree[o][3]=max(p[2]+q[3],p[3]+q[1]);

		}
		void build(vector<int>&nums,int o,int l,int r)
		{
			if(l==r)
			{
				tree[o][3]=max(nums[l],0);
				return;
			}
			int m=(l+r)>>1;
			build(nums,o<<1,l,m);
			build(nums,o<<1|1,m+1,r);
			check(o);
		}
		void update(int o,int l,int r,int i,int val)
		{
			if(l==r)
			{
				tree[o][3]=max(val,0);
				return;
			}
			int m=(l+r)>>1;
			if(i<=m)
				update(o<<1,l,m,i,val);
			else
				update(o<<1|1,m+1,r,i,val);
			check(o);
		}
};


int main() 
{
	Solution s;
	vector<int> nums={3,5,9};
	vector<vector<int>> queries={{1,-2},{0,-3}};
	cout<<s.maximumSumSubsequence(nums,queries)<<endl;
	nums.clear();nums={0,-1};
	queries.clear();queries={{0,-5}};
	cout<<s.maximumSumSubsequence(nums,queries)<<endl;
	return 0;
}
