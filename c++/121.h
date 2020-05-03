#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;
class Solution 
{
	public:
		int maxProfit(vector<int>& prices)
		{
			int low=INT_MAX,profix=0;
			for(int i=0;i<prices.size();i++)
			{
				low=min(low,prices[i]);
				profix=max(profix,prices[i]-low);       
			}
			return profix;
		}
};
