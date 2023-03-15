/*
   There is a computer that can run an unlimited number of tasks at the same time. You are given a 2D integer array tasks where tasks[i] = [starti, endi, durationi] indicates that the ith task should run for a total of durationi seconds (not necessarily continuous) within the inclusive time range [starti, endi].

   You may turn on the computer only when it needs to run a task. You can also turn it off if it is idle.

   Return the minimum time during which the computer should be turned on to complete all tasks.



   Example 1:

Input: tasks = [[2,3,1],[4,5,1],[1,5,2]]
Output: 2
Explanation:
- The first task can be run in the inclusive time range [2, 2].
- The second task can be run in the inclusive time range [5, 5].
- The third task can be run in the two inclusive time ranges [2, 2] and [5, 5].
The computer will be on for a total of 2 seconds.

Example 2:

Input: tasks = [[1,3,2],[2,5,3],[5,6,2]]
Output: 4
Explanation:
- The first task can be run in the inclusive time range [2, 3].
- The second task can be run in the inclusive time ranges [2, 3] and [5, 5].
- The third task can be run in the two inclusive time range [5, 6].
The computer will be on for a total of 4 seconds.



Constraints:

1 <= tasks.length <= 2000
tasks[i].length == 3
1 <= starti, endi <= 2000
1 <= durationi <= endi - starti + 1

*/


#include"head.h"
class Solution {
	public:
		int findMinimumTime(vector<vector<int>>& tasks) {
		const int n=tasks.size();

		sort(tasks.begin(),tasks.end(),cmp);
		vector<int> vis(2001,false);

		int res=0;
		for(int i=0;i<n;i++)
		{
			int s=tasks[i][0],e=tasks[i][1],d=tasks[i][2];
			for(int j=s;j<=e;j++)
				d-=vis[j];
			for(int j=e;d>0;j--)
				if(!vis[j])
				{
					vis[j]=true;
					d--;
					res++;
				}
		}
		return res;
		}
		static bool cmp(vector<int>&x,vector<int> &y)
		{
			return x[1]<y[1];
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> v={{2,3,1},{4,5,1},{1,5,2}};
	cout<<s.findMinimumTime(v)<<endl;
	v.clear();v={{1,3,2},{2,5,3},{5,6,2}};
	cout<<s.findMinimumTime(v)<<endl;
	return 0;
}
