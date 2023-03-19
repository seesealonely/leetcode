/*
   You are given an array nums of positive integers and a positive integer k.

   A subset of nums is beautiful if it does not contain two integers with an absolute difference equal to k.

   Return the number of non-empty beautiful subsets of the array nums.

   A subset of nums is an array that can be obtained by deleting some (possibly none) elements from nums. Two subsets are different if and only if the chosen indices to delete are different.



   Example 1:

Input: nums = [2,4,6], k = 2
Output: 4
Explanation: The beautiful subsets of the array nums are: [2], [4], [6], [2, 6].
It can be proved that there are only 4 beautiful subsets in the array [2,4,6].

Example 2:

Input: nums = [1], k = 1
Output: 1
Explanation: The beautiful subset of the array nums is [1].
It can be proved that there is only 1 beautiful subset in the array [1].



Constraints:

1 <= nums.length <= 20
1 <= nums[i], k <= 1000

*/

#define c11
#include"head.h"
class Solution {
	public:
		int beautifulSubsets(vector<int>& nums, int k) {
			unordered_map<int,int> h;
			int res=0;
			backtrace(res,0,k,nums,h);
			return res-1;
		}
		void backtrace(int &res,int s,int k,const vector<int> &nums,unordered_map<int,int> &h)
		{

			if(s==nums.size())
			{
				res++;
				return;
			}
			int x=nums[s];
			if(h[x+k]==0&&h[x-k]==0)
			{
				h[x]++;
				backtrace(res,s+1,k,nums,h);
				h[x]--;
			}
			backtrace(res,s+1,k,nums,h);
		}
};


int main() 
{
	Solution s;
	vector<int> v={2,4,6};
	cout<<s.beautifulSubsets(v,2)<<endl;
	v.clear();v={1};
	cout<<s.beautifulSubsets(v,1)<<endl;
	return 0;
}
