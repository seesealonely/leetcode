/*
   Given an array nums that represents a permutation of integers from 1 to n. We are going to construct a binary search tree (BST) by inserting the elements of nums in order into an initially empty BST. Find the number of different ways to reorder nums so that the constructed BST is identical to that formed from the original array nums.

   For example, given nums = [2,1,3], we will have 2 as the root, 1 as a left child, and 3 as a right child. The array [2,3,1] also yields the same BST but [3,2,1] yields a different BST.

   Return the number of ways to reorder nums such that the BST formed is identical to the original BST formed from nums.

   Since the answer may be very large, return it modulo 109 + 7.



   Example 1:

Input: nums = [2,1,3]
Output: 1
Explanation: We can reorder nums to be [2,3,1] which will yield the same BST. There are no other ways to reorder nums which will yield the same BST.

Example 2:

Input: nums = [3,4,5,1,2]
Output: 5
Explanation: The following 5 arrays will yield the same BST:
[3,1,2,4,5]
[3,1,4,2,5]
[3,1,4,5,2]
[3,4,1,2,5]
[3,4,1,5,2]

Example 3:

Input: nums = [1,2,3]
Output: 0
Explanation: There are no other orderings of nums that will yield the same BST.



Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= nums.length
All integers in nums are distinct.

*/


#include"head.h"
class Solution {
	private:
		typedef long long int ll;
		const int mod=1e9+7;
		vector<ll> fact;
		ll power(ll x,ll y)
		{
			ll tot=1,p=x;
			for(;y;y>>=1)
			{
				if(y&1)
					tot=tot*p%mod;
				p=p*p%mod;
			}
			return tot;
		}
		ll select(int n,int m)
		{
			return fact[n]*power(fact[m],mod-2)%mod*power(fact[n-m],mod-2)%mod;
		}
		
		int solve(const vector<int> &nums)
		{
			if(nums.size()==0)
				return 1;
			vector<int> low,high;
			const int n=nums.size();
			for(int i=1;i<n;i++)
			{
				if(nums[i]<nums[0])  low.push_back(nums[i]);
				else high.push_back(nums[i]);
			}
			return select(n-1,low.size())*solve(low)%mod*solve(high)%mod;
		}
	public:
		int numOfWays(vector<int>& nums) {
		const int n=nums.size();
		fact.resize(n);
		fact[0]=1;
		for(int i=1;i<n;i++)
			fact[i]=fact[i-1]*i%mod;

		return (solve(nums)-1+mod)%mod;
		}
};


int main() 
{
	Solution s;
	vector<int> nums={2,1,3};
	cout<<s.numOfWays(nums)<<endl;
	nums.clear();nums={3,4,5,1,2};
	cout<<s.numOfWays(nums)<<endl;
	nums.clear();nums={1,2,3};
	cout<<s.numOfWays(nums)<<endl;
	return 0;
}
