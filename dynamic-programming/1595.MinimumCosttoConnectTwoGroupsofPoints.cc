/*
   You are given two groups of points where the first group has size1 points, the second group has size2 points, and size1 >= size2.

   The cost of the connection between any two points are given in an size1 x size2 matrix where cost[i][j] is the cost of connecting point i of the first group and point j of the second group. The groups are connected if each point in both groups is connected to one or more points in the opposite group. In other words, each point in the first group must be connected to at least one point in the second group, and each point in the second group must be connected to at least one point in the first group.

   Return the minimum cost it takes to connect the two groups.



   Example 1:

Input: cost = [[15, 96], [36, 2]]
Output: 17
Explanation: The optimal way of connecting the groups is:
1--A
2--B
This results in a total cost of 17.

Example 2:

Input: cost = [[1, 3, 5], [4, 1, 1], [1, 5, 3]]
Output: 4
Explanation: The optimal way of connecting the groups is:
1--A
2--B
2--C
3--A
This results in a total cost of 4.
Note that there are multiple points connected to point 2 in the first group and point A in the second group. This does not matter as there is no limit to the number of points that can be connected. We only care about the minimum total cost.

Example 3:

Input: cost = [[2, 5, 1], [3, 4, 7], [8, 1, 2], [6, 2, 4], [3, 8, 8]]
Output: 10



Constraints:

size1 == cost.length
size2 == cost[i].length
1 <= size1, size2 <= 12
size1 >= size2
0 <= cost[i][j] <= 100

*/


#include"head.h"
class Solution {
	public:
		int connectTwoGroups(vector<vector<int>>& cost) {
		const int r=cost.size(),c=cost.front().size();

		vector<vector<int>> dp(r+1,vector<int>(1<<c,INT_MAX>>1));
		vector<vector<int>> costs(r+1,vector<int>(1<<c,0));

		for(int i=1;i<=r;i++)
		{
			costs[i][0]=INT_MAX>>1;
			for(int s=1;s<(1<<c);s++)
				for(int j=0;j<c;j++)
					if((s>>j)&1)
						costs[i][s]+=cost[i-1][j];
		}

		dp[0][0]=0;
		for(int i=1;i<=r;i++)
			for(int s=1;s<(1<<c);s++)
			{
				for(int sub=s;sub>0;sub=(sub-1)&s)
					dp[i][s]=min(dp[i][s],dp[i-1][s^sub]+costs[i][sub]);

				for(int j=0;j<c;j++)
					dp[i][s|(1<<j)]=min(dp[i][s|(1<<j)],dp[i-1][s]+cost[i-1][j]);
			}
		return dp[r][(1<<c)-1];
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> cost={{15,96},{36,2}};
	cout<<s.connectTwoGroups(cost)<<endl;
	cost.clear();cost={{1,3,5},{4,1,1},{1,5,3}};
	cout<<s.connectTwoGroups(cost)<<endl;
	cost.clear();cost={{2,5,1},{3,4,7},{8,1,2},{6,2,4},{3,8,8}};
	cout<<s.connectTwoGroups(cost)<<endl;
	return 0;
}
