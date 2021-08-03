/*
   A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the same.

   Given an array of numbers arr, return true if the array can be rearranged to form an arithmetic progression. Otherwise, return false.



   Example 1:

Input: arr = [3,5,1]
Output: true
Explanation: We can reorder the elements as [1,3,5] or [5,3,1] with differences 2 and -2 respectively, between each consecutive elements.

Example 2:

Input: arr = [1,2,4]
Output: false
Explanation: There is no way to reorder the elements to obtain an arithmetic progression.



Constraints:

2 <= arr.length <= 1000
-106 <= arr[i] <= 106

*/
#include"head.h"
class Solution {
	public:
		bool canMakeArithmeticProgression(vector<int>& arr) {
		return usingSet(arr);
		return usingSort(arr);
		}
		bool usingSort(vector<int> &arr)
		{
			sort(arr.begin(),arr.end());
			for(int i=2;i<arr.size();i++)
				if(arr[i-2]-arr[i-1]!=arr[i-1]-arr[i])
					return false;
			return true;
		}
		bool usingSet(vector<int> &arr)
		{
			set<int> s;
			int mn=INT_MAX,mx=INT_MIN,n=arr.size(),sub=0;
			for(int i=0;i<n;i++)
			{
				mn=min(mn,arr[i]);
				mx=max(mx,arr[i]);
			}
			sub=(mx-mn)/(n-1);
			if((mx-mn)%(n-1)) return false;
			if(!sub) return true;
			for(int i=0;i<n;i++)
			{
				if(!s.insert(arr[i]).second)
					return false;
				if((arr[i]-mn)%sub)
					return false;
			}
			return true;
		}
};
