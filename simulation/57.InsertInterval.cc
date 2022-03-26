/*
   You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

   Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

   Return intervals after the insertion.



   Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].



Constraints:

0 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 105
intervals is sorted by starti in ascending order.
newInterval.length == 2
0 <= start <= end <= 105

*/


#include"head.h"
class Solution {
    public:
        vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int b=newInterval[0],e=newInterval[1],i=0,n=intervals.size();
        vector<vector<int> > res;

        while(i<n&&intervals[i][1]<b)
            res.push_back(intervals[i++]);

        int s=b,t=e;
        while(i<n&&intervals[i][0]<=e)
            s=min(s,intervals[i][0]),t=max(t,intervals[i][1]),i++;
        res.push_back({s,t});

        while(i<n)
            res.push_back(intervals[i++]);

        return res;
        }
};


int main() 
{
    Solution s;
    vector<vector<int> > v1={{1,3},{6,9}};vector<int> v2={2,5};
    show(s.insert(v1,v2));
    v1.clear();v1={{1,2},{3,5},{6,7},{8,10},{12,16}};
    v2.clear();v2={4,8};
    show(s.insert(v1,v2));
    return 0;
}
