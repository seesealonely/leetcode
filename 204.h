#include<iostream>
#include<vector>
using namespace std;
class Solution {
	public:
		int countPrimes(int n) {
			vector<bool> result(n,false);
			int res=0;
			for(int i=2;i<n;i++)
			{
				if(!result[i])
				{
				++res;	
				for(int j=2;j*i<n;j++)
					result[j*i]=true;
				}
			} 
			return res;
		}
};
