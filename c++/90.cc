#include"90.h"
int main()
{
	int vv[]={1,2,2,3,4};
	vector<int> v(vv,vv+5);
	Solution s;
	vector<vector<int> > res=s.subsetsWithDup(v);
	for(int i=0;i<res.size();i++)
	{
	for(int j=0;j<res[i].size();j++)
	cout<<res[i][j]<<" ";
	cout<<endl;
	}
	return 0;
}
