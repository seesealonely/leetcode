/*
   You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

   We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.



   Example 1:

Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation:
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].

Example 2:

Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
Output: [1,1]



Constraints:

nums.length == k
1 <= k <= 3500
1 <= nums[i].length <= 50
-105 <= nums[i][j] <= 105
nums[i] is sorted in non-decreasing order.

*/


#include"head.h"
class Solution {
	public:
		vector<int> smallestRange(vector<vector<int>>& nums) {
		vector<pair<int,int>> sorted;
		const int n=nums.size();
		for(int i=0;i<n;i++)
			for(int j=0;j<nums[i].size();j++)
				sorted.push_back({nums[i][j],i});

		sort(sorted.begin(),sorted.end());
		
		int cnt=0,l=0;
		vector<int> res;
		unordered_map<int,int> count;

		for(int r=0;r<sorted.size();r++)
		{
			if(!count[sorted[r].second]++) cnt++;
			if(cnt==n)
			{
				while(count[sorted[l].second]>1) --count[sorted[l++].second];
				if(res.empty()||res[1]-res[0]>sorted[r].first-sorted[l].first)
					res={sorted[l].first,sorted[r].first};
			}
		}
		return res;
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> nums = {{4,10,15,24,26},{0,9,12,20},{5,18,22,30}};
	show(s.smallestRange(nums));
	nums.clear();nums = {{1,2,3},{1,2,3},{1,2,3}};
	show(s.smallestRange(nums));
	return 0;
}
