#include<vector>
#include<iostream>
using namespace std;
class Solution
{
	public:
	vector<int> twoSum(vector<int>&nums,int target)
	{
		int i,j;
	 for(i=0;i<nums.size();i++)
		 for(j=i+1;j<nums.size();j++)
			  if(nums[i]+nums[j]==target)
				   goto label;
	  label:
	 vector<int> result;
	 result.push_back(i);
	 result.push_back(j);
	  return result;
	}
};
