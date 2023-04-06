/*
*/


#include"head.h"
class Solution {
	public:
		int minimumDifference(vector<int>& nums) {
			const int n=nums.size()/2;
			vector<vector<int>> s1(n+1),s2(n+1);

			getSub(0,0,0,s1,vector<int>(nums.begin(),nums.begin()+n));
			getSub(0,0,0,s2,vector<int>(nums.begin()+n,nums.end()));

			for(int i=0;i<=n;i++)
				sort(s2[i].begin(),s2[i].end());

			int res=INT_MAX;
			for(int i=0;i<=n;i++)
			{
				int j=n-i;
				vector<int> s=s2[j];
				for(int k=0;k<s1[i].size();k++)
				{
					int l=0,r=s.size();
					while(l<r)
					{
						int m=(l+r)>>1;
						if(s[m]>=-s1[i][k])
							r=m;
						else
							l=m+1;
					}
					if(l<s.size())
					res=min(res,abs(s1[i][k]+s[l]));
					if(l>0)
					res=min(res,abs(s1[i][k]+s[l-1]));
				}
			}
			return res;

		}
		void getSub(int i,int cnt,int diff,vector<vector<int>> &s,const vector<int> &nums)
		{
			if(i==nums.size())
			{
				s[cnt].push_back(diff);
				return ;
			}
			getSub(i+1,cnt,diff-nums[i],s,nums);
			getSub(i+1,cnt+1,diff+nums[i],s,nums);
		}
};


int main() 
{
	Solution s;
	vector<int> v={3,9,7,3};
	cout<<s.minimumDifference(v)<<endl;
	v.clear();v={-36,36};
	cout<<s.minimumDifference(v)<<endl;
	v.clear();v={2,-1,0,4,-2,-9};
	cout<<s.minimumDifference(v)<<endl;
	return 0;
}
