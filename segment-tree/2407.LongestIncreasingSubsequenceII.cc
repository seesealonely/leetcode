/*
   You are given an integer array nums and an integer k.

   Find the longest subsequence of nums that meets the following requirements:

   The subsequence is strictly increasing and
   The difference between adjacent elements in the subsequence is at most k.

   Return the length of the longest subsequence that meets the requirements.

   A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.



   Example 1:

Input: nums = [4,2,1,4,3,4,5,8,15], k = 3
Output: 5
Explanation:
The longest subsequence that meets the requirements is [1,3,4,5,8].
The subsequence has a length of 5, so we return 5.
Note that the subsequence [1,3,4,5,8,15] does not meet the requirements because 15 - 8 = 7 is larger than 3.

Example 2:

Input: nums = [7,4,5,1,8,12,4,7], k = 5
Output: 4
Explanation:
The longest subsequence that meets the requirements is [4,5,8,12].
The subsequence has a length of 4, so we return 4.

Example 3:

Input: nums = [1,5], k = 1
Output: 1
Explanation:
The longest subsequence that meets the requirements is [1].
The subsequence has a length of 1, so we return 1.



Constraints:

1 <= nums.length <= 105
1 <= nums[i], k <= 105

*/


#include"head.h"
class Solution {
	private:
		static const int N=1e5+2;
		int mx[N<<2];		
		void update(int p,int v,int l,int r,int root)
		{
			if(l==r)
			{
				mx[root]=max(mx[root],v);
				return ;
			}
			int m=(l+r)>>1;
			if(p<=m) update(p,v,l,m,root<<1);
			else update(p,v,m+1,r,root<<1|1);
			mx[root]=max(mx[root<<1],mx[root<<1|1]);
		}
		int query(int L,int R,int l,int r,int root)
		{
			if(L<=l&&r<=R)
				return mx[root];

			int m=(l+r)>>1,res=0;

			if(L<=m) res=max(res,query(L,R,l,m,root<<1));
			if(m<R) res=max(res,query(L,R,m+1,r,root<<1|1));

			return res;
		}
	public:
		int lengthOfLIS(vector<int>& nums, int k) {
		const int n=nums.size();

		memset(mx,0,sizeof(mx));

		int res=0;
		for(int i=0;i<n;i++)
		{
			int v=query(max(0,nums[i]-k),max(0,nums[i]-1),0,100000,1)+1;

			res=max(res,v);
			update(nums[i],v,0,1e5,1);
		}

		return res;
		}
};


int main() 
{
	Solution s;
	vector<int> v={4,2,1,4,3,4,5,8,15};
	cout<<s.lengthOfLIS(v,3)<<endl;
	v.clear();v={7,4,5,1,8,12,4,7};
	cout<<s.lengthOfLIS(v,5)<<endl;
	v.clear();v={1,5};
	cout<<s.lengthOfLIS(v,1)<<endl;
	return 0;
}
