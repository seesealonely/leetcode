#include<iostream>
#include<vector>
using namespace std;
class Solution
{
	public:
		vector<int> generate(int numRows)
		{
			vector<int> res(numRows+1,0); 
				res[0]=1;
			for(int i=1;i<numRows+1;i++)
			{
				for(int j=i;j>0;j--)
					res[j]+=res[j-1];
			}	
			return res;
		}
};
