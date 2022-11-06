/*

   You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.

   For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.

   You will start at the bus stop source (You are not on any bus initially), and you want to go to the bus stop target. You can travel between bus stops by buses only.

   Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.



   Example 1:

Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
Output: 2
Explanation: The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.

Example 2:

Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
Output: -1



Constraints:

1 <= routes.length <= 500.
1 <= routes[i].length <= 105
All the values of routes[i] are unique.
sum(routes[i].length) <= 105
0 <= routes[i][j] < 106
0 <= source, target < 106

*/

#define c11
#include"head.h"
class Solution {
    public:
        int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
            if(source==target) return 0;
            unordered_map<int,vector<int>> stopTobus;
            const int n=routes.size();
            for(int i=0;i<n;i++)
                for(int j=0;j<routes[i].size();j++)
                    stopTobus[routes[i][j]].push_back(i);

            vector<bool> visit(n,false);
            queue<int> q;q.push(source);
            int res=0;
            while(!q.empty())
            {
                ++res;
                for(int i=q.size()-1;i>=0;i--)
                {
                    int stop=q.front();q.pop();
                    for(int j=0;j<stopTobus[stop].size();j++)
                    {
                        int bus=stopTobus[stop][j];
                        if(visit[bus]) continue;
                        visit[bus]=true;
                        for(int k=0;k<routes[bus].size();k++)
                        {
                            if(routes[bus][k]==target) return res;
                            q.push(routes[bus][k]);
                        }
                    }
                }

            }
            return -1;
        }
};


int main() 
{
    Solution s;
    vector<vector<int>> v={{1,2,7},{3,6,7}};
    cout<<s.numBusesToDestination(v,1,6)<<endl;
    v.clear();v={{7,12},{4,5,15},{6},{15,19},{9,12,13}};
    cout<<s.numBusesToDestination(v,15,12)<<endl;
    return 0;
}
