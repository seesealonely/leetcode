#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
 	if(nums.empty()) return 0;
	else if(nums.size()==1) return nums[0];
	int res=0,nminusone=nums[0],nminustwo=0;
	for(int i=1;i<nums.size();++i)
	{
		res=nminustwo+nums[i]>nminusone?nminustwo+nums[i]:nminusone;
		nminustwo=nminusone;
		nminusone=res;
	} 
	return res;
    }
};
