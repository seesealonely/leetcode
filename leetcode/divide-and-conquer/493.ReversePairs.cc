/*
   Given an integer array nums, return the number of reverse pairs in the array.

   A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 493.ReversePairs.cc head.cc head.h head.o lib.a l.sh nums[j].



   Example 1:

Input: nums = [1,3,2,3,1]
Output: 2

Example 2:

Input: nums = [2,4,3,5,1]
Output: 3



Constraints:

1 <= nums.length <= 5 493.ReversePairs.cc head.cc head.h head.o lib.a l.sh 104
-231 <= nums[i] <= 231 - 1

*/
#include"head.h"
class Solution {
	public:
		int reversePairs(vector<int>& nums) {
			if(nums.size()==0)
				return 0;
			vector<int> sorted(nums);
			return mergeSort(nums,sorted,0,nums.size()-1);
		}
		int mergeSort(vector<int> &nums,vector<int> &s,int left,int right)
		{
			if(left>=right)
				return 0;
			int mid=(left+right)>>1;
			int res=mergeSort(nums,s,left,mid)+mergeSort(nums,s,mid+1,right)+countPairs(nums,left,right);

			int l=left,r=mid+1,start=left;
			while(l<=mid&&r<=right)
			{
				if(nums[l]<=nums[r])
					s[start++]=nums[l++];
				else
					s[start++]=nums[r++];
			}
			while(l<=mid)s[start++]=nums[l++];
			while(r<right)s[start++]=nums[r++];

			for(int i=left;i<=right;i++)
				nums[i]=s[i];

			return res;
		}
		int countPairs(vector<int> &nums,int l,int r)
		{
			int res=0,mid=(l+r)>>1,i=l,j=mid+1;
			for(;i<=mid;i++)
			{
				while(j<=r&&(long) nums[i]>2*(long)nums[j])
				{
					res+=mid-i+1;
					j++;
				}
			}
			return res;
		}
};
int main() 
{
	Solution s;
	vector<int> v={1,3,2,3,1};
	cout<<s.reversePairs(v)<<endl;
	v.clear();v={2,4,3,5,1};
	cout<<s.reversePairs(v)<<endl;
	return 0;
}
