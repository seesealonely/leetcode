#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
	public:
		int removeElement(vector<int>& nums, int val) 
		{
			for(vector<int>::iterator it=nums.begin();it!=nums.end();)
			if(*it==val) nums.erase(it);
			else it++;
			return nums.size();
		}
};
