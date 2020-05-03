#include"35.h"
int main()
{
	Solution s;
	int v[]={1,3,5,7};
	vector<int> nums(v,v+3);
	cout<<"int v[]={1,3,5,7}"<<endl;;
	cout<<"find 5"<<endl;;
	cout<<s.searchInsert(nums,5)<<endl;
	cout<<"find 2"<<endl;;
	cout<<s.searchInsert(nums,2)<<endl;
	cout<<"find 7"<<endl;;
	cout<<s.searchInsert(nums,7)<<endl;
	cout<<"find 0"<<endl;;
	cout<<s.searchInsert(nums,0)<<endl;
	return 0;
}
