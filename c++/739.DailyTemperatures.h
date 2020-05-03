/*
   Given a list of daily temperatures, produce a list that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

   For example, given the list temperatures = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100]. 
*/

#include"head.h"

vector<int> usingHash(vector<int>& temperatures) 
{
	vector<int> res;
	map<int,int> m;
	int rindex=0,imin=INT_MAX;
	for(int i=30;i<101;i++)
		m[i]=INT_MAX;
	for(int i=temperatures.size()-1;i>=0;i--)
	{
		m[temperatures[i]]=i;
		imin=INT_MAX;
		for(rindex =temperatures[i]+1;rindex<101;rindex++)
			if(m[rindex]<imin) 
			imin=m[rindex];
		if(imin!=INT_MAX) res.push_back(imin-i);
		else res.push_back(0);
	}
	reverse(res.begin(),res.end());
	return res;
}
	class Solution {
		public:
			vector<int> dailyTemperatures(vector<int>& temperatures) 
			{
				return  usingHash(temperatures);
			}
	};
