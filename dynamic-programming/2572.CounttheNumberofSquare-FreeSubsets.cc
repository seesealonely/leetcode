/*
   You are given a positive integer 0-indexed array nums.

   A subset of the array nums is square-free if the product of its elements is a square-free integer.

   A square-free integer is an integer that is divisible by no square number other than 1.

   Return the number of square-free non-empty subsets of the array nums. Since the answer may be too large, return it modulo 109 + 7.

   A non-empty subset of nums is an array that can be obtained by deleting some (possibly none but not all) elements from nums. Two subsets are different if and only if the chosen indices to delete are different.



   Example 1:

Input: nums = [3,4,4,5]
Output: 3
Explanation: There are 3 square-free subsets in this example:
- The subset consisting of the 0th element [3]. The product of its elements is 3, which is a square-free integer.
- The subset consisting of the 3rd element [5]. The product of its elements is 5, which is a square-free integer.
- The subset consisting of 0th and 3rd elements [3,5]. The product of its elements is 15, which is a square-free integer.
It can be proven that there are no more than 3 square-free subsets in the given array.

Example 2:

Input: nums = [1]
Output: 1
Explanation: There is 1 square-free subset in this example:
- The subset consisting of the 0th element [1]. The product of its elements is 1, which is a square-free integer.
It can be proven that there is no more than 1 square-free subset in the given array.



Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 30

*/


#include"head.h"
class Solution {
    public:
        int squareFreeSubsets(vector<int>& nums) {
        const int n=nums.size(),N=10,mod=1e9+7;
        vector<int> s={2,3,5,7,11,13,17,19,23,29};
        vector<int> dp((1<<N),0);

        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            int x=nums[i-1],key=0;
            bool find=false;

            for(int j=0;j<N;j++)
            {
                if(x%(s[j]*s[j])==0)
                {
                    find=true;
                    break;
                }

                if(x%s[j]==0)
                key|=1<<j;
            }

            if(find) continue;
            for(int j=(1<<N)-1;j>=0;j--)
                if((j&key)==key)
                    dp[j]=(dp[j]+dp[j^key])%mod;
        }

        int res=0;
        for(int j=0;j<(1<<N);j++)
            res=(res+dp[j])%mod;

        return (res-1+mod)%mod;
        }
};


int main() 
{
    Solution s;
    vector<int> v={3,4,4,5};
    cout<<s.squareFreeSubsets(v)<<endl;
    v.clear();v={1};
    cout<<s.squareFreeSubsets(v)<<endl;
    v.clear();v={26,6,4,27,6,18};
    cout<<s.squareFreeSubsets(v)<<endl;
    return 0;
}
