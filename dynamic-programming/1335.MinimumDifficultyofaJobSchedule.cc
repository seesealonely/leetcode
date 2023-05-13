/*
   You want to schedule a list of jobs in d days. Jobs are dependent (i.e To work on the ith job, you have to finish all the jobs j where 0 <= j < i).

   You have to finish at least one task every day. The difficulty of a job schedule is the sum of difficulties of each day of the d days. The difficulty of a day is the maximum difficulty of a job done on that day.

   You are given an integer array jobDifficulty and an integer d. The difficulty of the ith job is jobDifficulty[i].

   Return the minimum difficulty of a job schedule. If you cannot find a schedule for the jobs return -1.



   Example 1:

Input: jobDifficulty = [6,5,4,3,2,1], d = 2
Output: 7
Explanation: First day you can finish the first 5 jobs, total difficulty = 6.
Second day you can finish the last job, total difficulty = 1.
The difficulty of the schedule = 6 + 1 = 7

Example 2:

Input: jobDifficulty = [9,9,9], d = 4
Output: -1
Explanation: If you finish a job per day you will still have a free day. you cannot find a schedule for the given jobs.

Example 3:

Input: jobDifficulty = [1,1,1], d = 3
Output: 3
Explanation: The schedule is one job per day. total difficulty will be 3.



Constraints:

1 <= jobDifficulty.length <= 300
0 <= jobDifficulty[i] <= 1000
1 <= d <= 10

*/


#include"head.h"
class Solution {
	public:
		int minDifficulty(vector<int>& jobDifficulty, int d) {
		const int n=jobDifficulty.size();
		 const int MAX = 1000000000;

		vector<vector<int>> mx(n+1,vector<int>(n+1,0));
		for(int i=1;i<=n;i++)
		{
			mx[i][i]=jobDifficulty[i-1];
			for(int j=i+1;j<=n;j++)
				mx[i][j]=max(mx[i][j-1],jobDifficulty[j-1]);
		}

		vector<vector<int>> dp(n+1,vector<int>(d+1,MAX));
		dp[0][0]=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=min(d,i);j++)
				for(int k=0;k<i;k++)
				dp[i][j]=min(dp[i][j],dp[k][j-1]+mx[k+1][i]);
		return dp[n][d]==MAX?-1:dp[n][d];
		}
};


int main() 
{
	Solution s;
	vector<int> jobDifficulty={6,5,4,3,2,1};
	cout<<s.minDifficulty(jobDifficulty,2)<<endl;
	jobDifficulty.clear();jobDifficulty={9,9,9};
	cout<<s.minDifficulty(jobDifficulty,4)<<endl;
	jobDifficulty.clear();jobDifficulty={1,1,1};
	cout<<s.minDifficulty(jobDifficulty,3)<<endl;
	return 0;
}
