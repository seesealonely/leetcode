#include<iostream>
#include<vector>
using namespace std;
//dp
/*
class Solution {
public:
    int maxProduct(vector<int>& nums) {
 	int dpmax[nums.size()],dpmin[nums.size()];
	int res=dpmin[0]=dpmax[0]=nums[0];
	for(int i=1;i<nums.size();++i)
	{
		dpmax[i]=max(max(dpmax[i-1]*nums[i],dpmin[i-1]*nums[i]),nums[i]);
		dpmin[i]=min(min(dpmax[i-1]*nums[i],dpmin[i-1]*nums[i]),nums[i]);
		if(res<dpmax[i]) res=dpmax[i];
	}       
	return res;
    }
};
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
 	int dpmax[2],dpmin[2],res;
	res=dpmin[0]=dpmax[0]=nums[0];
	for(int i=1;i<nums.size();++i)
	{
		dpmax[i%2]=max(max(dpmax[(i-1)%2]*nums[i],dpmin[(i-1)%2]*nums[i]),nums[i]);
		dpmin[i%2]=min(min(dpmax[(i-1)%2]*nums[i],dpmin[(i-1)%2]*nums[i]),nums[i]);
		if(res<dpmax[i%2]) res=dpmax[i%2];
	}       
	return res;
    }
};
