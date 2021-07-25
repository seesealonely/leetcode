/*
   There are n cars going to the same destination along a one-lane road. The destination is target miles away.

   You are given two integer array position and speed, both of length n, where position[i] is the position of the ith car and speed[i] is the speed of the ith car (in miles per hour).

   A car can never pass another car ahead of it, but it can catch up to it, and drive bumper to bumper at the same speed.

   The distance between these two cars is ignored (i.e., they are assumed to have the same position).

   A car fleet is some non-empty set of cars driving at the same position and same speed. Note that a single car is also a car fleet.

   If a car catches up to a car fleet right at the destination point, it will still be considered as one car fleet.

   Return the number of car fleets that will arrive at the destination.



   Example 1:

Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]
Output: 3
Explanation:
The cars starting at 10 and 8 become a fleet, meeting each other at 12.
The car starting at 0 doesn't catch up to any other car, so it is a fleet by itself.
The cars starting at 5 and 3 become a fleet, meeting each other at 6.
Note that no other cars meet these fleets before the destination, so the answer is 3.

Example 2:

Input: target = 10, position = [3], speed = [3]
Output: 1



Constraints:

n == position.length == speed.length
1 <= n <= 105
0 < target <= 106
0 <= position[i] < target
All the values of position are unique.
0 < speed[i] <= 106

*/
#include"head.h"
class Solution {
	public:
		int carFleet(int target, vector<int>& position, vector<int>& speed) {
//		return usingArray(target,position,speed);
		return usingmap(target,position,speed);
		}
		int usingArray(int target, vector<int>& position, vector<int>& speed) {
		vector<pair<int,double> > arr;
		for(int i=0;i<position.size();i++)
			arr.push_back(make_pair(position[i],(double)(target-position[i])/speed[i]));
		sort(arr.begin(),arr.end(),cmp);
		int res=0;double cur=0;
		for(int i=arr.size()-1;i>=0;i--)
			if(arr[i].second>cur) cur=arr[i].second,res++;
		return res;
		}
		int usingmap(int target, vector<int>& position, vector<int>& speed) {
			map<int,double> h;
			for(int i=0;i<position.size();i++)
				h[-position[i]]=(double) (target-position[i])/speed[i];
			int res=0; double cur=0;
			for(map<int,double>::iterator it=h.begin();it!=h.end();it++)
			if(it->second>cur) cur=it->second,res++;
			return res;

		}
	private:
		static	bool cmp(pair<int,double> a,pair<int,double> b)
		{
			return a.first<=b.first;
		}
};
