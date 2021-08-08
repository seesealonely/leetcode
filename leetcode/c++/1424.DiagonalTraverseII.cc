/*
Given a list of lists of integers, nums, return all elements of nums in diagonal order as shown in the below images.



Example 1:

Input: nums = [[1,2,3],[4,5,6],[7,8,9]]
Output: 9

Example 2:

Input: nums = [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
Output: 9

Example 3:

Input: nums = [[1,2,3],[4],[5,6,7],[8],[9,10,11]]
Output: 9

Example 4:

Input: nums = [[1,2,3,4,5,6]]
Output: [1,2,3,4,5,6]



Constraints:

1 <= nums.length <= 10^5
1 <= nums[i].length <= 10^5
1 <= nums[i][j] <= 10^9
There at most 10^5 elements in nums.
*/
#include"1424.DiagonalTraverseII.h"
int main() 
 {
 	 Solution s;
	 vector<vector<int> > v= {{1,2,3},{4,5,6},{7,8,9}};
 	 show(s.findDiagonalOrder(v));
	 v.clear();v={{1,2,3,4,5},{6,7},{8},{9,10,11},{12,13,14,15,16}};
 	 show(s.findDiagonalOrder(v));
	 v.clear();v={{1,2,3},{4},{5,6,7},{8},{9,10,11}};
 	 show(s.findDiagonalOrder(v));
	 v.clear();v={{1,2,3,4,5,6}};
 	 show(s.findDiagonalOrder(v));
 	 return 0;
 }
