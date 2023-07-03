/*
   Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

   The overall run time complexity should be O(log (m+n)).



   Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.



Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106

*/


#include"head.h"
class Solution {
	public:
		double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int tot=nums1.size()+nums2.size();
		if(tot%2==0)
		{
			int l=dfs(nums1,0,nums2,0,tot/2);
			int r=dfs(nums1,0,nums2,0,tot/2+1);
			return (l+r)/2.0;
		}
		else
			return dfs(nums1,0,nums2,0,tot/2+1);
		}
		int dfs(vector<int> nums1,int i,vector<int>nums2,int j,int k)
		{
			if(nums1.size()-i>nums2.size()-j) return dfs(nums2,j,nums1,i,k);
			if(nums1.size()==i) return nums2[j+k-1];

			if(k==1) return min(nums1[i],nums2[j]);

			int si=min((int)nums1.size(),i+k/2),sj=j+k-k/2;
			if(nums1[si-1]>nums2[sj-1])
				return dfs(nums1,i,nums2,sj,k-(sj-j));
			else
				return dfs(nums1,si,nums2,j,k-(si-i));
		}
};


int main() 
{
	Solution s;
	vector<int> nums1 = {1,3}, nums2 = {2};
	cout<<s.findMedianSortedArrays(nums1,nums2)<<endl;
	nums1.clear();nums2.clear();
	nums1={1,2};nums2={3,4};
	cout<<s.findMedianSortedArrays(nums1,nums2)<<endl;
	return 0;
}
