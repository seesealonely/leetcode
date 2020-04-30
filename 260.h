#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
	int x=0;
        vector<int> res(2,0);
	for(int i=0;i<nums.size();i++)
	x^=nums[i];
	x&=-x;
	for(int i=0;i<nums.size();i++)	
	if((x&nums[i])!=0) res[0]^=nums[i];
	else res[1]^=nums[i];
	return res;
    }
};
