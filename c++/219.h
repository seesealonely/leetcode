#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
 	//if(nums.empty()||k>nums.size()) return false;
	map<int,int> m;
	m[0]=-1;
	for(int i=0;i<nums.size();i++)
	if(m.find(nums[i])!=m.end()&&i-m[nums[i]]<=k)
	return true;
	else m[nums[i]]=i;
	return false;
    }
};
