#include"54.SpiralMatrix.h"
int main()
{
	vector<vector<int> > v;
	int count=0;
	for(int i=0;i<3;++i)
	{
		v.push_back({});
		for(int j=0;j<3;++j)
		v[i].push_back(++count);
	}
	Solution s;
	vector<int> res=s.spiralOrder(v);
	s.show(res);
	return 0;
}
