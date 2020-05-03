#include<iostream>
#include<set>
#include<vector>
#include<limits.h>
using namespace std;
/*
   class Solution 
   {
   public:
   int thirdMax(vector<int>& nums) 
   {
   int max,mid,min,count=0;
   max=mid=min=INT_MIN;       
   for(int i=0;i<nums.size();i++)
   {
   if(nums[i]==max||nums[i]==mid)
   continue;
   if(nums[i]>max)
   {
   min=mid;
   mid=max;
   max=nums[i];
   count++;
   }
   else if(nums[i]>mid)
   {
   min=mid;
   mid=nums[i];
   count++;
   }
   else if(nums[i]>=min)
   {
   min=nums[i];
   count++;
   }
   }
   if(count>=3)
   return min;
   else return max;
   }
   };
   */
class Solution 
{
	public:
		int thirdMax(vector<int>& nums) 
		{
			set<int>  res;
			for(int i=0;i<nums.size();++i)
			{
				res.insert(nums[i]);
				if(res.size()>3)
					res.erase(res.begin());
			}
			return res.size()==3?*res.begin():*res.rbegin();
		}
};
