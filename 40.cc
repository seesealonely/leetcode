#include"40.h"
int main()
{
	int vv[]={10,1,2,7,6,1,5};
	vector<int > v(vv,vv+7);
	Solution s;
	sort(v.begin(),v.end());
	vector<vector<int> >	res=s.combinationSum2(v,8);
	for(int i=0;i<res.size();i++)
	{
		for(int j=0;j<res[i].size();j++)
			cout<<res[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
