/*
   Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

   Si % Sj = 0 or Sj % Si = 0.

   If there are multiple solutions, return any subset is fine.

   Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)

Example 2:

Input: [1,2,4,8]
Output: [1,2,4,8]

*/

#include"368.LargestDivisibleSubset.h"

int main()
{
	Solution s;
	vector<int> v;
	v.push_back(1);	v.push_back(2);	v.push_back(3);
	show(s.largestDivisibleSubset(v));
	v.clear();
	v.push_back(1);	v.push_back(2);	v.push_back(4);	v.push_back(8);
	show(s.largestDivisibleSubset(v));
	return 0;
}
