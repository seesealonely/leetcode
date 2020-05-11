/*
Return the length of the shortest, non-empty, contiguous subarray of A with sum at least K.

If there is no non-empty subarray with sum at least K, return -1.



Example 1:

Input: A = [1], K = 1
Output: 1

Example 2:

Input: A = [1,2], K = 4
Output: -1

Example 3:

Input: A = [2,-1,2], K = 3
Output: 3



Note:

1 <= A.length <= 50000
-10 ^ 5 <= A[i] <= 10 ^ 5
1 <= K <= 10 ^ 9

*/
#include"862.ShortestSubarraywithSumatLeastK.h"
int main() 
 {
 	 Solution s;
	vector<int> v;
	v.push_back(1);
 	 cout<<s.shortestSubarray(v,1)<<endl;
	v.push_back(2);
 	 cout<<s.shortestSubarray(v,4)<<endl;
	v.clear();v.push_back(2);v.push_back(-1);v.push_back(2);
 	 cout<<s.shortestSubarray(v,3)<<endl;
 	 return 0;
 }
