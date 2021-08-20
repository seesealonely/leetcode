/*
   Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.



   Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation:
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4].
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.

Example 2:

Input: arr = 9
Output: 444



Constraints:

1 <= arr.length <= 3*10^4 
1 <= arr[i] <= 3*10^4 

*/
#include"head.h"
class Solution {
	public:
		int sumSubarrayMins(vector<int>& arr) {
			int n=arr.size(),count=0,mod=1e9+7,res=0;
			vector<int> l(n,0),r(n,0);
			stack<pair<int,int> > s1,s2;
			for(int i=0;i<n;i++)
			{
				count=1;
				while(!s1.empty()&&s1.top().first>=arr[i])
				{
					count+=s1.top().second;
					s1.pop();
				}
				s1.push(make_pair(arr[i],count));
				l[i]=count;
			}	
			for(int i=n-1;i>=0;i--)
			{
				count=1;
				while(!s2.empty()&&s2.top().first>arr[i])
				{
					count+=s2.top().second;
					s2.pop();
				}
				s2.push(make_pair(arr[i],count));
				r[i]=count;
			}	
			for(int i=0;i<n;i++)
				res=(res+l[i]*arr[i]*r[i])%mod;
				
			return res;
		}
		int origin(vector<int>& arr) {
			int n=arr.size(),mod=1e9+7,sum=0,curmin;
			for(int i=0;i<n;i++)
			{
				curmin=arr[i];
				for(int j=i;j<n;j++)
				{
					curmin=min(arr[j],curmin);
					sum=(curmin+sum)%mod;
				}
			}
			return sum;
		}
};
