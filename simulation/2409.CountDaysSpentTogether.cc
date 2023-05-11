/*
   Alice and Bob are traveling to Rome for separate business meetings.

   You are given 4 strings arriveAlice, leaveAlice, arriveBob, and leaveBob. Alice will be in the city from the dates arriveAlice to leaveAlice (inclusive), while Bob will be in the city from the dates arriveBob to leaveBob (inclusive). Each will be a 5-character string in the format "MM-DD", corresponding to the month and day of the date.

   Return the total number of days that Alice and Bob are in Rome together.

   You can assume that all dates occur in the same calendar year, which is not a leap year. Note that the number of days per month can be represented as: [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31].



   Example 1:

Input: arriveAlice = "08-15", leaveAlice = "08-18", arriveBob = "08-16", leaveBob = "08-19"
Output: 3
Explanation: Alice will be in Rome from August 15 to August 18. Bob will be in Rome from August 16 to August 19. They are both in Rome together on August 16th, 17th, and 18th, so the answer is 3.

Example 2:

Input: arriveAlice = "10-01", leaveAlice = "10-31", arriveBob = "11-01", leaveBob = "12-31"
Output: 0
Explanation: There is no day when Alice and Bob are in Rome together, so we return 0.



Constraints:

All dates are provided in the format "MM-DD".
Alice and Bob's arrival dates are earlier than or equal to their leaving dates.
The given dates are valid dates of a non-leap year.

*/


#include"head.h"
const int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
class Solution {
	public:
		int getDays(string s)
		{
			int m,d;
			sscanf(s.c_str(),"%d-%d",&m,&d);
			int res=0;
			for(int i=0;i<m;i++)
				res+=days[i];

			return res+d;
		}
		int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
		int s1=getDays(arriveAlice),t1=getDays(leaveAlice);
		int s2=getDays(arriveBob),t2=getDays(leaveBob);

		return max(0,min(t1,t2)-max(s1,s2)+1);
		
		}
};


int main() 
{
	Solution s;
	cout<<s.countDaysTogether("08-15","08-18","08-16","08-19")<<endl;
	cout<<s.countDaysTogether("10-01","10-31","11-01","12-31")<<endl;
	return 0;
}
