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
#include"539.MinimumTimeDifference.h"
int main() 
 {
 	 Solution s;
	 vector<string> v={"23:59","00:00"};
 	 cout<<s.findMinDifference(v)<<endl;
	 v.clear();v={"00:00","23:59","00:00"};
 	 cout<<s.findMinDifference(v)<<endl;
	 v.clear();v={"01:01","02:01","00:00"};
 	 cout<<s.findMinDifference(v)<<endl;
 	 return 0;
 }
