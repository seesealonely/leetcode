#include<iostream>
#include<vector>
using namespace std;
class Solution {
	public:
		vector<vector<int> > generateMatrix(int n) {
			vector<vector<int> > res(n,vector<int>(n));
			for(int h=0,v=0,num=1,i=0;i<=n/2;i++)
			{
				v=i;
				while(v<=n-i-1)
					res[h][v++]=num++;	
				h=i+1;
				while(h<=n-i-1)
					res[h++][n-i-1]=num++;
				v=n-i-1;	
				while(v>i)
					res[n-i-1][--v]=num++;
				h=n-i-1;
				while(h>i+1)
					res[--h][i]=num++;
			} 
/*			for(int m=0;m<n;m++)
			{
				for(int k=0;k<n;k++)
					cout<<res[m][n]<<" ";
				cout<<endl;
			}
*/
			return res;
		}
};
