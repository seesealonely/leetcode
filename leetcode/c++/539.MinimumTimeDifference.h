/*
   Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.



   Example 1:

Input: timePoints = 9
Output: 1

Example 2:

Input: timePoints = 9
Output: 0



Constraints:

timePoints[i] is in the format "HH:MM".
*/
#include"head.h"
class Solution {
	public:
		int findMinDifference(vector<string>& timePoints) {
			vector<bool> bucket(24*60,false);
			for(int i=0;i<timePoints.size();i++)
			{
				int cur=stoi(timePoints[i].substr(0,2))*60;
				cur+=stoi(timePoints[i].substr(3,2));
				if(bucket[cur]) return 0;
				bucket[cur]=true;
			}
			int pre=0,res=INT_MAX,prehalf=INT_MAX,posthalf=INT_MIN;
			for(int i=0;i<24*60;i++)
			{
				if(bucket[i])
				{
					if(prehalf!=INT_MAX)
						res=min(res,i-pre);
				prehalf=min(i,prehalf);
				posthalf=max(i,posthalf);
				pre=i;
				}
			}
			res=min(res,24*60-posthalf+prehalf);
			return res;
		}
};
