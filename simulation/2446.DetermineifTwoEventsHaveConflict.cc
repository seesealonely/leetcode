/*
   You are given two arrays of strings that represent two inclusive events that happened on the same day, event1 and event2, where:

   event1 = [startTime1, endTime1] and
   event2 = [startTime2, endTime2].

   Event times are valid 24 hours format in the form of HH:MM.

   A conflict happens when two events have some non-empty intersection (i.e., some moment is common to both events).

   Return true if there is a conflict between two events. Otherwise, return false.



   Example 1:

Input: event1 = ["01:15","02:00"], event2 = ["02:00","03:00"]
Output: true
Explanation: The two events intersect at time 2:00.

Example 2:

Input: event1 = ["01:00","02:00"], event2 = ["01:20","03:00"]
Output: true
Explanation: The two events intersect starting from 01:20 to 02:00.

Example 3:

Input: event1 = ["10:00","11:00"], event2 = ["14:00","15:00"]
Output: false
Explanation: The two events do not intersect.



Constraints:

evnet1.length == event2.length == 2.
event1[i].length == event2[i].length == 5
startTime1 <= endTime1
startTime2 <= endTime2
All the event times follow the HH:MM format.

*/


#include"head.h"
class Solution {
    public:
        bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int st1=toNum(event1[0]),en1=toNum(event1[1]);
        int st2=toNum(event2[0]),en2=toNum(event2[1]);

        return max(st1,st2)<=min(en1,en2);
        }
        int toNum(string &s)
        {
            return ((s[0]-'0')*10+(s[1]-'0'))*60+(s[3]-'0')*10+s[4]-'0';
        }
};


int main() 
{
    Solution s;
    vector<string> e1={"01:15","02:00"},e2={"02:00","03:00"};
    cout<<s.haveConflict(e1,e2)<<endl;
    e1.clear();e1={"01:00","02:00"};
    e2.clear();e2={"01:20","03:00"};
    cout<<s.haveConflict(e1,e2)<<endl;
    e1.clear();e1={"10:00","11:00"};
    e2.clear();e2={"14:00","15:00"};
    cout<<s.haveConflict(e1,e2)<<endl;
    return 0;
}
