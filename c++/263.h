#include<iostream>
using namespace std;
class Solution {
	public:
		bool isUgly(int num) {
			for(int i=2;i<6;i++)
			if(i==4)continue;
			else		while(num%i==0) num/=i;
			return num==1;       
		}
		void print(bool b)
		{
			if(b)
				cout<<"Ugly";
			else 
				cout<<"No Ugly";
		}
};
