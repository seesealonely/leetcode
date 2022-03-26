/*
   Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.



   Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.



Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104

*/


#include"head.h"
class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);

        vector<vector<int> > res;
        for(int i=0;i<intervals.size();i++)
        {
            vector<int> c=intervals[i];
            if(res.empty()||res.back()[1]<c[0])
                res.push_back(intervals[i]);
            else if(res.back()[0]<c[1])
                res.back()[1]=max(res.back()[1],c[1]);
        }
        return res;
        }
        static bool cmp(vector<int> &a,vector<int> &b)
        {
            return a[0]<b[0];
        }
};


int main() 
{
    Solution s;
    vector<vector<int> > v={{1,3},{2,6},{8,10},{15,18}};
    show(s.merge(v));
    v.clear();v={{1,4},{4,5}};
    show(s.merge(v));
    return 0;
}
