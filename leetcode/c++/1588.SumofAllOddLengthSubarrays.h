/*
   Given an array of positive integers arr, calculate the sum of all possible odd-length subarrays.

   A subarray is a contiguous subsequence of the array.

   Return the sum of all odd-length subarrays of arr.



   Example 1:

Input: arr = [1,4,2,5,3]
Output: 58
Explanation: The odd-length subarrays of arr and their sums are:
[1] = 1
[4] = 4
[2] = 2
[5] = 5
[3] = 3
[1,4,2] = 7
[4,2,5] = 11
[2,5,3] = 10
[1,4,2,5,3] = 15
If we add all these together we get 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58

Example 2:

Input: arr = [1,2]
Output: 3
Explanation: There are only 2 subarrays of odd length, [1] and [2]. Their sum is 3.

Example 3:

Input: arr = [10,11,12]
Output: 66



Constraints:

1 <= arr.length <= 100
1 <= arr[i] <= 1000

*/
#include"head.h"
#include<numeric>
class Solution {
	public:
		int sumOddLengthSubarrays(vector<int>& arr) {
		return countCurNum(arr);
		return preSum(arr);
		return origin(arr);
		}
		int origin(vector<int>& arr) {
		int n=arr.size(),res=0;
		for(int i=0;i<n;i++)
			for(int j=1;i+j<=n;j+=2)
			res+=accumulate(arr.begin()+i,arr.begin()+i+j,0);
		return res;
		}
		int preSum(vector<int>& arr) {
			vector<int> presum;
			int n=arr.size(),res=0;
			presum.push_back(0);
			for(int i=0;i<n;i++)
				presum.push_back(presum.back()+arr[i]);
			for(int i=0;i<n;i++)
				for(int j=1;i+j<=n;j+=2)
					res+=presum[i+j]-presum[i];
			return res;
		}
		int countCurNum(vector<int>& arr) {
			int n=arr.size(),l=0,r=0,lo=0,le=0,ro=0,re=0,res=0;
			for(int i=0;i<n;i++)
			{
				l=i,r=n-i-1;
				lo=(l+1)/2;le=l/2+1;
				ro=(r+1)/2;re=r/2+1;
				res+=(lo*ro+le*re)*arr[i];
			}
			return res;
		}
};
