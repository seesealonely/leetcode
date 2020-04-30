#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/**
 * Definition for an interval.
 */
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
	public:
		vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
			if(intervals.empty()) return internvals.insert(newInterval);
			int left=0,right=intervals.size()-1,mid;
			while(left<=right)
			{
				mid=(left+right)>>1;
				if(intervals[mid].start<newInterval.start)
				left=mid+1;
				else if(intervals[mid].start>newInterval.start)
				right=mid-1;
				else break;
			}        
			int ltmp=mid-1;
			left=0;right=intervals.size()-1;
			while(left<=right)
			{
				mid=(left+right)>>1;
				if(intervals[mid].end<newInterval.end)
				left=mid+1;
				else if(intervals[mid].end>newInterval.end)
				right=mid-1;
				else break;
			}        
			int rtmp=mid+1;
			
		}
};
