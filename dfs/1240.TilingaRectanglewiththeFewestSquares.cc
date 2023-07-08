/*
   Given a rectangle of size n x m, return the minimum number of integer-sided squares that tile the rectangle.



   Example 1:

Input: n = 2, m = 3
Output: 3
Explanation: 3 squares are necessary to cover the rectangle.
2 (squares of 1x1)
1 (square of 2x2)

Example 2:

Input: n = 5, m = 8
Output: 5

Example 3:

Input: n = 11, m = 13
Output: 6



Constraints:

1 <= n, m <= 13

*/


#include"head.h"
class Solution {
	public:
		int tilingRectangle(int n, int m) {
		int res=m*n;
		vector<int> filled(n,0);
		solve(0,0,n,m,0,res,filled);
		return res;
		}
		void solve(int x,int y,int n,int m,int tot,int &res,vector<int> &filled)
		{
			if(tot>=res) return;
			if(y==m) {x++;y=0;}
			if(x==n) {res=tot;return;}

			if((filled[x]>>y)&1)
				solve(x,y+1,n,m,tot,res,filled);
			else
			{
				int r=0,c=0;
				for(int i=x;i<n;i++)
				{
					if((filled[i]>>y)&1) break;
					r++;
				}
				for(int j=y;j<m;j++)
				{
					if((filled[x]>>j)&1) break;
					c++;
				}

				int t=min(r,c);

				for(int s=1;s<=t;s++)
				{
					for(int i=0;i<s;i++)
					{
						filled[x+s-1]|=1<<(y+i);
						filled[x+i]|=1<<(y+s-1);
					}
				solve(x,y+1,n,m,tot+1,res,filled);
				}
				for(int i=x;i<x+t;i++)
					for(int j=y;j<y+t;j++)
						filled[i]^=1<<j;
			}
		}
};


int main() 
{
	Solution s;
	cout<<s.tilingRectangle(2,3)<<endl;
	cout<<s.tilingRectangle(5,8)<<endl;
	cout<<s.tilingRectangle(11,13)<<endl;
	return 0;
}
