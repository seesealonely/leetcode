/*
   Given an array of positive integers nums, return the number of distinct prime factors in the product of the elements of nums.

   Note that:

   A number greater than 1 is called prime if it is divisible by only 1 and itself.
   An integer val1 is a factor of another integer val2 if val2 / val1 is an integer.

    

   Example 1:

Input: nums = [2,4,3,7,10,6]
Output: 4
Explanation:
The product of all the elements in nums is: 2 * 4 * 3 * 7 * 10 * 6 = 10080 = 25 * 32 * 5 * 7.
There are 4 distinct prime factors so we return 4.

Example 2:

Input: nums = [2,4,8,16]
Output: 1
Explanation:
The product of all the elements in nums is: 2 * 4 * 8 * 16 = 1024 = 210.
There is 1 distinct prime factor so we return 1.

 

Constraints:

1 <= nums.length <= 104
2 <= nums[i] <= 1000

*/

#define c11
#include"head.h"
class Solution {
    public:
        int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> s;
        const int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int cur=nums[i];
            for(int j=2;j<=cur;j++)
            {
                if(cur%j==0)
                    s.insert(j);
                while(cur%j==0)
                    cur/=j;
            }
            if(cur>1)
                s.insert(cur);
        }

        return s.size();
        }
};


int main() 
{
    Solution s;
    vector<int> v={2,4,3,7,10,6};
    cout<<s.distinctPrimeFactors(v)<<endl;
    v.clear();v={2,4,8,16};
    cout<<s.distinctPrimeFactors(v)<<endl;
    return 0;
}
