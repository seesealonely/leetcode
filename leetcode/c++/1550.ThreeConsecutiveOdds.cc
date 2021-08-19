/*
Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.



Example 1:

Input: arr = [2,6,4,1]
Output: false
Explanation: There are no three consecutive odds.

Example 2:

Input: arr = [1,2,34,3,4,5,7,23,12]
Output: true
Explanation: [5,7,23] are three consecutive odds.



Constraints:

1 <= arr.length <= 1000
1 <= arr[i] <= 1000
*/
#include"1550.ThreeConsecutiveOdds.h"
int main() 
 {
 	 Solution s;
	 vector<int> v={2,6,4,1};
 	 cout<<s.threeConsecutiveOdds(v)<<endl;
	 v.clear();v={1,2,34,3,4,5,7,23,12};
 	 cout<<s.threeConsecutiveOdds(v)<<endl;
	 v.clear();v={1,3,2};
 	 cout<<s.threeConsecutiveOdds(v)<<endl;
 	 return 0;
 }
