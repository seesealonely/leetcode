#include"77.h"
int main()
{
	Solution s;
	vector<vector<int> > res=s.combine(7,7);
	for(int i=0;i<res.size();i++)
	{
		for(int j=0;j<res[i].size();j++)
			cout<<res[i][j]<<" ";
		cout<<endl;
	}

	return 0;	
}
