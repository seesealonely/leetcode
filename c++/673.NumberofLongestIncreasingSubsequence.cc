/*
   Given an unsorted array of integers, find the number of longest increasing subsequence.

   Example 1:

Input: [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].

Example 2:

Input: [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.

Note: Length of the given array will be not exceed 2000 and the answer is guaranteed to be fit in 32-bit signed int. 
*/

#include"673.NumberofLongestIncreasingSubsequence.h"

int main()
{
	vector<int> v;
	v.push_back(1);v.push_back(3);v.push_back(5);v.push_back(4);v.push_back(7);
	Solution s;
	cout<<s.findNumberOfLIS(v)<<endl;
	v.clear();
	v.push_back(2);v.push_back(2);v.push_back(2);v.push_back(2);v.push_back(2);
	cout<<s.findNumberOfLIS(v)<<endl;
	v.clear();
	v.push_back(1);v.push_back(2);
	cout<<s.findNumberOfLIS(v)<<endl;
	return 0;
}
