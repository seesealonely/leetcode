/*
   There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course ai first if you want to take course bi.

   For example, the pair [0, 1] indicates that you have to take course 0 before you can take course 1.

   Prerequisites can also be indirect. If course a is a prerequisite of course b, and course b is a prerequisite of course c, then course a is a prerequisite of course c.

   You are also given an array queries where queries[j] = [uj, vj]. For the jth query, you should answer whether course uj is a prerequisite of course vj or not.

   Return a boolean array answer, where answer[j] is the answer to the jth query.



   Example 1:

Input: numCourses = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
Output: [false,true]
Explanation: The pair [1, 0] indicates that you have to take course 1 before you can take course 0.
Course 0 is not a prerequisite of course 1, but the opposite is true.

Example 2:

Input: numCourses = 2, prerequisites = [], queries = [[1,0],[0,1]]
Output: [false,false]
Explanation: There are no prerequisites, and each course is independent.

Example 3:

Input: numCourses = 3, prerequisites = [[1,2],[1,0],[2,0]], queries = [[1,0],[1,2]]
Output: [true,true]



Constraints:

2 <= numCourses <= 100
0 <= prerequisites.length <= (numCourses * (numCourses - 1) / 2)
prerequisites[i].length == 2
0 <= ai, bi <= n - 1
ai != bi
All the pairs [ai, bi] are unique.
The prerequisites graph has no cycles.
1 <= queries.length <= 104
0 <= ui, vi <= n - 1
ui != vi

*/


#include"head.h"
class Solution {
    public:
        vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
            int n=numCourses;
            vector<vector<bool>> tag(n,vector<bool>(n,false));
            vector<vector<int>> g(n);

            for(int i=0;i<prerequisites.size();i++)
                g[prerequisites[i][0]].push_back(prerequisites[i][1]);

            queue<int> q;
            for(int i=0;i<n;i++)
            {
                queue<int> q;q.push(i);
                tag[i][i]=true;
                while(!q.empty())
                {
                    int cur=q.front();q.pop();
                    for(int j=0;j<g[cur].size();j++)
                    {
                        if(tag[i][g[cur][j]]==false)
                        {
                            tag[i][g[cur][j]]=true;
                            q.push(g[cur][j]);
                        }
                    }
                }
            }

            vector<bool> res;
            for(int i=0;i<queries.size();i++)
                res.push_back(tag[queries[i][0]][queries[i][1]]);

            return res;
        }
};


int main() 
{
    Solution s;
    vector<vector<int>> p={{1,0}},q={{0,1},{1,0}};
    show(s.checkIfPrerequisite(2,p,q));
    p.clear();
    q.clear();q={{1,0},{0,1}};
    show(s.checkIfPrerequisite(2,p,q));
    return 0;
}
