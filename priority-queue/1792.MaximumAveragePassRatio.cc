/*
   There is a school that has classes of students and each class will be having a final exam. You are given a 2D integer array classes, where classes[i] = [passi, totali]. You know beforehand that in the ith class, there are totali total students, but only passi number of students will pass the exam.

   You are also given an integer extraStudents. There are another extraStudents brilliant students that are guaranteed to pass the exam of any class they are assigned to. You want to assign each of the extraStudents students to a class in a way that maximizes the average pass ratio across all the classes.

   The pass ratio of a class is equal to the number of students of the class that will pass the exam divided by the total number of students of the class. The average pass ratio is the sum of pass ratios of all the classes divided by the number of the classes.

   Return the maximum possible average pass ratio after assigning the extraStudents students. Answers within 10-5 of the actual answer will be accepted.



   Example 1:

Input: classes = [[1,2],[3,5],[2,2]], extraStudents = 2
Output: 0.78333
Explanation: You can assign the two extra students to the first class. The average pass ratio will be equal to (3/4 + 3/5 + 2/2) / 3 = 0.78333.

Example 2:

Input: classes = [[2,4],[3,9],[4,5],[2,10]], extraStudents = 4
Output: 0.53485



Constraints:

1 <= classes.length <= 105
classes[i].length == 2
1 <= passi <= totali <= 105
1 <= extraStudents <= 105

*/


#include"head.h"
class Solution {
	public:
		class Class
		{
			public:
				int idx,pass,total;
				Class(int i,int p,int t):idx(i),pass(p),total(t){}
				bool operator <(const  Class &cur) const
				{
					return 1.0*(pass+1)/(total+1)-1.0*pass/total<1.0*(cur.pass+1)/(cur.total+1)-1.0*cur.pass/cur.total;
				}
				
		};
		double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
		const int n=classes.size();
		priority_queue<Class> q;
		
		for(int i=0;i<n;i++)
			q.push(Class(i,classes[i][0],classes[i][1]));

		while(extraStudents--)
		{
			Class c=q.top();
			q.pop();
			classes[c.idx][0]++;
			classes[c.idx][1]++;
			q.push(Class(c.idx,c.pass+1,c.total+1));
		}

		double res=0;

		for(int i=0;i<n;i++)
			res+=1.0*classes[i][0]/classes[i][1];

		return res/n;
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> c={{1,2},{3,5},{2,2}};
	cout<<s.maxAverageRatio(c,2)<<endl;
	c.clear();c={{2,4},{3,9},{4,5},{2,10}};
	cout<<s.maxAverageRatio(c,4)<<endl;
	return 0;
}
