/*
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:

Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

Note:

    Then length of the input array is in range [1, 10,000].
    The input array may contain duplicates, so ascending order here means <=.

*/

#include"581.ShortestUnsortedContinuousSubarray.h"

int main()
{
	int e1[]={2, 6, 4, 8, 10, 9, 15};
	vector<int> v1(e1,e1+7);
	Solution s;
	cout<<s.findUnsortedSubarray(v1)<<endl;
	v1.clear();
	v1.push_back(2);v1.push_back(1);
	cout<<s.findUnsortedSubarray(v1)<<endl;
	return 0;
}
