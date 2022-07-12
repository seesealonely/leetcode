/*
   You are given an integer array jobs, where jobs[i] is the amount of time it takes to complete the ith job.

   There are k workers that you can assign jobs to. Each job should be assigned to exactly one worker. The working time of a worker is the sum of the time it takes to complete all jobs assigned to them. Your goal is to devise an optimal assignment such that the maximum working time of any worker is minimized.

   Return the minimum possible maximum working time of any assignment.



   Example 1:

Input: jobs = [3,2,3], k = 3
Output: 3
Explanation: By assigning each person one job, the maximum time is 3.

Example 2:

Input: jobs = [1,2,4,7,8], k = 2
Output: 11
Explanation: Assign the jobs the following way:
Worker 1: 1, 2, 8 (working time = 1 + 2 + 8 = 11)
Worker 2: 4, 7 (working time = 4 + 7 = 11)
The maximum working time is 11.



Constraints:

1 <= k <= jobs.length <= 12
1 <= jobs[i] <= 107

*/
#include"head.h"
class Solution {
	public:
		int minimumTimeRequired(vector<int>& jobs, int k) {
		const int n=jobs.size();
		vector<vector<int> > dp(k,vector<int>((1<<n),0));
		vector<int> sum((1<<n),0);
		for(int i=0;i<(1<<n);i++)
			for(int j=0;j<n;j++)
			if((i&(1<<j)))
				sum[i]+=jobs[j];
		
		for(int i=0;i<(1<<n);i++)
			dp[0][i]=sum[i];

		for(int i=1;i<k;i++)
			for(int j=0;j<(1<<n);j++)
			{
				int mn=INT_MAX;
				for(int x=j;x;x=(x-1)&j)
					mn=min(mn,max(dp[i-1][j-x],sum[x]));
				dp[i][j]=mn;
			}
		return dp[k-1][(1<<n)-1];
		}
};
int main() 
{
	Solution s;
	vector<int> v={3,2,3};
	cout<<s.minimumTimeRequired(v,3)<<endl;
	v.clear();v={1,2,4,7,8};
	cout<<s.minimumTimeRequired(v,2)<<endl;
	return 0;
}
