#include<iostream>
#include<set>
#include<vector>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
 	 multiset<int> res;
	for(int i=0;i<nums.size();++i)
	{
		res.insert(nums[i]);
		if(res.size()>k)
		res.erase(res.begin());
	}      
	return *res.begin();
    }
};
