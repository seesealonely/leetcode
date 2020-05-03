/*
Given an array A of integers, for each integer A[i] we need to choose either x = -K or x = K, and add x to A[i] (only once).

After this process, we have some array B.

Return the smallest possible difference between the maximum value of B and the minimum value of B.

 

Example 1:

Input: A = [1], K = 0
Output: 0
Explanation: B = [1]

Example 2:

Input: A = [0,10], K = 2
Output: 6
Explanation: B = [2,8]

Example 3:

Input: A = [1,3,6], K = 3
Output: 3
Explanation: B = [4,6,3]

 

Note:

    1 <= A.length <= 10000
    0 <= A[i] <= 10000
    0 <= K <= 10000
*/

#include"910.SmallestRangeII.h"

int main()
{
	Solution s;
	vector<int> v;
	v.push_back(1);
	cout<<s.smallestRangeII(v,0)<<endl;
	v.clear();v.push_back(0);v.push_back(10);
	cout<<s.smallestRangeII(v,2)<<endl;
	v.clear();v.push_back(1);v.push_back(3);v.push_back(6);
	cout<<s.smallestRangeII(v,3)<<endl;
	return 0;
}
