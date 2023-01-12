/*
   You have n robots. You are given two 0-indexed integer arrays, chargeTimes and runningCosts, both of length n. The ith robot costs chargeTimes[i] units to charge and costs runningCosts[i] units to run. You are also given an integer budget.

   The total cost of running k chosen robots is equal to max(chargeTimes) + k * sum(runningCosts), where max(chargeTimes) is the largest charge cost among the k robots and sum(runningCosts) is the sum of running costs among the k robots.

   Return the maximum number of consecutive robots you can run such that the total cost does not exceed budget.

    

   Example 1:

Input: chargeTimes = [3,6,1,3,4], runningCosts = [2,1,3,4,5], budget = 25
Output: 3
Explanation: 
It is possible to run all individual and consecutive pairs of robots within budget.
To obtain answer 3, consider the first 3 robots. The total cost will be max(3,6,1) + 3 * sum(2,1,3) = 6 + 3 * 6 = 24 which is less than 25.
It can be shown that it is not possible to run more than 3 consecutive robots within budget, so we return 3.

Example 2:

Input: chargeTimes = [11,12,19], runningCosts = [10,8,7], budget = 19
Output: 0
Explanation: No robot can be run that does not exceed the budget, so we return 0.

 

Constraints:

chargeTimes.length == runningCosts.length == n
1 <= n <= 5 * 104
1 <= chargeTimes[i], runningCosts[i] <= 105
1 <= budget <= 1015

*/


#include"head.h"
class Solution {
    public:
        int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
            const int n=chargeTimes.size();
            deque<int> q;

            long long sum=0;
            int res=0;
            for(int l=0,r=0;r<n;r++)
            {
                while(!q.empty()&&chargeTimes[q.back()]<=chargeTimes[r])
                    q.pop_back();

                q.push_back(r);

                sum+=runningCosts[r];
                while(l<=r&&sum*(r-l+1)+chargeTimes[q.front()]>budget)
                {
                    if(q.front()==l)
                        q.pop_front();
                    sum-=runningCosts[l++];
                }
                res=max(res,r-l+1);
            }

            return res;
        }
};


int main() 
{
    Solution s;
    vector<int> c={3,6,1,3,4},r={2,1,3,4,5};
    cout<<s.maximumRobots(c,r,25)<<endl;
    c.clear();c={11,12,19};
    r.clear();r={10,8,7};
    cout<<s.maximumRobots(c,r,19)<<endl;
    return 0;
}
