/*
   Given two integer arrays arr1 and arr2, return the minimum number of operations (possibly zero) needed to make arr1 strictly increasing.

   In one operation, you can choose two indices 0 <= i < arr1.length and 0 <= j < arr2.length and do the assignment arr1[i] = arr2[j].

   If there is no way to make arr1 strictly increasing, return -1.



   Example 1:

Input: arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
Output: 1
Explanation: Replace 5 with 2, then arr1 = [1, 2, 3, 6, 7].

Example 2:

Input: arr1 = [1,5,3,6,7], arr2 = [4,3,1]
Output: 2
Explanation: Replace 5 with 3 and then replace 3 with 4. arr1 = [1, 3, 4, 6, 7].

Example 3:

Input: arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]
Output: -1
Explanation: You can't make arr1 strictly increasing.



Constraints:

1 <= arr1.length, arr2.length <= 2000
0 <= arr1[i], arr2[i] <= 10^9
*/


#include"head.h"
class Solution {
	public:
		int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
		const int n=arr1.size();
		sort(arr2.begin(),arr2.end());

		vector<vector<int>> dp(n,vector<int>(n+1,INT_MAX));

		dp[0][0]=arr1[0];
		dp[0][1]=arr2[0];

		for(int i=1;i<n;i++)
			for(int j=0;j<=i+1;j++)
			{
				if(arr1[i]>dp[i-1][j])
					dp[i][j]=min(dp[i][j],arr1[i]);

				if(j>0)
					if(dp[i-1][j-1]<INT_MAX)
					{
						vector<int>::iterator hi=upper_bound(arr2.begin(),arr2.end(),dp[i-1][j-1]);
						if(hi!=arr2.end())
							dp[i][j]=min(dp[i][j],*hi);
					}
			}
		for(int i=0;i<=n;i++)
			if(dp[n-1][i]!=INT_MAX)
				return i;
		return -1;
		}
};


int main() 
{
	Solution s;
	vector<int> v1={1,5,3,6,7},v2={1,3,2,4};
	cout<<s.makeArrayIncreasing(v1,v2)<<endl;
	v2.clear();v2={4,3,1};
	cout<<s.makeArrayIncreasing(v1,v2)<<endl;
	v2.clear();v2={1,6,3,3};
	cout<<s.makeArrayIncreasing(v1,v2)<<endl;
	return 0;
}
