/*
   You are given an array nums which is a
   permutation
   of [0, 1, 2, ..., n - 1]. The score of any permutation of [0, 1, 2, ..., n - 1] named perm is defined as:

   score(perm) = |perm[0] - nums[perm[1]]| + |perm[1] - nums[perm[2]]| + ... + |perm[n - 1] - nums[perm[0]]|

   Return the permutation perm which has the minimum possible score. If multiple permutations exist with this score, return the one that is
   lexicographically smallest
   among them.



   Example 1:

Input: nums = [1,0,2]

Output: [0,1,2]

Explanation:

The lexicographically smallest permutation with minimum cost is [0,1,2]. The cost of this permutation is |0 - 0| + |1 - 2| + |2 - 1| = 2.

Example 2:

Input: nums = [0,2,1]

Output: [0,2,1]

Explanation:

The lexicographically smallest permutation with minimum cost is [0,2,1]. The cost of this permutation is |0 - 1| + |2 - 2| + |1 - 0| = 2.



Constraints:

2 <= n == nums.length <= 14
nums is a permutation of [0, 1, 2, ..., n - 1].

*/


#include"head.h"
class Solution {
	public:
		vector<int> findPermutation(vector<int>& nums) {
			const int n=nums.size(),m=(1<<n);
			vector<vector<int>> dp(m,vector<int>(n,1e9)),p(m,vector<int>(n,-1));

			dp[1][0]=nums[0];
			for(int mask=0;mask<m;mask++)
				for(int i=1;i<n;i++)
				{
					if(!((mask>>i)&1))
						continue;
					for(int j=0;j<n;j++)
					{
						if(j==i||!((mask>>j)&1))
							continue;
						int val=dp[mask^(1<<i)][j]-nums[j]+nums[i]+abs(i-nums[j]);
						if(dp[mask][i]>val)
						{
							dp[mask][i]=val;
							p[mask][i]=j;
						}
					}
				}
			int mx=INT_MAX,st=0;
			for(int i=0;i<n;i++)
				if(mx>dp[m-1][i])
				{
					mx=dp[m-1][i];
					st=i;
				}

			vector<int> res;
			res.push_back(0);

			int mask=m-1,i=st;
			while(p[mask][i]!=-1)
			{
				res.push_back(i);
				int next=p[mask][i];
				mask^=(1<<i);
				i=next;
			}
			return res;
		}
};


int main() 
{
	Solution s;
	vector<int> nums={1,0,2};
	show(s.findPermutation(nums));
	nums.clear();nums={0,2,1};
	show(s.findPermutation(nums));
	return 0;
}
