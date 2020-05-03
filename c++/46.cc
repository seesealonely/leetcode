#include"46.h"
int main()
{
	int v[]={5,4,3};
	vector<int >  vv(v,v+3);
	Solution s;
	vector<vector<int> > res=s.permute(vv);
	for(int i=0;i<res.size();i++)
	{
	for(int j=0;j<res[i].size();j++)
	cout<<res[i][j]<<" ";
	cout<<endl;
	}
	return 0;
}
