/*
In a country popular for train travel, you have planned some train travelling one year in advance.  The days of the year that you will travel is given as an array days.  Each day is an integer from 1 to 365.

Train tickets are sold in 3 different ways:

    a 1-day pass is sold for costs[0] dollars;
    a 7-day pass is sold for costs[1] dollars;
    a 30-day pass is sold for costs[2] dollars.

The passes allow that many days of consecutive travel.  For example, if we get a 7-day pass on day 2, then we can travel for 7 days: day 2, 3, 4, 5, 6, 7, and 8.

Return the minimum number of dollars you need to travel every day in the given list of days.

 

Example 1:

Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
Explanation: 
For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
In total you spent $11 and covered all the days of your travel.

Example 2:

Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
Output: 17
Explanation: 
For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1, 2, ..., 30.
On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
In total you spent $17 and covered all the days of your travel.

 

Note:

    1 <= days.length <= 365
    1 <= days[i] <= 365
    days is in strictly increasing order.
    costs.length == 3
    1 <= costs[i] <= 1000

*/
#define c11
#include"head.h"

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
	return dp(days,costs);
	return reDp(days,costs);
    }
	Solution():mem(366,0){};
int reDp(vector<int>& days, vector<int>& costs) {
	for(int i=0;i<days.size();i++)
		hash.insert(pair<int,bool>{days[i],true});	
	dp1(1,costs);	
	}
	int dp1(int i,vector<int> &cost)
	{
		if(i>365) return 0;
		if(mem[i])
			return mem[i];
		int res=0;
		if(hash.find(i)!=hash.end())
			res=min(min(dp1(i+1,cost)+cost[0],dp1(i+7,cost)+cost[1]),dp1(30+i,cost)+cost[2]);
		else dp1(i+1,cost);
		mem[i]=res;
		return res;
	}
    int dp(vector<int>& days, vector<int>& costs) {
	vector<bool> daysOrNot(366,false);	        
	vector<int> res(366,0);	        
	for(int i=0;i<days.size();i++)
	daysOrNot[days[i]]=true;
	res[0]=0;
	for(int i=1;i<=365;i++)
	{
		if(!daysOrNot[i])
		{
			res[i]=res[i-1];
			continue;
		}
		res[i]=min(min(res[i-1]+costs[0],res[max(0,i-7)]+costs[1]),res[max(0,i-30)]+costs[2]);
	}
	return res[365];
	}
	private:
	unordered_map<int,bool> hash;
//	int mem[366];
	vector<int> mem;
};
