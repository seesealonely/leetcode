#include<iostream>
#include<vector>
using namespace std;
class Solution {
	public:
		vector<int> twoSum(vector<int>& numbers, int target) {
			for(int begin=0;begin<numbers.size()-1;begin++)
			{
				int subbegin=begin+1,subend=numbers.size()-1,minus=target-numbers[begin],mid;
				while(subbegin<=subend)
				{
					mid=(subbegin+subend)/2;
					if(numbers[mid]>minus) subend=mid-1;
					else if(numbers[mid]<minus) subbegin=mid+1;
					else
					{
						vector<int> res;
						res.push_back(begin+1);
						res.push_back(mid+1);
						return res;
					}
				}
			}
			return {};
		}
};
