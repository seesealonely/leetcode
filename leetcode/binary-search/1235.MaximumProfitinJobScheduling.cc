/*
   We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

   You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

   If you choose a job that ends at time X you will be able to start another job that starts at time X.



   Example 1:

Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job.
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.

Example 2:

Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
Output: 150
Explanation: The subset chosen is the first, fourth and fifth job.
Profit obtained 150 = 20 + 70 + 60.

Example 3:

Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
Output: 6



Constraints:

1 <= startTime.length == endTime.length == profit.length <= 5 * 104
1 <= startTime[i] < endTime[i] <= 109
1 <= profit[i] <= 104
*/
#include"head.h"
class Solution {
	public:
		int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
			const int n=startTime.size();
			vector<vector<int> > jobs(n);
			vector<int> dp(n,INT_MIN);
			for(int i=0;i<n;i++)
			{
				jobs[i].push_back(startTime[i]);
				jobs[i].push_back(endTime[i]);
				jobs[i].push_back(profit[i]);
			}
			sort(jobs.begin(),jobs.end(),cmp);
			dp[0]=jobs[0][2];
			for(int i=1;i<n;i++)
			{
				int l=0,r=i-1;
				while(l<r)
				{
					int m=(l+r)>>1;
					if(jobs[m+1][1]<=jobs[i][0])
						l=m+1;
					else
						r=m;
				}
				if(jobs[l][1]<=jobs[i][0])
					dp[i]=max(dp[i-1],dp[l]+jobs[i][2]);
				else
					dp[i]=max(dp[i-1],jobs[i][2]);
			}
			return dp[n-1];
		}
		static bool cmp(vector<int> &a,vector<int> &b)
		{
			return a[1]<b[1];
		}
};
int main() 
{
	Solution s;
	vector<int> v1={1,2,3,3},v2={3,4,5,6},v3={50,10,40,70};
	cout<<s.jobScheduling(v1,v2,v3)<<endl;
	v1.clear();v2.clear();v3.clear();
	v1={1,2,3,4,6},v2={3,5,10,6,9},v3={20,20,100,70,60};
	cout<<s.jobScheduling(v1,v2,v3)<<endl;
	v1.clear();v2.clear();v3.clear();
	v1={1,1,1},v2={2,3,4},v3={5,6,4};
	cout<<s.jobScheduling(v1,v2,v3)<<endl;
	return 0;
}
