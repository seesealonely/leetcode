/*
   You are given a 0-indexed 2D integer array nums representing the coordinates of the cars parking on a number line. For any index i, nums[i] = [starti, endi] where starti is the starting point of the ith car and endi is the ending point of the ith car.

   Return the number of integer points on the line that are covered with any part of a car.



   Example 1:

Input: nums = [[3,6],[1,5],[4,7]]
Output: 7
Explanation: All the points from 1 to 7 intersect at least one car, therefore the answer would be 7.

Example 2:

Input: nums = [[1,3],[5,8]]
Output: 7
Explanation: Points intersecting at least one car are 1, 2, 3, 5, 6, 7, 8. There are a total of 7 points, therefore the answer would be 7.



Constraints:

1 <= nums.length <= 100
nums[i].length == 2
1 <= starti <= endi <= 100

*/


#include"head.h"
class Solution {
	public:
		int numberOfPoints(vector<vector<int>>& nums) {
		int mx=0,mn=INT_MAX,n=nums.size();
		for(int i=0;i<n;i++)
		{
			mn=min(mn,nums[i][0]);
			mx=max(mx,nums[i][1]);
		}
		vector<int> sub(mx+2,0);

		for(int i=0;i<n;i++)
		{
			int s=nums[i][0],e=nums[i][1];
			sub[s]+=1;
			sub[e+1]-=1;
		}
	
		int res=0;
		for(int i=mn;i<=mx;i++)
		{
			sub[i]+=sub[i-1];
			if(sub[i]>0)
				res++;
		}
		return res;
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> nums = {{3,6},{1,5},{4,7}};
	cout<<s.numberOfPoints(nums)<<endl;
	nums.clear();nums={{1,3},{5,8}};
	cout<<s.numberOfPoints(nums)<<endl;
	return 0;
}
