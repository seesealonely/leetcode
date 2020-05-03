#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
void show(vector<vector<int> > & s)
{
	for(vector<vector<int> >::iterator it=s.begin();it!=s.end();++it)
	{
		for(vector<int>::iterator it1=(*it).begin();it1!=(*it).end();++it1)
			cout<<*it1<<" ";
		cout<<endl;
	}
	s.clear();
}

class Solution {
	public:
		vector<vector<int> > fourSum(vector<int>& nums, int target){
			vector<vector<int> >res;
			if(nums.size()<=3)return {};
			sort(nums.begin(),nums.end());
					vector<int> v;
			for(int i=0;i<(nums.size()-3);i++)
			{
				for(int j=i+1;j<(nums.size()-2);j++)
				{
					int begin=j+1,end=nums.size()-1;
					while(begin<end)
					{
					int sum=nums[i]+nums[j]+nums[begin]+nums[end];
						if(sum==target)
						{
							v.clear();
							v.push_back(nums[i]);		
							v.push_back(nums[j]);		
							v.push_back(nums[begin]);		
							v.push_back(nums[end]);		
							res.push_back(v);
							while(begin<end&&v[2]==nums[begin])begin++;
							while(begin<end&&v[3]==nums[end])end--;
						}
						else if(sum>target)
							end--;
						else begin++;
					while(j<nums.size()-2&&nums[j]==nums[j+1])j++;
					}
					while(i<nums.size()-3&&nums[i]==nums[i+1])i++;
				}
			}
			return res;

		}
};
