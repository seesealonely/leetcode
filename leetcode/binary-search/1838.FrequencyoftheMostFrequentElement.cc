/*
   The frequency of an element is the number of times it occurs in an array.

   You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.

   Return the maximum possible frequency of an element after performing at most k operations.



   Example 1:

Input: nums = [1,2,4], k = 5
Output: 3
Explanation: Increment the first element three times and the second element two times to make nums = [4,4,4].
4 has a frequency of 3.

Example 2:

Input: nums = [1,4,8,13], k = 5
Output: 2
Explanation: There are multiple optimal solutions:
- Increment the first element three times to make nums = [4,4,8,13]. 4 has a frequency of 2.
- Increment the second element four times to make nums = [1,8,8,13]. 8 has a frequency of 2.
- Increment the third element five times to make nums = [1,4,13,13]. 13 has a frequency of 2.

Example 3:

Input: nums = [3,9,6], k = 2
Output: 1



Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 105
1 <= k <= 105

*/
#include"head.h"
class Solution {
	public:
		int maxFrequency(vector<int>& nums, int k) {
			sort(nums.begin(),nums.end());
			const int n=nums.size();
			vector<long long> presum(n+1,0);
			for(int i=1;i<=n;i++)
				presum[i]=presum[i-1]+nums[i-1];
			int l=0,r=n;
			while(l<r)
			{
				int mid=(l+r+1)>>1;
				if(check(nums,presum,mid,k))
					l=mid;
				else
					r=mid-1;
			}
			return r;
		}
		bool check(vector<int> nums,vector<long long> &pre,int len,int k)
		{
			for(int i=0;i+len-1<nums.size();i++)
			{
				int sub=(long long)nums[i+len-1]*len-(pre[i+len]-pre[i]);
				if(sub<=k)
					return true;
			}
			return false;
		}
};
int main() 
{
	Solution s;
	vector<int> v={1,2,4};
	cout<<s.maxFrequency(v,5)<<endl;
	v.clear();v={1,4,8,13};
	cout<<s.maxFrequency(v,5)<<endl;
	v.clear();v={3,9,6};
	cout<<s.maxFrequency(v,2)<<endl;
	return 0;
}
