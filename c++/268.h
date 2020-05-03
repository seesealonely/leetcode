#include<iostream>
#include<vector>
using namespace std;
/* ^=
class Solution {
public:
    int missingNumber(vector<int>& nums) {
 	int res=nums.size();
	for(int i=0;i<nums.size();i++)
	{
		res^=i;
		res^=nums[i];
	}       
	return res;
    }
};
*/
/*  sum
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
 	int res=(0+nums.size())*(nums.size()+1)/2;
	
	for(int i=0;i<nums.size();i++)
		res-=nums[i];
	return res;
    }
};
