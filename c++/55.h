#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
 	int jumpposition=0;
	for(int i=0;i<nums.size()&&i<=jumpposition;i++)
	jumpposition=max(i+nums[i],jumpposition);
//	cout<<"last position:"<<jumpposition<<endl;
	return jumpposition>=nums.size();	       
    }
};
