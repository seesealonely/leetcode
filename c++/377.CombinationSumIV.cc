/*
 Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.

Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers? 
*/

#include"377.CombinationSumIV.h"
int main()
{
	vector<int> v;
	v.push_back(1);	v.push_back(2);	v.push_back(3);
	Solution s;
	cout<<s.combinationSum4(v,4)<<endl;
	return 0;
}
