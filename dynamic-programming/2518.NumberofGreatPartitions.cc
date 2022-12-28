/*
   You are given an array nums consisting of positive integers and an integer k.

   Partition the array into two ordered groups such that each element is in exactly one group. A partition is called great if the sum of elements of each group is greater than or equal to k.

   Return the number of distinct great partitions. Since the answer may be too large, return it modulo 109 + 7.

   Two partitions are considered distinct if some element nums[i] is in different groups in the two partitions.

    

   Example 1:

Input: nums = [1,2,3,4], k = 4
Output: 6
Explanation: The great partitions are: ([1,2,3], [4]), ([1,3], [2,4]), ([1,4], [2,3]), ([2,3], [1,4]), ([2,4], [1,3]) and ([4], [1,2,3]).

Example 2:

Input: nums = [3,3,3], k = 4
Output: 0
Explanation: There are no great partitions for this array.

Example 3:

Input: nums = [6,6], k = 2
Output: 2
Explanation: We can either put nums[0] in the first partition or in the second partition.
The great partitions will be ([6], [6]) and ([6], [6]).

 

Constraints:

1 <= nums.length, k <= 1000
1 <= nums[i] <= 109

*/


#include"head.h"
class Solution {
    public:
        int countPartitions(vector<int>& nums, int k) {
            const int n=nums.size();
            vector<int> dp(k,0);
            dp[0]=1;

            long long sum=0,res=1;
            const int mod=1e9+7;
            for(int i=0;i<n;i++)
            {
                res=(2*res)%mod;
                sum+=nums[i];
                for(int j=k-1;j>=nums[i];j--)
                    dp[j]=((long long)dp[j]+dp[j-nums[i]])%mod;
            }

            if(sum<2*k)
                return 0;
            dp[0]=(long long)dp[0]*2%mod;
            for(int i=1;i<k;i++)
                dp[i]=((long long)dp[i]*2+dp[i-1])%mod;

            return (res-dp[k-1]+mod)%mod;
        }
};


int main() 
{
    Solution s;
    vector<int> v={1,2,3,4};
    cout<<s.countPartitions(v,4)<<endl;
    v.clear();v={3,3,3};
    cout<<s.countPartitions(v,4)<<endl;
    v.clear();v={6,6};
    cout<<s.countPartitions(v,2)<<endl;
    return 0;
}
