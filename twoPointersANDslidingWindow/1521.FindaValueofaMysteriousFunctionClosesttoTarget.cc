/*
   func(arr, l, r) {
   if (r < l) {
   return -1000000000;
   }
   ans = arr[l]
   for (i = l + 1; i < r; i++) {
   ans = ans & arr[i]
   }
   return ans
   }
   Winston was given the above mysterious function func. He has an integer array arr and an integer target and he wants to find the values l and r that make the value |func(arr, l, r) - target| minimum possible.

   Return the minimum possible value of |func(arr, l, r) - target|.

   Notice that func should be called with the values l and r where 0 <= l, r < arr.length.



   Example 1:

Input: arr = [9,12,3,7,15], target = 5
Output: 2
Explanation: Calling func with all the pairs of [l,r] = [[0,0],[1,1],[2,2],[3,3],[4,4],[0,1],[1,2],[2,3],[3,4],[0,2],[1,3],[2,4],[0,3],[1,4],[0,4]], Winston got the following results [9,12,3,7,15,8,0,3,7,0,0,3,0,0,0]. The value closest to 5 is 7 and 3, thus the minimum difference is 2.

Example 2:

Input: arr = [1000000,1000000,1000000], target = 1
Output: 999999
Explanation: Winston called the func with all possible values of [l,r] and he always got 1000000, thus the min difference is 999999.

Example 3:

Input: arr = [1,2,4,8,16], target = 0
Output: 0



Constraints:

1 <= arr.length <= 105
1 <= arr[i] <= 106
0 <= target <= 107
*/


#include"head.h"
class Solution {
	public:
		const int m=24;
		void add(vector<int>&cnt,int x,int &sum)
		{
			for(int i=0;i<m;i++)
			if(!((x>>i)&1))
			{
				cnt[i]++;
				if(cnt[i]==1)
					sum^=1<<i;
			}
		}
		void remove(vector<int>&cnt,int x,int &sum)
		{
			for(int i=0;i<m;i++)
				if(!((x>>i)&1))
				{
					cnt[i]--;
					if(cnt[i]==0)
						sum|=1<<i;
				}
		}
		int closestToTarget(vector<int>& arr, int target) {
		const int n=arr.size();
		vector<int> cnt(m,0);
		int res=INT_MAX,sum=(1<<m)-1;
		for(int l=0,r=0;r<n;r++)
		{
			add(cnt,arr[r],sum);
			res=min(res,abs(sum-target));
			while(sum<target)
			{
				remove(cnt,arr[l++],sum);
				res=min(res,abs(sum-target));
			}
		}
		return res;
		}
};


int main() 
{
	Solution s;
	vector<int> arr = {9,12,3,7,15};
	cout<<s.closestToTarget(arr,5)<<endl;
	arr.clear();arr={1000000,1000000,1000000};
	cout<<s.closestToTarget(arr,1)<<endl;
	return 0;
}
