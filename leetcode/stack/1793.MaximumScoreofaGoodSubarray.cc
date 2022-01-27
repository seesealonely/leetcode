/*
   You are given an array of integers nums (0-indexed) and an integer k.

   The score of a subarray (i, j) is defined as min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1). A good subarray is a subarray where i <= k <= j.

   Return the maximum possible score of a good subarray.



   Example 1:

Input: nums = [1,4,3,7,4,5], k = 3
Output: 15
Explanation: The optimal subarray is (1, 5) with a score of min(4,3,7,4,5) * (5-1+1) = 3 * 5 = 15. 

Example 2:

Input: nums = [5,5,4,5,4,1,1,1], k = 0
Output: 20
Explanation: The optimal subarray is (0, 4) with a score of min(5,5,4,5,4) * (4-0+1) = 4 * 5 = 20.



Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 2 * 104
0 <= k < nums.length

*/
#include"head.h"
class Solution {
	public:
		int maximumScore(vector<int>& nums, int k) {
			const int n=nums.size();
			vector<int> l(n,0),r(n,0);

			stack<int> st;
			for(int i=0;i<n;i++)
			{
				while(!st.empty()&&nums[i]<=nums[st.top()])
					st.pop();
					l[i]=(st.empty()?0:st.top()+1);
					st.push(i);
			}

			st=stack<int>();
			for(int i=n-1;i>=0;i--)
			{
				while(!st.empty()&&nums[i]<=nums[st.top()])
					st.pop();
					r[i]=(st.empty()?n-1:st.top()-1);
					st.push(i);
			}

			int res=0;
			for(int i=0;i<n;i++)
				if(l[i]<=k&&r[i]>k)
				res=max(res,nums[i]*(r[i]-l[i]+1));

			return res;
		}
};
int main() 
{
	Solution s;
	vector<int> v={1,4,3,7,4,5};
	cout<<s.maximumScore(v,3)<<endl;
	v.clear();v={5,5,4,5,4,1,1,1};
	cout<<s.maximumScore(v,0)<<endl;
	return 0;
}
