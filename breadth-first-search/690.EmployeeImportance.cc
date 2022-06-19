/*
   You have a data structure of employee information, including the employee's unique ID, importance value, and direct subordinates' IDs.

   You are given an array of employees employees where:

   employees[i].id is the ID of the ith employee.
   employees[i].importance is the importance value of the ith employee.
   employees[i].subordinates is a list of the IDs of the direct subordinates of the ith employee.

   Given an integer id that represents an employee's ID, return the total importance value of this employee and all their direct and indirect subordinates.



   Example 1:

Input: employees = [[1,5,[2,3]],[2,3,[]],[3,3,[]]], id = 1
Output: 11
Explanation: Employee 1 has an importance value of 5 and has two direct subordinates: employee 2 and employee 3.
They both have an importance value of 3.
Thus, the total importance value of employee 1 is 5 + 3 + 3 = 11.

Example 2:

Input: employees = [[1,2,[5]],[5,-3,[]]], id = 5
Output: -3
Explanation: Employee 5 has an importance value of -3 and has no direct subordinates.
Thus, the total importance value of employee 5 is -3.



Constraints:

1 <= employees.length <= 2000
1 <= employees[i].id <= 2000
All employees[i].id are unique.
-100 <= employees[i].importance <= 100
One employee has at most one direct leader and may have several subordinates.
The IDs in employees[i].subordinates are valid IDs.

*/

#define c11
#include"head.h"
class Employee {
    public:
        int id;
        int importance;
        vector<int> subordinates;
};
class Solution {
    public:
        int getImportance(vector<Employee*> employees, int id) {
            unordered_map<int,Employee*> h;
            for(int i=0;i<employees.size();i++)
                h[employees[i]->id]=employees[i];

            queue<int> q;q.push(id);
            int res=0;
            while(!q.empty())
            {
                int cur=q.front();q.pop();
                res+=h[cur]->importance;
                for(int i=0;i<h[cur]->subordinates.size();i++)
                    q.push(h[cur]->subordinates[i]);
            }
            return res;
        }
};


int main() 
{
    Solution s;
 Employee e1,e2,e3;
    e2.id=2,e2.importance=3,e2.subordinates.clear();
    e3.id=3,e3.importance=3,e3.subordinates.clear();
//    vector<int> tmp;tmp.push_back(2);tmp.push_back(3);
    e1.id=1,e1.importance=5,e1.subordinates.push_back(2);e1.subordinates.push_back(3);
    vector<Employee*> e;
    e.push_back(&e1);e.push_back(&e2);e.push_back(&e3);
    cout<<s.getImportance(e,1)<<endl;
    return 0;
}
