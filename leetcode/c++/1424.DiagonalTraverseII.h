/*
   Given a list of lists of integers, nums, return all elements of nums in diagonal order as shown in the below images.



   Example 1:

Input: nums = [[1,2,3],[4,5,6],[7,8,9]]
Output: 9

Example 2:

Input: nums = [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
Output: 9

Example 3:

Input: nums = [[1,2,3],[4],[5,6,7],[8],[9,10,11]]
Output: 9

Example 4:

Input: nums = [[1,2,3,4,5,6]]
Output: [1,2,3,4,5,6]



Constraints:

1 <= nums.length <= 10^5
1 <= nums[i].length <= 10^5
1 <= nums[i][j] <= 10^9
There at most 10^5 elements in nums.
*/
#include"head.h"
class Solution {
	public:
		vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
			return bfs(nums);
		}
		vector<int> bfs(vector<vector<int>>& nums) {
			vector<int> res;
			queue<pair<int,int>> qu;
			int n=nums.size();
			qu.push({0,0});
			while(!qu.empty())
			{
				pair<int,int> cur=qu.front();qu.pop();
				res.push_back(nums[cur.first][cur.second]);
				if(cur.second==0&&cur.first+1<n) qu.push({cur.first+1,cur.second});
				if(cur.second+1<nums[cur.first].size()) qu.push({cur.first,cur.second+1});
			}
			return res;
		}
};
