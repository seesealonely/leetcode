/*
   You are given an integer array rewardValues of length n, representing the values of rewards.

   Initially, your total reward x is 0, and all indices are unmarked. You are allowed to perform the following operation any number of times:

   Choose an unmarked index i from the range [0, n - 1].
   If rewardValues[i] is greater than your current total reward x, then add rewardValues[i] to x (i.e., x = x + rewardValues[i]), and mark the index i.

   Return an integer denoting the maximum total reward you can collect by performing the operations optimally.



   Example 1:

Input: rewardValues = [1,1,3,3]

Output: 4

Explanation:

During the operations, we can choose to mark the indices 0 and 2 in order, and the total reward will be 4, which is the maximum.

Example 2:

Input: rewardValues = [1,6,4,3,2]

Output: 11

Explanation:

Mark the indices 0, 2, and 1 in order. The total reward will then be 11, which is the maximum.



Constraints:

1 <= rewardValues.length <= 2000
1 <= rewardValues[i] <= 2000

*/


#include"head.h"
#include<bitset>

class Solution {
	public:
		int maxTotalReward(vector<int>& rewardValues) {
		bitset<100001> dp;
		dp[0]=true;
		sort(rewardValues.begin(),rewardValues.end());
		for(int i=0;i<rewardValues.size();i++)
		{
			int shift=1e5-(rewardValues[i]-1);
			dp|=(dp<<shift>>shift<<rewardValues[i]);
		}
		int res=1e5;
		while(!dp[res]) --res;
		return res;
		}
};


int main() 
{
	Solution s;
	vector<int> rewardValues={1,1,3,3};
	cout<<s.maxTotalReward(rewardValues)<<endl;
	rewardValues.clear();rewardValues={1,6,4,3,2};
	cout<<s.maxTotalReward(rewardValues)<<endl;
	return 0;
}
