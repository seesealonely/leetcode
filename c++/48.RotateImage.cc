#include"48.RotateImage.h"
int main(void)
{
	vector<vector<int> > v;
	int res=0;
	for(int i=0;i<3;++i)
	{	
		v.push_back({});
		for(int j=0;j<3;++j)
			v[i].push_back(++res);
	}
	Solution s;
	s.show(v);
	s.rotate(v);
	s.show(v);
	return 0;
}
