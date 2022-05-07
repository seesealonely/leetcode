/*
   You are given a 0-indexed 2D integer array of events where events[i] = [startTimei, endTimei, valuei]. The ith event starts at startTimei and ends at endTimei, and if you attend this event, you will receive a value of valuei. You can choose at most two non-overlapping events to attend such that the sum of their values is maximized.

   Return this maximum sum.

   Note that the start time and end time is inclusive: that is, you cannot attend two events where one of them starts and the other ends at the same time. More specifically, if you attend an event with end time t, the next event must start at or after t + 1.



   Example 1:

Input: events = [[1,3,2],[4,5,2],[2,4,3]]
Output: 4
Explanation: Choose the green events, 0 and 1 for a sum of 2 + 2 = 4.

Example 2:
Example 1 Diagram

Input: events = [[1,3,2],[4,5,2],[1,5,5]]
Output: 5
Explanation: Choose event 2 for a sum of 5.

Example 3:

Input: events = [[1,5,3],[1,5,1],[6,6,5]]
Output: 8
Explanation: Choose events 0 and 2 for a sum of 3 + 5 = 8.



Constraints:

2 <= events.length <= 105
events[i].length == 3
1 <= startTimei <= endTimei <= 109
1 <= valuei <= 106

*/


#include"head.h"
class Solution {
    public:
        int maxTwoEvents(vector<vector<int>>& events) {

        sort(events.begin(),events.end(),cmp);

        const int n=events.size();
        vector<int> nextBig(n+1,0);
        for(int i=n-1;i>=0;i--)
            nextBig[i]=max(nextBig[i+1],events[i][2]);

        int res=0;
        for(int i=0;i<n;i++)
        {
            int next=binarySearch(events,events[i][1]);
            res=max(res,events[i][2]+nextBig[next]);
        }

        return res;
        }

        int binarySearch(vector<vector<int>> &e,int end)
        {
            int l=0,r=e.size(),m=(1+r)>>1;
            while(l<r)
            {
                m=(l+r)>>1;
                if(e[m][0]>end)
                    r=m;
                else
                    l=m+1;
            }
            return l;
        }

        static bool cmp(vector<int>& a,vector<int>&b)
        {
            return a[0]<b[0];
        }

};


int main() 
{
    Solution s;
    vector<vector<int>> v={{1,3,2},{4,5,2},{2,4,3}};
    cout<<s.maxTwoEvents(v)<<endl;
    v.clear();v={{1,3,2},{4,5,2},{1,5,5}};
    cout<<s.maxTwoEvents(v)<<endl;
    v.clear();v={{1,5,3},{1,5,1},{6,6,5}};
    cout<<s.maxTwoEvents(v)<<endl;
    return 0;
}
