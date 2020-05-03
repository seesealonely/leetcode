#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k,int t) {
	map<int,int> m;
	for(int i=0;i<nums.size();i++)
	if(m.find(nums[i])!=m.end()&&nums[i]<=t&&i-m[nums[i]]<=k)
	return true;
	else if(nums[i]>t||i-m[nums[i]]>k)
	return false;
	else m[nums[i]]=i;
	return false;
    }
};
