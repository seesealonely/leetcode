/*
Given an array A of integers, we must modify the array in the following way: we choose an i and replace A[i] with -A[i], and we repeat this process K times in total.  (We may choose the same index i multiple times.)

Return the largest possible sum of the array after modifying it in this way.

 

Example 1:

Input: A = [4,2,3], K = 1
Output: 5
Explanation: Choose indices (1,) and A becomes [4,-2,3].

Example 2:

Input: A = [3,-1,0,2], K = 3
Output: 6
Explanation: Choose indices (1, 2, 2) and A becomes [3,1,0,2].

Example 3:

Input: A = [2,-3,-1,5,-4], K = 2
Output: 13
Explanation: Choose indices (1, 4) and A becomes [2,3,-1,5,4].

 

Note:

    1 <= A.length <= 10000
    1 <= K <= 10000
    -100 <= A[i] <= 100

*/

#include"1005.MaximizeSumOfArrayAfterKNegations.h"

int main()
{
	Solution s;
	vector<int> v;
	v.push_back(4);v.push_back(2);v.push_back(3);
	cout<<s.largestSumAfterKNegations(v,1)<<endl;
	v.clear();v.push_back(3);v.push_back(-1);v.push_back(0);v.push_back(2);
	cout<<s.largestSumAfterKNegations(v,3)<<endl;
	v.clear();v.push_back(2);v.push_back(-3);v.push_back(-1);v.push_back(5);v.push_back(-4);
	cout<<s.largestSumAfterKNegations(v,2)<<endl;
	return 0;
}
