/*
Given an integer array, return the k-th smallest distance among all the pairs. The distance of a pair (A, B) is defined as the absolute difference between A and B.

Example 1:

Input:
nums = [1,3,1]
k = 1
Output: 0 
Explanation:
Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.

Note:

    2 <= len(nums) <= 10000.
    0 <= nums[i] < 1000000.
    1 <= k <= len(nums) * (len(nums) - 1) / 2.

*/

#include"719.FindK-thSmallestPairDistance.h"

int main()
{
	Solution s;
	vector<int> v;
	v.push_back(1);v.push_back(3);v.push_back(1);
	cout<<s.smallestDistancePair(v,1)<<endl;
	v[2]=6;
	cout<<s.smallestDistancePair(v,3)<<endl;
	return 0;
}
