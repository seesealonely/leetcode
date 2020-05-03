#include"head.h"
using namespace std;
class Solution {
	public:
		int threeSumClosest(vector<int>& nums, int target) {
			if(nums.size()<3) return 0;
			int closest=nums[0]+nums[1]+nums[2];
			sort(nums.begin(),nums.end());
			int first,second,third,cursum;
			for(first=0;first<nums.size()-2;++first)
			{
				if(first>0&&nums[first]==nums[first-1])continue;       
				second=first+1;
				third=nums.size()-1;
				while(second<third)
				{
					cursum=nums[first]+nums[second]+nums[third];
					if(cursum==target) return cursum;
					if(abs(target-cursum)<abs(target-closest))
						closest=cursum;
					if(cursum>target)
						--third;
					else 
						++second;

				}

			}
		return closest;
		}
};
