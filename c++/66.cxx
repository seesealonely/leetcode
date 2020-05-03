#include"66.h"
int main()
{
	Solution s;
	vector<int> i(9,9);
	vector<int> j(9,8);
	vector<int> w=s.plusOne(i);
	for(int k=0;k<w.size();k++)
		cout<<w[k];
		cout<<endl;
	w=s.plusOne(j);
	for(int k=0;k<w.size();k++)
		cout<<w[k];
		cout<<endl;
	return 0;
}
