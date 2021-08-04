/*
   Given an array of integers arr. Return the number of sub-arrays with odd sum.

   As the answer may grow large, the answer must be computed modulo 10^9 + 7.



   Example 1:

Input: arr = [1,3,5]
Output: 4
Explanation: All sub-arrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
All sub-arrays sum are [1,4,9,3,8,5].
Odd sums are 9 so the answer is 4.

Example 2:

Input: arr = [2,4,6]
Output: 0
Explanation: All sub-arrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
All sub-arrays sum are [2,6,12,4,10,6].
All sub-arrays have even sum and the answer is 0.

Example 3:

Input: arr = [1,2,3,4,5,6,7]
Output: 16

Example 4:

Input: arr = 9
Output: 4

Example 5:

Input: arr = [7]
Output: 1



Constraints:

1 <= arr.length <= 10^5
1 <= arr[i] <= 100
*/
#include"head.h"
class Solution {
	public:
		int numOfSubarrays(vector<int>& arr) {
			return twoWay(arr);
			return oneWay(arr);
		}
		int oneWay(vector<int> &arr)
		{
			int odd=0,even=0,res=0,n=arr.size(),mod=1e9+7,tmp=0;
			for(int i=0;i<n;i++)
			{
				if(arr[i]%2)
				{
					tmp=even;
					even=odd;	
					odd=tmp;
					odd+=1;
				}
				else 
					even++;
				res=(res+odd)%mod;
			}
			return res;
		}
		int twoWay(vector<int> &arr)
		{
			int odd=0,even=0,res=0,n=arr.size(),mod=1e9+7;
			for(int i=0;i<n;i++)
			{
				if(arr[i]%2)
				{
					swap(odd,even);  //even +cur is odd ,odd+ cur is even.
					odd++;
				}
				else 
					even++;
				res=(res+odd)%mod;
			}
			return res;
		}
};
