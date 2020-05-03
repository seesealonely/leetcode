#include"75.h"
int main()
{
int v[]={2,1,1,0};
vector<int> vv(v,v+4);
Solution s;
s.sortColors(vv);
for(int  i=0;i<vv.size();i++)
cout<<vv[i]<<" ";
cout<<endl;
return 0;
}
