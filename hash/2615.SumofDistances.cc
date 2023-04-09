/*
   You are given a 0-indexed integer array nums. There exists an array arr of length nums.length, where arr[i] is the sum of |i - j| over all j such that nums[j] == nums[i] and j != i. If there is no such j, set arr[i] to be 0.

   Return the array arr.



   Example 1:

Input: nums = [1,3,1,1,2]
Output: [5,0,3,4,0]
Explanation:
When i = 0, nums[0] == nums[2] and nums[0] == nums[3]. Therefore, arr[0] = |0 - 2| + |0 - 3| = 5.
When i = 1, arr[1] = 0 because there is no other index with value 3.
When i = 2, nums[2] == nums[0] and nums[2] == nums[3]. Therefore, arr[2] = |2 - 0| + |2 - 3| = 3.
When i = 3, nums[3] == nums[0] and nums[3] == nums[2]. Therefore, arr[3] = |3 - 0| + |3 - 2| = 4.
When i = 4, arr[4] = 0 because there is no other index with value 2.

Example 2:

Input: nums = [0,5,3]
Output: [0,0,0]
Explanation: Since each element in nums is distinct, arr[i] = 0 for all i.



Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109

*/

#define c11
#include"head.h"
class Solution {
	public:
		vector<long long> distance(vector<int>& nums) {
		typedef long long ll;
		unordered_map<int,vector<int>> set;

		const int n=nums.size();
		for(int i=0;i<n;i++)
			set[nums[i]].push_back(i);

		vector<ll> res(n);
		for(unordered_map<int,vector<int>>::iterator it=set.begin();it!=set.end();it++)
		{
			vector<int> idx=it->second;
			ll total=accumulate(idx.begin(),idx.end(),0LL),presum=0LL;

			for(int i=0;i<idx.size();i++)
			{
				int j=idx[i];
				ll postsum=total-presum-j;
				res[j]+=(ll)j*i;
				res[j]-=presum;
				res[j]-=(ll)j*(idx.size()-1-i);
				res[j]+=postsum;
				presum+=j;
			}
		}

		return res;
		}
};


int main() 
{
	Solution s;
	vector<int> v={1,3,1,1,2};
	show(s.distance(v));
	v.clear();v={0,5,3};
	show(s.distance(v));
	return 0;
}
