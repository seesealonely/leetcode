/*
   You are given 2 integer arrays nums1 and nums2 of lengths n and m respectively. You are also given a positive integer k.

   A pair (i, j) is called good if nums1[i] is divisible by nums2[j] * k (0 <= i <= n - 1, 0 <= j <= m - 1).

   Return the total number of good pairs.



   Example 1:

Input: nums1 = [1,3,4], nums2 = [1,3,4], k = 1

Output: 5

Explanation:
The 5 good pairs are (0, 0), (1, 0), (1, 1), (2, 0), and (2, 2).

Example 2:

Input: nums1 = [1,2,4,12], nums2 = [2,4], k = 3

Output: 2

Explanation:

The 2 good pairs are (3, 0) and (3, 1).



Constraints:

1 <= n, m <= 50
1 <= nums1[i], nums2[j] <= 50
1 <= k <= 50

*/

#define c11
#include"head.h"
class Solution {
	public:
		int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
			unordered_map<int,int> cnt;
			const int n1=nums1.size(),n2=nums2.size();
			for(int i=0;i<n1;i++)
			{
				int x=nums1[i];
				if(x%k)
					continue;
				x/=k;
				for(int j=1;j*j<=x;j++)
				{
					if(x%j)
						continue;
					cnt[j]++;
					if(j*j<x)
						cnt[x/j]++;
				}
			}
			int res=0;
			for(int i=0;i<n2;i++)
				res+=cnt.find(nums2[i])!=cnt.end()?cnt[nums2[i]]:0;
			return res;
		}
};


int main() 
{
	Solution s;
	vector<int> nums1={1,3,4},nums2={1,3,4};
	cout<<s.numberOfPairs(nums1,nums2,1)<<endl;
	nums1.clear();nums2.clear();
	nums1={1,2,4,12};nums2={2,4};
	cout<<s.numberOfPairs(nums1,nums2,3)<<endl;
	return 0;
}
