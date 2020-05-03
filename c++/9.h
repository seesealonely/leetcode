#include<iostream>
using namespace std;
class Solution {
	public:
		bool isPalindrome(int x)
		{
			if(x<0)return 0;
			int  tmp=x,head=x,tail=0;
			while(tmp>0)
			{
				tail=tail*10+tmp%10;
				tmp/=10;
			}
		cout<<"head "<<head<<" tail "<<tail<<endl;	
			return head==tail;
		}
};
