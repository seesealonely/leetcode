/*
   There are n workers. You are given two integer arrays quality and wage where quality[i] is the quality of the ith worker and wage[i] is the minimum wage expectation for the ith worker.

   We want to hire exactly k workers to form a paid group. To hire a group of k workers, we must pay them according to the following rules:

   Every worker in the paid group should be paid in the ratio of their quality compared to other workers in the paid group.
   Every worker in the paid group must be paid at least their minimum wage expectation.

   Given the integer k, return the least amount of money needed to form a paid group satisfying the above conditions. Answers within 10-5 of the actual answer will be accepted.



   Example 1:

Input: quality = [10,20,5], wage = [70,50,30], k = 2
Output: 105.00000
Explanation: We pay 70 to 0th worker and 35 to 2nd worker.

Example 2:

Input: quality = [3,1,10,10,1], wage = [4,8,2,2,7], k = 3
Output: 30.66667
Explanation: We pay 4 to 0th worker, 13.33333 to 2nd and 3rd workers separately.



Constraints:

n == quality.length == wage.length
1 <= k <= n <= 104
1 <= quality[i], wage[i] <= 104

*/


#include"head.h"
class Solution {
    public:
        double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n=quality.size(),sum_q=0;
        vector<int> idx(n,0);
        iota(idx.begin(),idx.end(),0);

        sort(idx.begin(),idx.end(),[&](int i,int j){return wage[i]*quality[j]<wage[j]*quality[i];});

        priority_queue<int> pq;
        for(int i=0;i<k;i++)
            pq.push(quality[idx[i]]),sum_q+=quality[idx[i]];

        double res=sum_q*((double)wage[idx[k-1]]/quality[idx[k-1]]);
        for(int i=k;i<n;i++)
        {
            int cur=quality[idx[i]];
            if(cur<pq.top())
            {
                sum_q-=pq.top()-cur;
                pq.pop();
                pq.push(cur);
                res=min(res,sum_q*((double)wage[idx[i]]/cur));
            }
        }

        return res;

        }
};


int main() 
{
    Solution s;
    vector<int> q={10,20,5},w={70,50,30};
    cout<<s.mincostToHireWorkers(q,w,2)<<endl;
    q.clear();q={3,1,10,10,1};
    w.clear();w={4,8,2,2,7};
    cout<<s.mincostToHireWorkers(q,w,3)<<endl;
    return 0;
}
