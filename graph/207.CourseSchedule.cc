/*
   There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

   For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

   Return true if you can finish all courses. Otherwise, return false.



   Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0. So it is possible.

Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.



Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.

*/

#define c11
#include"head.h"
class Solution {
    public:
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            unordered_map<int,int> indegree;
            unordered_map<int,unordered_set<int>> g;
            const int n=prerequisites.size();
            for(int i=0;i<n;i++)
            {
                indegree[prerequisites[i][0]]++;
                g[prerequisites[i][1]].insert(prerequisites[i][0]);
            }

            queue<int> q;
            for(int i=0;i<numCourses;i++)
                if(!indegree[i])
                    q.push(i);

            int cnt=0;
            while(!q.empty())
            {
                int cur=q.front();q.pop();
                for(unordered_set<int>::iterator it=g[cur].begin();it!=g[cur].end();it++)
                {
                    if(--indegree[*it]==0)
                        q.push(*it);
                }
                cnt++;
            }
            return cnt==numCourses;
        }
};


int main() 
{
    Solution s;
    vector<vector<int>> v={{1,0}};
    cout<<s.canFinish(2,v)<<endl;
    v.clear();v={{1,0},{0,1}};
    cout<<s.canFinish(2,v)<<endl;
    v.clear();v={{0,1}};
    cout<<s.canFinish(2,v)<<endl;
    return 0;
}
