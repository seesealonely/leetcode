/*
   You are given two numeric strings num1 and num2 and two integers max_sum and min_sum. We denote an integer x to be good if:

   num1 <= x <= num2
   min_sum <= digit_sum(x) <= max_sum.

   Return the number of good integers. Since the answer may be large, return it modulo 109 + 7.

   Note that digit_sum(x) denotes the sum of the digits of x.



   Example 1:

Input: num1 = "1", num2 = "12", min_sum = 1, max_sum = 8
Output: 11
Explanation: There are 11 integers whose sum of digits lies between 1 and 8 are 1,2,3,4,5,6,7,8,10,11, and 12. Thus, we return 11.

Example 2:

Input: num1 = "1", num2 = "5", min_sum = 1, max_sum = 5
Output: 5
Explanation: The 5 integers whose sum of digits lies between 1 and 5 are 1,2,3,4, and 5. Thus, we return 5.



Constraints:

1 <= num1 <= num2 <= 1022
1 <= min_sum <= max_sum <= 400

*/


#include"head.h"
class Solution {
	public:
		int count(string num1, string num2, int min_sum, int max_sum) {
		init(num2.size(),max_sum);

		int res=0;
		res=(res+solve(num2,max_sum))%mod;
		res=(res-solve(num2,min_sum-1))%mod;
		res=(res-solve(num1,max_sum))%mod;
		res=(res+solve(num1,min_sum-1))%mod;
		
		int tot=0;
		for(int i=0;i<num1.size();i++)
			tot+=num1[i]-'0';

		if(min_sum<=tot&&tot<=max_sum)
			res++;

		return (res+mod)%mod;
		}

	private:
		const int mod=1e9+7;
		static const int L=30,S=405;
		int f[L][S],g[L][S];
		int init(int n,int m)
		{
			f[0][0]=g[0][0]=1;
			for(int j=1;j<=m;j++)
			{
				f[0][j]=1;
				g[0][j]=(g[0][j-1]+f[0][j])%mod;
			}
			for(int i=1;i<n;i++)
			{
				f[i][0]=g[i][0]=1;
				for(int j=1;j<=m;j++)
				{
					f[i][j]=(f[i][j-1]+f[i-1][j])%mod;
					if(j>=10)
						f[i][j]=(f[i][j]-f[i-1][j-10])%mod;
					g[i][j]=(g[i][j-1]+f[i][j])%mod;
				}
			}
		}
		int solve(string num,int sum)
		{
			const int n=num.size();
			int res=0;
			for(int i=0;i<n;i++)
			{
				int x=num[i]-'0';
				res=(res+g[n-1-i][sum])%mod;

				if(sum>=x)
					res=(res-g[n-1-i][sum-x])%mod;
				sum-=x;
				if(sum<0)
					return res;
			}
			return res+1;
		}
};


int main() 
{
	Solution s;
	cout<<s.count("1","12",1,8)<<endl;
	cout<<s.count("1","5",1,5)<<endl;
	return 0;
}
