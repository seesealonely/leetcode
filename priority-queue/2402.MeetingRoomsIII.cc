/*
   You are given an integer n. There are n rooms numbered from 0 to n - 1.

   You are given a 2D integer array meetings where meetings[i] = [starti, endi] means that a meeting will be held during the half-closed time interval [starti, endi). All the values of starti are unique.

   Meetings are allocated to rooms in the following manner:

   Each meeting will take place in the unused room with the lowest number.
   If there are no available rooms, the meeting will be delayed until a room becomes free. The delayed meeting should have the same duration as the original meeting.
   When a room becomes unused, meetings that have an earlier original start time should be given the room.

   Return the number of the room that held the most meetings. If there are multiple rooms, return the room with the lowest number.

   A half-closed interval [a, b) is the interval between a and b including a and not including b.



   Example 1:

Input: n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
Output: 0
Explanation:
- At time 0, both rooms are not being used. The first meeting starts in room 0.
- At time 1, only room 1 is not being used. The second meeting starts in room 1.
- At time 2, both rooms are being used. The third meeting is delayed.
- At time 3, both rooms are being used. The fourth meeting is delayed.
- At time 5, the meeting in room 1 finishes. The third meeting starts in room 1 for the time period [5,10).
- At time 10, the meetings in both rooms finish. The fourth meeting starts in room 0 for the time period [10,11).
Both rooms 0 and 1 held 2 meetings, so we return 0. 

Example 2:

Input: n = 3, meetings = [[1,20],[2,10],[3,5],[4,9],[6,8]]
Output: 1
Explanation:
- At time 1, all three rooms are not being used. The first meeting starts in room 0.
- At time 2, rooms 1 and 2 are not being used. The second meeting starts in room 1.
- At time 3, only room 2 is not being used. The third meeting starts in room 2.
- At time 4, all three rooms are being used. The fourth meeting is delayed.
- At time 5, the meeting in room 2 finishes. The fourth meeting starts in room 2 for the time period [5,10).
- At time 6, all three rooms are being used. The fifth meeting is delayed.
- At time 10, the meetings in rooms 1 and 2 finish. The fifth meeting starts in room 1 for the time period [10,12).
Room 0 held 1 meeting while rooms 1 and 2 each held 2 meetings, so we return 1. 



Constraints:

1 <= n <= 100
1 <= meetings.length <= 105
meetings[i].length == 2
0 <= starti < endi <= 5 * 105
All the values of starti are unique.

*/


#include"head.h"
class Solution {
    public:
        int mostBooked(int n, vector<vector<int>>& meetings) {
        typedef long long ll;
        typedef pair<ll,int > pll;
        priority_queue<pll,vector<pll>,greater<pll>> run;
        priority_queue<int,vector<int>,greater<int>> empty;

        sort(meetings.begin(),meetings.end());
        for(int i=0;i<n;i++)
            empty.push(i);
        vector<int> cnt(n,0);
        for(int i=0;i<meetings.size();i++)
        {
            while(!run.empty()&&run.top().first<=meetings[i][0])
            {
                empty.push(run.top().second);
                run.pop();
            }

            if(empty.empty())
            {
                pll cur=run.top();run.pop();
                run.push({cur.first+meetings[i][1]-meetings[i][0],cur.second});
                cnt[cur.second]++;
            }
            else
            {
                int cur=empty.top();empty.pop();
                run.push({meetings[i][1],cur});
                cnt[cur]++;
            }
        }

        int idx=0,mx=cnt[0];
        for(int i=1;i<n;i++)
            if(mx<cnt[i])
                idx=i,mx=cnt[i];

        return idx;
        }
};


int main() 
{
    Solution s;
    vector<vector<int>> v={{0,10},{1,5},{2,7},{3,4}};
    cout<<s.mostBooked(2,v)<<endl;
    v.clear();v={{1,20},{2,10},{3,5},{4,9},{6,8}};
    cout<<s.mostBooked(3,v)<<endl;
    return 0;
}
