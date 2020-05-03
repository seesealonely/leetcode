#include<iostream>
#include<vector>
using namespace std;
class Solution {
	public:
		int singleNumber(vector<int>& nums) {
			int res=0,tmp=0;
			for(int i=0;i<nums.size();i++)
			{
				res=(nums[i]^res)&~tmp; 
				tmp=(nums[i]^tmp)&~res;
			}
			return res;
		}
};
