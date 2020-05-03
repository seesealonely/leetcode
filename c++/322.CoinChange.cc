/*
 You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.

Note:
You may assume that you have an infinite number of each kind of coin. 
*/
#include"322.CoinChange.h"
int main()
{
	vector<int>v(3,0);v[0]=1;v[1]=2;v[2]=5;
	Solution s;
	cout<<s.coinChange(v,11)<<endl;
	vector<int> vv(1,2);
	cout<<s.coinChange(vv,3)<<endl;
	return 0;
}
