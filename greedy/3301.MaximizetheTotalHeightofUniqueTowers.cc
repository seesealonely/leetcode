/*
   You are given an array maximumHeight, where maximumHeight[i] denotes the maximum height the ith tower can be assigned.

   Your task is to assign a height to each tower so that:

   The height of the ith tower is a positive integer and does not exceed maximumHeight[i].
   No two towers have the same height.

   Return the maximum possible total sum of the tower heights. If it's not possible to assign heights, return -1.



   Example 1:

Input: maximumHeight = [2,3,4,3]

Output: 10

Explanation:

We can assign heights in the following way: [1, 2, 4, 3].

Example 2:

Input: maximumHeight = [15,10]

Output: 25

Explanation:

We can assign heights in the following way: [15, 10].

Example 3:

Input: maximumHeight = [2,2,1]

Output: -1

Explanation:

It's impossible to assign positive heights to each index so that no two towers have the same height.



Constraints:

1 <= maximumHeight.length <= 105
1 <= maximumHeight[i] <= 109

*/


#include"head.h"
class Solution {
	public:
		long long maximumTotalSum(vector<int>& maximumHeight) {
		const int n=maximumHeight.size();
		long long cur=1e9+5,res=0;
		sort(maximumHeight.rbegin(),maximumHeight.rend());
		for(int i=0;i<n;i++)
		{
			cur=min(cur,(long long)maximumHeight[i]);
			if(cur<=0) return -1;
			res+=cur;
			cur--;
		}
		return res;
		}
};


int main() 
{
	Solution s;
	vector<int> maximumHeight={2,3,4,3};
	cout<<s.maximumTotalSum(maximumHeight)<<endl;
	maximumHeight.clear();maximumHeight={15,10};
	cout<<s.maximumTotalSum(maximumHeight)<<endl;
	maximumHeight.clear();maximumHeight={2,2,1};
	cout<<s.maximumTotalSum(maximumHeight)<<endl;
	return 0;
}
