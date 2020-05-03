#include<iostream>
#include<iterator>
#include <algorithm> 
#include<vector>
using namespace std;
vector<int> input()
{
	int vv[]={-9,14,-7,-8,9,1,-10,-8,13,12,6,9,3,-3,-15,-15,1,8,-7,-4,-6,8,2,-10,8,11,-15,3,0,-11,-1,-1,10,0,6,5,-14,3,12,-15,-7,-5,9,11,-1,1,3,-15,-5,11,-12,-4,-4,-2,-6,-10,-6,-6,0,2,-9,14,-14,-14,-9,-1,-2,-7,-12,-13,-15,-4,-3,1,14,3,-12,3,3,-10,-9,-1,-7,3,12,-6,0,13,4,-15,0,2,6,1,3,13,8,-13,13,11,11,13,14,-6};
	vector<int> v(vv,vv+103);
	return v;
}
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

int findTimes(vector<vector<int> > v,vector<int> tmp)
{
	if(find(v.begin(),v.end(),tmp)!=v.end())
		return true;
	else return false;
}
class Solution 
{
	public:
		vector<vector<int> > threeSum(vector<int>& nums)
		{
			vector<vector<int> >res(0);
			if(nums.size()<=2)return {};	
			sort(nums.begin(),nums.end());
			for(int i=0;i<=nums.size()-3;i++)
			{
				int begin=i+1,end=nums.size()-1;
				while(begin<end)
				{
					if(nums[i]+nums[begin]+nums[end]==0)
					{
						vector<int> v;
						v.push_back(nums[i]);
						v.push_back(nums[begin]);
						v.push_back(nums[end]);
						res.push_back(v);
						while((begin<end)&&(nums[begin]==v[1]))
							begin++;
						while((begin<end)&&(nums[end]==v[2]))
							end--;
					}
					else if(nums[i]+nums[begin]+nums[end]<0)
						begin++; 
					else
						end--;
				}
				while((i<nums.size()-1)&&(nums[i]==nums[i+1])) i++;
			}	
			return res;
		}
};
