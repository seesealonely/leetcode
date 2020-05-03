#include"27.h"
int main(void)
{

	Solution s;
	vector<int> v;
	v.push_back(3);
	v.push_back(2);
	v.push_back(2);
	v.push_back(3);

int   res=s.removeElement(v,3);
cout<<"#############################"<<endl;
for(int i=0;i<v.size();i++)
cout<<v[i]<<" ";
cout<<endl;
cout<<"#############################"<<endl;
cout<<" result: "<<res<<endl;
return 0;
}
