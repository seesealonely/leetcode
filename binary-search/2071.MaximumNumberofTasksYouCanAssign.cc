/*
   You have n tasks and m workers. Each task has a strength requirement stored in a 0-indexed integer array tasks, with the ith task requiring tasks[i] strength to complete. The strength of each worker is stored in a 0-indexed integer array workers, with the jth worker having workers[j] strength. Each worker can only be assigned to a single task and must have a strength greater than or equal to the task's strength requirement (i.e., workers[j] >= tasks[i]).

   Additionally, you have pills magical pills that will increase a worker's strength by strength. You can decide which workers receive the magical pills, however, you may only give each worker at most one magical pill.

   Given the 0-indexed integer arrays tasks and workers and the integers pills and strength, return the maximum number of tasks that can be completed.

    

   Example 1:

Input: tasks = [3,2,1], workers = [0,3,3], pills = 1, strength = 1
Output: 3
Explanation:
We can assign the magical pill and tasks as follows:
- Give the magical pill to worker 0.
- Assign worker 0 to task 2 (0 + 1 >= 1)
- Assign worker 1 to task 1 (3 >= 2)
- Assign worker 2 to task 0 (3 >= 3)

Example 2:

Input: tasks = [5,4], workers = [0,0,0], pills = 1, strength = 5
Output: 1
Explanation:
We can assign the magical pill and tasks as follows:
- Give the magical pill to worker 0.
- Assign worker 0 to task 0 (0 + 5 >= 5)

Example 3:

Input: tasks = [10,15,30], workers = [0,10,10,10,10], pills = 3, strength = 10
Output: 2
Explanation:
We can assign the magical pills and tasks as follows:
- Give the magical pill to worker 0 and worker 1.
- Assign worker 0 to task 0 (0 + 10 >= 10)
- Assign worker 1 to task 1 (10 + 10 >= 15)
The last pill is not given because it will not make any worker strong enough for the last task.

 

Constraints:

n == tasks.length
m == workers.length
1 <= n, m <= 5 * 104
0 <= pills <= m
0 <= tasks[i], workers[j], strength <= 109

*/


#include"head.h"
class Solution {
    public:
        int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end());
        int l=0,r=min(tasks.size(),workers.size());
        while(l<r)
        {
            int m=(l+r+1)>>1;
            if(check(tasks,workers,m,pills,strength))
                l=m;
            else
                r=m-1;
        }

        return l;
        }
        bool check(const vector<int> &tasks,const vector<int> &workers,int m,int pills,int strength)
        {
            deque<int> q;
            int tail=workers.size()-1;
            for(int i=m-1;i>=0;i--)
            {
                if(q.empty()) q.push_back(workers[tail--]);
                if(tasks[i]<=q.front()) q.pop_front();
                else
                {
                    if(pills==0||tasks[i]-strength>q.front())
                        return false;

                    pills--;
                    while(tail>=0&&tasks[i]-strength<=workers[tail])
                        q.push_back(workers[tail--]);

                    q.pop_back();
                }
            }
            return true;
        }
};


int main() 
{
    Solution s;
    vector<int> t={3,2,1},w={0,3,3};
    cout<<s.maxTaskAssign(t,w,1,1)<<endl;
    t.clear();t={5,4};
    w.clear();w={0,0,0};
    cout<<s.maxTaskAssign(t,w,1,5)<<endl;
    t.clear();t={10,15,30};
    w.clear();w={0,10,10,10,10};
    cout<<s.maxTaskAssign(t,w,3,10)<<endl;
    t.clear();t={5,9,8,5,9};
    w.clear();w={1,6,4,2,6};
    cout<<s.maxTaskAssign(t,w,1,5)<<endl;
    return 0;
}
