#include"74.h"
int main()
{
	vector<vector<int> >v(1);
	int num=1;
	for(int i=0;i<v.size();i++)
	{
		v[i].resize(4);
		for(int j=0;j<4;j++)
		{
			v[i][j]=num;
			num+=2;	
		}
	}
	Solution s;
	cout<<s.searchMatrix(v,0)<<endl;
	return 0;
}
