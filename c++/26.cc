#include"26.h"
int main()
{
	int in[]={1,1,2};
	vector<int>  input(in,in+3);
	Solution s;
	cout<<"###################"<<endl;
	cout<<s.removeDuplicates(input)<<endl;
	cout<<"###################"<<endl;
	for(int i=0;i<input.size();i++)
	cout<<input[i]<<" ";
	cout<<endl;
	int in1[]={0,0,0,0};
	vector<int>  input1(in1,in1+4);
	cout<<"###################"<<endl;
	cout<<s.removeDuplicates(input1)<<endl;
	cout<<"###################"<<endl;
	for(int i=0;i<input1.size();i++)
	cout<<input1[i]<<" ";
	cout<<endl;
	return 0;
}
