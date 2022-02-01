/*
   You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

   Return the sum of all subarray ranges of nums.

   A subarray is a contiguous non-empty sequence of elements within an array.



   Example 1:

Input: nums = [1,2,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.

Example 2:

Input: nums = [1,3,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[3], range = 3 - 3 = 0
[3], range = 3 - 3 = 0
[1,3], range = 3 - 1 = 2
[3,3], range = 3 - 3 = 0
[1,3,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.

Example 3:

Input: nums = [4,-2,-3,4,1]
Output: 59
Explanation: The sum of all subarray ranges of nums is 59.



Constraints:

1 <= nums.length <= 1000
-109 <= nums[i] <= 109

*/
#include"head.h"
class Solution {
	public:
		long long subArrayRanges(vector<int>& nums) {
			return maxs(nums)-mins(nums);
		}
		long long maxs(vector<int>& nums) {
			const int n=nums.size();
			vector<int> l(n,0),r(n,0);
			stack<pair<int,int>> st;
			long long int res=0;
			for(int i=0;i<n;i++)
			{
				int count=1;
				while(!st.empty()&&nums[st.top().first]<nums[i])
				{
					count+=st.top().second;
					st.pop();
				}
				l[i]=count;
				st.push({i,count});
			}
			st=stack<pair<int,int>>();
			for(int i=n-1;i>=0;i--)
			{
				int count=1;
				while(!st.empty()&&nums[st.top().first]<=nums[i])
				{
					count+=st.top().second;
					st.pop();
				}
				r[i]=count;
				st.push({i,count});
			}
			for(int i=0;i<n;i++)
				res+=(long long int)nums[i]*l[i]*r[i];
			return res;
		}
		long long mins(vector<int>& nums) {
			const int n=nums.size();
			vector<int> l(n,0),r(n,0);
			stack<pair<int,int>> st;
			long long int res=0;
			for(int i=0;i<n;i++)
			{
				int count=1;
				while(!st.empty()&&nums[st.top().first]>nums[i])
				{
					count+=st.top().second;
					st.pop();
				}
				l[i]=count;
				st.push({i,count});
			}
			st=stack<pair<int,int>>();
			for(int i=n-1;i>=0;i--)
			{
				int count=1;
				while(!st.empty()&&nums[st.top().first]>=nums[i])
				{
					count+=st.top().second;
					st.pop();
				}
				r[i]=count;
				st.push({i,count});
			}
			for(int i=0;i<n;i++)
				res+=(long long int)nums[i]*l[i]*r[i];
			return res;
		}

};
int main() 
{
	Solution s;
	vector<int> v={1,2,3};
	cout<<s.subArrayRanges(v)<<endl;
	v.clear();v={1,3,3};
	cout<<s.subArrayRanges(v)<<endl;
	v.clear();v={4,-2,-3,4,1};
	cout<<s.subArrayRanges(v)<<endl;
	return 0;
}
