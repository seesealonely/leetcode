#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
	public:
		int removeElement(vector<int>& nums, int val) 
		{
			int num=nums.size();
			for(vector<int>::iterator iter=nums.begin(),vector<int>::iterator tmp;iter!=nums.end();++iter)
			{
				if(*iter==val)
				{
				tmp=++iter;
				nums.erase(iter);	
				}
			}
			return num;
		}
};
