#include<iostream>
using namespace std;
class Solution {
	public:
		int hammingWeight(unsigned int n) {
			int next=n,num;
			num=next?1:0;
			while(next&=(next-1))
			{
				next>>1;
				num++;
			}
			return num;
		}
};
