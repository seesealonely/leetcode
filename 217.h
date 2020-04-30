#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
	if(nums.empty()) return false;
	map<int,int> m;
	m[0]=1;
	for(int i=0;i<nums.size();i++)
		if(m[nums[i]]==nums[i])
			return true;	
		else m[nums[i]]=nums[i];
	return false;
    }
};
