/*
Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into sets of k consecutive numbers
Return True if its possible otherwise return False.



Example 1:

Input: nums = [1,2,3,3,4,4,5,6], k = 4
Output: true
Explanation: Array can be divided into [1,2,3,4] and [3,4,5,6].

Example 2:

Input: nums = [3,2,1,2,3,4,3,4,5,9,10,11], k = 3
Output: true
Explanation: Array can be divided into [1,2,3] , [2,3,4] , [3,4,5] and [9,10,11].

Example 3:

Input: nums = [3,3,2,2,1,1], k = 3
Output: true

Example 4:

Input: nums = [1,2,3,4], k = 3
Output: false
Explanation: Each array should be divided in subarrays of size 3.



Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
1 <= k <= nums.length
*/
#include"1296.DivideArrayinSetsofKConsecutiveNumbers.h"
int main() 
 {
 	 Solution s;
	vector<int> v={1,2,3,3,4,4,5,6};
 	 cout<<s.isPossibleDivide(v,4)<<endl;
	v.clear(); v={3,2,1,2,3,4,3,4,5,9,10,11};
 	 cout<<s.isPossibleDivide(v,3)<<endl;
	v.clear(); v={3,2,1,3,2,1};
 	 cout<<s.isPossibleDivide(v,3)<<endl;
	v.clear(); v={1,2,3,4};
 	 cout<<s.isPossibleDivide(v,3)<<endl;
 	 return 0;
 }

