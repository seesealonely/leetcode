#include"78.h"
int main()
{
int v[]={1,2,3};
vector<int> nums(v,v+3);
Solution s;
vector<vector<int> > vv=s.subsets(nums);
for(int i=0;i<vv.size();i++)
{
	for(int j=0;j<vv[i].size();j++)
		cout<<vv[i][j]<<" ";
	cout<<endl;
}
return 0;
}
