/*
Given an array of 4 digits, return the largest 24 hour time that can be made.

The smallest 24 hour time is 00:00, and the largest is 23:59.  Starting from 00:00, a time is larger if more time has elapsed since midnight.

Return the answer as a string of length 5.  If no valid time can be made, return an empty string.

 

Example 1:

Input: [1,2,3,4]
Output: "23:41"

Example 2:

Input: [5,5,5,5]
Output: ""

 

Note:

    A.length == 4
    0 <= A[i] <= 9
*/

#include"949.LargestTimeforGivenDigits.h"

int main()
{
	int vv1[]={1,2,3,4};
	int vv2[]={5,5,5,5};
	int vv3[]={1,9,6,0};
	vector<int> v1(begin(vv1),end(vv1)),v2(begin(vv2),end(vv2)),v3(begin(vv3),end(vv3));
	Solution s;
	cout<<s.largestTimeFromDigits(v1)<<endl;
	cout<<s.largestTimeFromDigits(v2)<<endl;
	cout<<s.largestTimeFromDigits(v3)<<endl;
}
