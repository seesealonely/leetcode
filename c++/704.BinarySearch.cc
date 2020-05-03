/*
Given a sorted (in ascending order) integer array nums of n elements and a target value, write a function to search target in nums. If target exists, then return its index, otherwise return -1.


Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1

 

Note:

    You may assume that all elements in nums are unique.
    n will be in the range [1, 10000].
    The value of each element in nums will be in the range [-9999, 9999].

*/

#include"704.BinarySearch.h"

int main()
{
	int e1[]={-1,0,3,5,9,12};
	int e2[]={-1,0,3,5,9,12};
	vector<int> v1(e1,e1+6);
	vector<int> v2(e2,e2+6);
	Solution s;
	cout<<s.search(v1,9)<<endl;
	cout<<s.search(v2,2)<<endl;
	v2.clear();v2.push_back(10000);
	cout<<s.search(v2,10000)<<endl;
	return 0;
}
