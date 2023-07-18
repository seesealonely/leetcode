/*
   You are given an array nums​​​ and an integer k​​​​​. The XOR of a segment [left, right] where left <= right is the XOR of all the elements with indices between left and right, inclusive: nums[left] XOR nums[left+1] XOR ... XOR nums[right].

   Return the minimum number of elements to change in the array such that the XOR of all segments of size k​​​​​​ is equal to zero.



   Example 1:

Input: nums = [1,2,0,3,0], k = 1
Output: 3
Explanation: Modify the array from [1,2,0,3,0] to from [0,0,0,0,0].

Example 2:

Input: nums = [3,4,5,2,1,7,3,4,7], k = 3
Output: 3
Explanation: Modify the array from [3,4,5,2,1,7,3,4,7] to [3,4,7,3,4,7,3,4,7].

Example 3:

Input: nums = [1,2,4,1,2,5,1,2,6], k = 3
Output: 3
Explanation: Modify the array from [1,2,4,1,2,5,1,2,6] to [1,2,3,1,2,3,1,2,3].



Constraints:

1 <= k <= nums.length <= 2000
​​​​​​0 <= nums[i] < 210

*/


#include"head.h"
class Solution {
	public:
		int minChanges(vector<int>& nums, int k) {
		const int n=1<<10;
		vector<unordered_map<int,int>> hash(k);
		vector<int> cnt(k);

		for(int i=0;i<nums.size();i++)
		{
			cnt[i%k]++;
			hash[i%k][nums[i]]++;
		}

		vector<int> f(n,INT_MAX-2010);
		f[0]=0;
		for(int i=0;i<k;i++)
		{
			int mx=*min_element(f.begin(),f.end());
			vector<int> g(n,mx+cnt[i]);
			for(int mask=0;mask<n;mask++)
				for(unordered_map<int,int>::iterator it=hash[i].begin();it!=hash[i].end();it++)
					g[mask]=min(g[mask],f[mask^it->first]+cnt[i]-it->second);

			f=g;
		}

		return f.front();
		}
};


int main() 
{
	Solution s;
	vector<int> nums = {1,2,0,3,0};
	cout<<s.minChanges(nums,1)<<endl;
	nums.clear();nums={3,4,5,2,1,7,3,4,7};
	cout<<s.minChanges(nums,3)<<endl;
	nums.clear();nums={1,2,4,1,2,5,1,2,6};
	cout<<s.minChanges(nums,3)<<endl;
	return 0;
}
