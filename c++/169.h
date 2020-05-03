#include<iostream>
#include<vector>
#include<map>
using namespace  std;
class Solution 
{
	public:
		int majorityElement(vector<int>& nums) 
		{
			map<int,int> count;
			int n=nums.size();
			for(int i=0;i<n;i++)
			if(++count[nums[i]]>n/2) return nums[i];
		}
};
