/*
   You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.

   Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.

   Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.

   Example 1:

Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]

Note:

The number of given pairs will be in the range [1, 1000].

*/

#include"646.MaximumLengthofPairChain.h"

int main()
{
	vector<vector<int> > vv;
	vector<int> v;
	v.push_back(1),v.push_back(2);
	vv.push_back(v);
	v.clear();
	v.push_back(2),v.push_back(3);
	vv.push_back(v);
	v.clear();
	v.push_back(3),v.push_back(4);
	vv.push_back(v);
	Solution s;
	cout<<s.findLongestChain(vv)<<endl;
	return 0;
}
