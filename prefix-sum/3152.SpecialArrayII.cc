/*
   An array is considered special if every pair of its adjacent elements contains two numbers with different parity.

   You are given an array of integer nums and a 2D integer matrix queries, where for queries[i] = [fromi, toi] your task is to check that
   subarray
   nums[fromi..toi] is special or not.

   Return an array of booleans answer such that answer[i] is true if nums[fromi..toi] is special.



   Example 1:

Input: nums = [3,4,1,2,6], queries = [[0,4]]

Output: [false]

Explanation:

The subarray is [3,4,1,2,6]. 2 and 6 are both even.

Example 2:

Input: nums = [4,3,1,6], queries = [[0,2],[2,3]]

Output: [false,true]

Explanation:

The subarray is [4,3,1]. 3 and 1 are both odd. So the answer to this query is false.
The subarray is [1,6]. There is only one pair: (1,6) and it contains numbers with different parity. So the answer to this query is true.



Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 105
1 <= queries.length <= 105
queries[i].length == 2
0 <= queries[i][0] <= queries[i][1] <= nums.length - 1

*/


#include"head.h"
class Solution {
	public:
		vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
		const int n=nums.size(),q=queries.size();
		vector<int> pre(n,0);
		for(int i=0;i<n-1;i++)
			pre[i+1]=(((nums[i]^nums[i+1])&1)^1)+(i==0?0:pre[i]);

		pre[0]=0;
		vector<bool> res(q);
		for(int i=0;i<q;i++)
		{
			int l=queries[i][0],r=queries[i][1];
			res[i]=pre[r]-pre[l]==0;
		}
		return res;
		}
};


int main() 
{
	Solution s;
	vector<int> nums={3,4,1,2,6};
	vector<vector<int>> queries={{0,4}};
	show(s.isArraySpecial(nums,queries));
	nums.clear();nums={4,3,1,6};
	queries.clear();queries={{0,2},{2,3}};
	show(s.isArraySpecial(nums,queries));
	return 0;
}
