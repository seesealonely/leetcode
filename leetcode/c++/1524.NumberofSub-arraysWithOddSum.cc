/*
Given an array of integers arr. Return the number of sub-arrays with odd sum.

As the answer may grow large, the answer must be computed modulo 10^9 + 7.



Example 1:

Input: arr = [1,3,5]
Output: 4
Explanation: All sub-arrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
All sub-arrays sum are [1,4,9,3,8,5].
Odd sums are 9 so the answer is 4.

Example 2:

Input: arr = [2,4,6]
Output: 0
Explanation: All sub-arrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
All sub-arrays sum are [2,6,12,4,10,6].
All sub-arrays have even sum and the answer is 0.

Example 3:

Input: arr = [1,2,3,4,5,6,7]
Output: 16

Example 4:

Input: arr = 9
Output: 4

Example 5:

Input: arr = [7]
Output: 1



Constraints:

1 <= arr.length <= 10^5
1 <= arr[i] <= 100
*/
#include"1524.NumberofSub-arraysWithOddSum.h"
int main() 
 {
 	 Solution s;
	 vector<int> v={1,3,5};
 	 cout<<s.numOfSubarrays(v)<<endl;
	 v.clear();v={2,4,6};
 	 cout<<s.numOfSubarrays(v)<<endl;
	 v.clear();v={1,2,3,4,5,6,7};
 	 cout<<s.numOfSubarrays(v)<<endl;
	 v.clear();v={100,100,99,99};
 	 cout<<s.numOfSubarrays(v)<<endl;
	 v.clear();v={7};
 	 cout<<s.numOfSubarrays(v)<<endl;
 	 return 0;
 }
