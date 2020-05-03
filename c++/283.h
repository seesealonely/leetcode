#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
	int begin=0;
	for(int i=0;i<nums.size();i++)
	if(nums[i])
		nums[begin++]=nums[i];
	while(begin<nums.size())
	nums[begin++]=0;
    }
};
