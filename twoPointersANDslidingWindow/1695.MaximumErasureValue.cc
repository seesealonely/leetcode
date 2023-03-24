/*
   You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.

   Return the maximum score you can get by erasing exactly one subarray.

   An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).



   Example 1:

Input: nums = [4,2,4,5,6]
Output: 17
Explanation: The optimal subarray here is [2,4,5,6].

Example 2:

Input: nums = [5,2,1,2,5,2,1,2,5]
Output: 8
Explanation: The optimal subarray here is [5,2,1] or [1,2,5].



Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 104

*/

#define c11
#include"head.h"
class Solution {
	public:
		int maximumUniqueSubarray(vector<int>& nums) {
		unordered_set<int> s;
		int n=nums.size(),sum=0,res=-1;

		for(int l=0,r=0;r<n;r++)
		{
			int cur=nums[r];
			sum+=cur;
			while(l<r&&s.count(cur))
			{
				sum-=nums[l];
				s.erase(nums[l++]);
			}
			s.insert(cur);
			res=max(res,sum);
		}

		return res;
		}
};


int main() 
{
	Solution s;
	vector<int> v={4,2,4,5,6};
	cout<<s.maximumUniqueSubarray(v)<<endl;
	v.clear();v={5,2,1,2,5,2,1,2,5};
	cout<<s.maximumUniqueSubarray(v)<<endl;
	return 0;
}
