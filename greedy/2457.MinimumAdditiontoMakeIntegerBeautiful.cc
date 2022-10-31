/*
   You are given two positive integers n and target.

   An integer is considered beautiful if the sum of its digits is less than or equal to target.

   Return the minimum non-negative integer x such that n + x is beautiful. The input will be generated such that it is always possible to make n beautiful.



   Example 1:

Input: n = 16, target = 6
Output: 4
Explanation: Initially n is 16 and its digit sum is 1 + 6 = 7. After adding 4, n becomes 20 and digit sum becomes 2 + 0 = 2. It can be shown that we can not make n beautiful with adding non-negative integer less than 4.

Example 2:

Input: n = 467, target = 6
Output: 33
Explanation: Initially n is 467 and its digit sum is 4 + 6 + 7 = 17. After adding 33, n becomes 500 and digit sum becomes 5 + 0 + 0 = 5. It can be shown that we can not make n beautiful with adding non-negative integer less than 33.

Example 3:

Input: n = 1, target = 1
Output: 0
Explanation: Initially n is 1 and its digit sum is 1, which is already smaller than or equal to target.



Constraints:

1 <= n <= 1012
1 <= target <= 150
The input will be generated such that it is always possible to make n beautiful.

*/


#include"head.h"
class Solution {
    public:
        long long makeIntegerBeautiful(long long n, int target) {
        long long  sum=0,nn=n;
        vector<int> mod;
        while(nn)
        {
            sum+=nn%10;
            mod.push_back(nn%10);
            nn/=10;
        }

        if(sum<=target)
            return 0;

        mod.push_back(0);
        for(int i=0;i<mod.size()-1;i++)
        {
            if(mod[i]==0)
                continue;
            sum=sum-mod[i]+1;

            mod[i]=0,mod[i+1]++;

            if(mod[i+1]==10)
                continue;

            if(sum<=target)
                break;
        }
        long long  res=0;
        for(int i=mod.size()-1;i>=0;i--)
            res=res*10+mod[i];

        return res-n;
        }
};


int main() 
{
    Solution s;
    cout<<s.makeIntegerBeautiful(16,6)<<endl;
    cout<<s.makeIntegerBeautiful(467,6)<<endl;
    cout<<s.makeIntegerBeautiful(1,1)<<endl;
    cout<<s.makeIntegerBeautiful(8,2)<<endl;
    return 0;
}
