/*
   You are given positive integers n and target.

   An array nums is beautiful if it meets the following conditions:

   nums.length == n.
   nums consists of pairwise distinct positive integers.
   There doesn't exist two distinct indices, i and j, in the range [0, n - 1], such that nums[i] + nums[j] == target.

   Return the minimum possible sum that a beautiful array could have.



   Example 1:

Input: n = 2, target = 3
Output: 4
Explanation: We can see that nums = [1,3] is beautiful.
- The array nums has length n = 2.
- The array nums consists of pairwise distinct positive integers.
- There doesn't exist two distinct indices, i and j, with nums[i] + nums[j] == 3.
It can be proven that 4 is the minimum possible sum that a beautiful array could have.

Example 2:

Input: n = 3, target = 3
Output: 8
Explanation: We can see that nums = [1,3,4] is beautiful.
- The array nums has length n = 3.
- The array nums consists of pairwise distinct positive integers.
- There doesn't exist two distinct indices, i and j, with nums[i] + nums[j] == 3.
It can be proven that 8 is the minimum possible sum that a beautiful array could have.

Example 3:

Input: n = 1, target = 1
Output: 1
Explanation: We can see, that nums = [1] is beautiful.



Constraints:

1 <= n <= 105
1 <= target <= 105

*/


#include"head.h"
class Solution {
	public:
		long long minimumPossibleSum(int n, int target) {
		const long long m=target/2;
	
		if(m>=n)
			return (long long) n*(n+1)/2;
		return m*(m+1)/2+(target+target+n-m-1)*(n-m)/2;
		}
};


int main() 
{
	Solution s;
	cout<<s.minimumPossibleSum(2,3)<<endl;
	cout<<s.minimumPossibleSum(3,3)<<endl;
	cout<<s.minimumPossibleSum(1,1)<<endl;
	return 0;
}
