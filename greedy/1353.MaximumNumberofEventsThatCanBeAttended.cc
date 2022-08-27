/*
   You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.

   You can attend an event i at any day d where startTimei <= d <= endTimei. You can only attend one event at any time d.

   Return the maximum number of events you can attend.



   Example 1:

Input: events = [[1,2],[2,3],[3,4]]
Output: 3
Explanation: You can attend all the three events.
One way to attend them all is as shown.
Attend the first event on day 1.
Attend the second event on day 2.
Attend the third event on day 3.

Example 2:

Input: events= [[1,2],[2,3],[3,4],[1,2]]
Output: 4



Constraints:

1 <= events.length <= 105
events[i].length == 2
1 <= startDayi <= endDayi <= 105

*/


#include"head.h"
class Solution {
    public:
        vector<int> pa;
        int maxEvents(vector<vector<int>>& events) {
         const int n=events.size();
         sort(events.begin(),events.end(),cmp);
         int mx=events.back()[1];
         pa.resize(mx+2);

         for(int i=1;i<=mx+1;i++)
             pa[i]=i;

         int res=0;
         for(int i=0;i<n;i++)
         {
                int x=find(events[i][0]);
                if(x<=events[i][1])
                {
                    res++;
                    pa[x]=find(x+1);
                }
         }
         return res;
        }
        int find(int x)
        {
            return x==pa[x]?x:pa[x]=find(pa[x]);
        }
        static bool cmp(vector<int> &a,vector<int>&b)
        {
            return a[1]<b[1];
        }
};


int main() 
{
    Solution s;
    vector<vector<int>> v={{1,2},{2,3},{3,4}};
    cout<<s.maxEvents(v)<<endl;
    v.push_back({1,2});
    cout<<s.maxEvents(v)<<endl;
    v.clear();v={{1,4},{4,4},{2,2},{3,4},{1,1}};
    cout<<s.maxEvents(v)<<endl;
    v.clear();v={{1,100000}};
    cout<<s.maxEvents(v)<<endl;
    v.clear();v={{1,1},{1,2},{1,3},{1,4},{1,5},{1,6},{1,7}};
    cout<<s.maxEvents(v)<<endl;
    return 0;
}
