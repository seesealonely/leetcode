/*
 Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"]. 
*/
#include"head.h"

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
 	vector<string> res;
	char temp[30];
	int cur;
	for(int i=0;i<nums.size();++i)
	{
		cur=nums[i];
		while(i+1<nums.size()&&nums[i]+1==nums[i+1]) i++;
		if(cur==nums[i]) {sprintf(temp,"%d",cur);res.push_back(temp);}
		else { sprintf(temp,"%d->%d",cur,nums[i]);res.push_back(temp);}
	}
	return res;
    }
};
