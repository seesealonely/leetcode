/*
Given an array A of integers, return the number of (contiguous, non-empty) subarrays that have a sum divisible by K.

 

Example 1:

Input: A = [4,5,0,-2,-3,1], K = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by K = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

 

Note:

    1 <= A.length <= 30000
    -10000 <= A[i] <= 10000
    2 <= K <= 10000

*/

#include"974.SubarraySumsDivisiblebyK.h"

int main()
{
	vector<int> v;
	v.push_back(4);v.push_back(5);v.push_back(0);v.push_back(-2);v.push_back(-3);v.push_back(1);
	Solution s;
	cout<<s.subarraysDivByK(v,5)<<endl;
	return 0;
}
