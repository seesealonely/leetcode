/*
We define a harmonious array is an array where the difference between its maximum value and its minimum value is exactly 1.

Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.

Example 1:

Input: [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].

Note: The length of the input array will not exceed 20,000. 
*/

#include"594.LongestHarmoniousSubsequence.h"

int main()
{
	int e1[]={1,3,2,2,5,2,3,7};
	vector<int> v1(e1,e1+8);
	Solution s;
	cout<<s.findLHS(v1)<<endl;
	cout<<s.findLHS_(v1)<<endl;
	return 0;
}
