/*
   There are n different online courses numbered from 1 to n. You are given an array courses where courses[i] = [durationi, lastDayi] indicate that the ith course should be taken continuously for durationi days and must be finished before or on lastDayi.

   You will start on the 1st day and you cannot take two or more courses simultaneously.

   Return the maximum number of courses that you can take.



   Example 1:

Input: courses = [[100,200],[200,1300],[1000,1250],[2000,3200]]
Output: 3
Explanation:
There are totally 4 courses, but you can take 3 courses at most:
First, take the 1st course, it costs 100 days so you will finish it on the 100th day, and ready to take the next course on the 101st day.
Second, take the 3rd course, it costs 1000 days so you will finish it on the 1100th day, and ready to take the next course on the 1101st day.
Third, take the 2nd course, it costs 200 days so you will finish it on the 1300th day.
The 4th course cannot be taken now, since you will finish it on the 3300th day, which exceeds the closed date.

Example 2:

Input: courses = [[1,2]]
Output: 1

Example 3:

Input: courses = [[3,2],[4,3]]
Output: 0



Constraints:

1 <= courses.length <= 104
1 <= durationi, lastDayi <= 104

*/


#include"head.h"
class Solution {
	public:
		int scheduleCourse(vector<vector<int>>& courses) {
		sort(courses.begin(),courses.end(),cmp);

		int start=0;
		priority_queue<int> pq;
		for(int i=0;i<courses.size();i++)
		{
			int d=courses[i][0],e=courses[i][1];
			pq.push(d);
			start+=d;
			if(start>e)
			{
				start-=pq.top();
				pq.pop();
			}
		}
		return pq.size();
		}
		static bool cmp(const vector<int>&x,const vector<int>&y)
		{
			return x[1]<y[1];
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> courses = {{100,200},{200,1300},{1000,1250},{2000,3200}};
	cout<<s.scheduleCourse(courses)<<endl;
	courses.clear();courses={{1,2}};
	cout<<s.scheduleCourse(courses)<<endl;
	courses.clear();courses={{3,2},{4,3}};
	cout<<s.scheduleCourse(courses)<<endl;
	return 0;
}
