/*
Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.



Example 1:

Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.

Example 2:

Input: nums = [0]
Output: 0

Example 3:

Input: nums = [2,4]
Output: 6

Example 4:

Input: nums = [8,10,2]
Output: 10

Example 5:

Input: nums = 9
Output: 127



Constraints:

1 <= nums.length <= 2 *10^5
0 <= nums[i] <= 231 - 1

*/
#include"421.MaximumXORofTwoNumbersinanArray.h"
int main() 
 {
 	 Solution s;
	 vector<int> v={3,10,5,25,2,8};
	 cout<<"1<<1="<<(1<<1)<<endl;
 	 cout<<s.findMaximumXOR(v)<<endl;
	 v.clear();v={0};
 	 cout<<s.findMaximumXOR(v)<<endl;
	 v.clear();v={2,4};
 	 cout<<s.findMaximumXOR(v)<<endl;
	 v.clear();v={8,10,2};
 	 cout<<s.findMaximumXOR(v)<<endl;
	 v.clear();v={14,70,53,83,49,91,36,80,92,51,66,70};
 	 cout<<s.findMaximumXOR(v)<<endl;
 	 return 0;
 }
