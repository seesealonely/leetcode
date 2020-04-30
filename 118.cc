#include"118.h"
int main()
{
	Solution s;
	vector<vector<int> > res=s.generate(5);
	for(int i=0;i<res.size();i++)
	{
		for(int j=0;j<res[i].size();j++)
			cout<<res[i][j]<<" ";
		cout<<endl;
	}
	res=s.generate(3);
	for(int i=0;i<res.size();i++)
	{
		for(int j=0;j<res[i].size();j++)
			cout<<res[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
