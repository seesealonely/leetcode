/*
   You are given two 0-indexed integer arrays servers and tasks of lengths n​​​​​​ and m​​​​​​ respectively. servers[i] is the weight of the i​​​​​​th​​​​ server, and tasks[j] is the time needed to process the j​​​​​​th​​​​ task in seconds.

   Tasks are assigned to the servers using a task queue. Initially, all servers are free, and the queue is empty.

   At second j, the jth task is inserted into the queue (starting with the 0th task being inserted at second 0). As long as there are free servers and the queue is not empty, the task in the front of the queue will be assigned to a free server with the smallest weight, and in case of a tie, it is assigned to a free server with the smallest index.

   If there are no free servers and the queue is not empty, we wait until a server becomes free and immediately assign the next task. If multiple servers become free at the same time, then multiple tasks from the queue will be assigned in order of insertion following the weight and index priorities above.

   A server that is assigned task j at second t will be free again at second t + tasks[j].

   Build an array ans​​​​ of length m, where ans[j] is the index of the server the j​​​​​​th task will be assigned to.

   Return the array ans​​​​.



   Example 1:

Input: servers = [3,3,2], tasks = [1,2,3,2,1,2]
Output: [2,2,0,2,1,2]
Explanation: Events in chronological order go as follows:
- At second 0, task 0 is added and processed using server 2 until second 1.
- At second 1, server 2 becomes free. Task 1 is added and processed using server 2 until second 3.
- At second 2, task 2 is added and processed using server 0 until second 5.
- At second 3, server 2 becomes free. Task 3 is added and processed using server 2 until second 5.
- At second 4, task 4 is added and processed using server 1 until second 5.
- At second 5, all servers become free. Task 5 is added and processed using server 2 until second 7.

Example 2:

Input: servers = [5,1,4,3,2], tasks = [2,1,2,4,5,2,1]
Output: [1,4,1,4,1,3,2]
Explanation: Events in chronological order go as follows: 
- At second 0, task 0 is added and processed using server 1 until second 2.
- At second 1, task 1 is added and processed using server 4 until second 2.
- At second 2, servers 1 and 4 become free. Task 2 is added and processed using server 1 until second 4. 
- At second 3, task 3 is added and processed using server 4 until second 7.
- At second 4, server 1 becomes free. Task 4 is added and processed using server 1 until second 9. 
- At second 5, task 5 is added and processed using server 3 until second 7.
- At second 6, task 6 is added and processed using server 2 until second 7.



Constraints:

servers.length == n
tasks.length == m
1 <= n, m <= 2 * 105
1 <= servers[i], tasks[j] <= 2 * 105

*/


#include"head.h"
class Solution {
	public:
		class  Idle
		{
			public:
			int w,idx;
		       Idle(int w,int idx)
		       {
			       this->w=w;
			       this->idx=idx;
		       }	       
		       bool operator <(const Idle &c) const
		       {
			       if(w!=c.w)
				       return c.w<w;
			       return c.idx<idx;
		       }
		};
		class Busy
		{
			public:
				int t,w,idx;
				Busy(int t,int w,int idx)
				{
					this->t=t;
					this->w=w;
					this->idx=idx;
				}
				bool operator <(const Busy & c) const
				{
					if(t!=c.t) 
						return t>c.t;
					if(w!=c.w)
						return w>c.w;
					return idx>c.idx;
				}
		};
		vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
		priority_queue<Idle> idle;
		priority_queue<Busy> busy;
	
		const int n=tasks.size(),m=servers.size();
		for(int i=0;i<m;i++)
			idle.push(Idle(servers[i],i));

		vector<int> res(n);
		for(int i=0;i<n;i++)
		{
			while(!busy.empty()&&busy.top().t<=i)
			{
				Busy s=busy.top();
				busy.pop();
				idle.push(Idle(servers[s.idx],s.idx));
			}

			if(!idle.empty())
			{
				Idle s=idle.top();
				idle.pop();

				res[i]=s.idx;
				busy.push(Busy(i+tasks[i],servers[s.idx],s.idx));
			}
			else
			{
				Busy s=busy.top();
				busy.pop();

				res[i]=s.idx;
				busy.push(Busy(s.t+tasks[i],servers[s.idx],s.idx));
			}
		}
		return res;
		}
};


int main() 
{
	Solution s;
	vector<int> servers={3,3,2},t={1,2,3,2,1,2};
	show(s.assignTasks(servers,t));
	servers.clear();servers={5,1,4,3,2};
	t.clear();t={2,1,2,4,5,2,1};
	show(s.assignTasks(servers,t));
	return 0;
}
