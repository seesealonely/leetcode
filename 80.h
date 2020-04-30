#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
 	int count=0;
	for(int i=2;i<nums.size();i++)
	{
		if(nums[i]==nums[i-count-2]) ++count;
		else nums[i-count]=nums[i];	
	}       
	return nums.size()-count;
    }
};
