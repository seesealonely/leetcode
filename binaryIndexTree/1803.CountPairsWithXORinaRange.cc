/*
   Given a (0-indexed) integer array nums and two integers low and high, return the number of nice pairs.

   A nice pair is a pair (i, j) where 0 <= i < j < nums.length and low <= (nums[i] XOR nums[j]) <= high.



   Example 1:

Input: nums = [1,4,2,7], low = 2, high = 6
Output: 6
Explanation: All nice pairs (i, j) are as follows:
- (0, 1): nums[0] XOR nums[1] = 5 
- (0, 2): nums[0] XOR nums[2] = 3
- (0, 3): nums[0] XOR nums[3] = 6
- (1, 2): nums[1] XOR nums[2] = 6
- (1, 3): nums[1] XOR nums[3] = 3
- (2, 3): nums[2] XOR nums[3] = 5

Example 2:

Input: nums = [9,8,4,2,1], low = 5, high = 14
Output: 8
Explanation: All nice pairs (i, j) are as follows:
​​​​​    - (0, 2): nums[0] XOR nums[2] = 13
- (0, 3): nums[0] XOR nums[3] = 11
- (0, 4): nums[0] XOR nums[4] = 8
- (1, 2): nums[1] XOR nums[2] = 12
- (1, 3): nums[1] XOR nums[3] = 10
- (1, 4): nums[1] XOR nums[4] = 9
- (2, 3): nums[2] XOR nums[3] = 6
- (2, 4): nums[2] XOR nums[4] = 5



Constraints:

1 <= nums.length <= 2 * 104
1 <= nums[i] <= 2 * 104
1 <= low <= high <= 2 * 104

*/

#define c11
#include"head.h"
class Solution {
	public:
		int countPairs(vector<int>& nums, int low, int high) {
			int res=0;
			unordered_map<int,int> cnt;

			for(int i=0;i<nums.size();i++)
				cnt[nums[i]]++;

			for(high++;high;high>>=1,low>>=1)
			{
				unordered_map<int,int> next;
				for(unordered_map<int,int>::iterator it=cnt.begin();it!=cnt.end();it++)
				{
					if(high&1&&cnt.count(it->first^(high-1))) res+=it->second*cnt[it->first^(high-1)];
					if(low&1&&cnt.count(it->first^(low-1))) res-=it->second*cnt[it->first^(low-1)];
					next[it->first>>1]+=it->second;
				}
				cnt=next;
			}
			return res>>1;
		}
};


int main() 
{
	Solution s;
	vector<int> nums={1,4,2,7};
	cout<<s.countPairs(nums,2,6)<<endl;
	nums.clear();nums={9,8,4,2,1};
	cout<<s.countPairs(nums,5,14)<<endl;
	return 0;
}
