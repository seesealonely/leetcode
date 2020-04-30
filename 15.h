#include<iostream>
#include<iterator>
#include <algorithm> 
#include<vector>
using namespace std;
vector<int> input()
{
	int vv[]={-1,-2,-3,4,1,3,0,3,-2,1,-2,2,-1,1,-5,4,-3};
	vector<int> v(vv,vv+16);
	return v;
}
void findResult(vector<int>&nums,vector<vector<int> > & v,int result,int beg,int mid,int end)
{

	if((nums.size()>=3)&&((end<=nums.size()-1)))
	{
		if((nums[beg]+nums[mid]+nums[end])==result)
		{
			vector<int> in;
			if(nums[beg]>nums[mid])
			{
				in.push_back(nums[beg]);
				in.push_back(nums[mid]);
			}
			else
			{

				in.push_back(nums[mid]);
				in.push_back(nums[beg]);
			}
			if(nums[end]>in[0])
				in.insert(in.begin(),nums.at(end));
			else if(nums[end]>in[1])
				in.insert(in.begin()+1,nums.at(end));
			else 
				in.push_back(nums[end]);
			if(find(v.begin(),v.end(),in)!=v.end())
				;
			else
			{
				v.push_back(in);
				cout<<nums[beg]<<" "<<nums[mid]<<" "<<nums[end]<<endl;	
			}
		}
		findResult(nums,v,result,beg,mid,end+1);
		findResult(nums,v,result,beg,mid+1,end+1);
		findResult(nums,v,result,beg+1,mid+1,end+1);
	}
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
class Solution 
{
	public:
		//vector<vector<int>> threeSum(vector<int>& nums)
		vector<vector<int> > threeSum(vector<int>& nums,int input)
		{
			vector<vector<int> > v;

			findResult(nums,v,0,0,1,2);	
			return v;
		}
};
