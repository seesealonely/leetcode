/*
   You are given an array of intervals, where intervals[i] = [starti, endi] and each starti is unique.

   The right interval for an interval i is an interval j such that startj >= endi and startj is minimized.

   Return an array of right interval indices for each interval i. If no right interval exists for interval i, then put -1 at index i.



   Example 1:

Input: intervals = [[1,2]]
Output: [-1]
Explanation: There is only one interval in the collection, so it outputs -1.

Example 2:

Input: intervals = [[3,4],[2,3],[1,2]]
Output: [-1,0,1]
Explanation: There is no right interval for [3,4].
The right interval for [2,3] is [3,4] since start0 = 3 is the smallest start that is >= end1 = 3.
The right interval for [1,2] is [2,3] since start1 = 2 is the smallest start that is >= end2 = 2.

Example 3:

Input: intervals = [[1,4],[2,3],[3,4]]
Output: [-1,2,-1]
Explanation: There is no right interval for [1,4] and [3,4].
The right interval for [2,3] is [3,4] since start2 = 3 is the smallest start that is >= end1 = 3.



Constraints:

1 <= intervals.length <= 2 * 104
intervals[i].length == 2
-106 <= starti <= endi <= 106
The start point of each interval is unique.


*/
#define c11
#include"head.h"
class Solution {
	public:
		vector<int> findRightInterval(vector<vector<int>>& intervals) {
			return usinglib(intervals);
			const int n=intervals.size();
			unordered_map<int,int> index;
			vector<int> res,first;
			for(int i=0;i<n;i++)
			{
				index[intervals[i][0]]=i;
				first.push_back(intervals[i][0]);
			}

			sort(first.begin(),first.end());
			for(int i=0;i<n;i++)
			{
				int j=binarySearch(first,intervals[i][1]);
				if(j==-1)
					res.push_back(j);
				else
					res.push_back(index[first[j]]);
			}
			return res;
		}
		int binarySearch(vector<int> &num,int target)
		{
			const int n=num.size();
			if(num[n-1]<target)
				return -1;
			int l=0,r=n-1;
			while(l<r)
			{
				const int m=(l+r)>>1;
				if(num[m]<target)
					l=m+1;
				else
					r=m;
			}
			return l;
		}

		vector<int> usinglib(vector<vector<int>>& intervals) {
			int n=intervals.size();
			unordered_map<int,int> index;
			vector<int> first,res;
			for(int i=0;i<n;i++)
			{
				first.push_back(intervals[i][0]);
				index[intervals[i][0]]=i;
			}
			sort(first.begin(),first.end());
			for(int i=0;i<n;i++)
			{
				auto it=lower_bound(first.begin(),first.end(),intervals[i][1]);
				if(it==first.end())
					res.push_back(-1);
				else
					res.push_back(index[first[it-first.begin()]]);
			}
			return res;
		}
};
int main() 
{
	Solution s;
	vector<vector<int> > v={{1,2}};
	show(s.findRightInterval(v));
	v.clear();v={{3,4},{2,3},{1,2}};
	show(s.findRightInterval(v));
	v.clear();v={{1,4},{2,3},{3,4}};
	show(s.findRightInterval(v));
	return 0;
}
