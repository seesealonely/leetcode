/*
   Given two positive integers left and right, find the two integers num1 and num2 such that:

   left <= nums1 < nums2 <= right .
   nums1 and nums2 are both prime numbers.
   nums2 - nums1 is the minimum amongst all other pairs satisfying the above conditions.

   Return the positive integer array ans = [nums1, nums2]. If there are multiple pairs satisfying these conditions, return the one with the minimum nums1 value or [-1, -1] if such numbers do not exist.

   A number greater than 1 is called prime if it is only divisible by 1 and itself.

    

   Example 1:

Input: left = 10, right = 19
Output: [11,13]
Explanation: The prime numbers between 10 and 19 are 11, 13, 17, and 19.
The closest gap between any pair is 2, which can be achieved by [11,13] or [17,19].
Since 11 is smaller than 17, we return the first pair.

Example 2:

Input: left = 4, right = 6
Output: [-1,-1]
Explanation: There exists only one prime number in the given range, so the conditions cannot be satisfied.

 

Constraints:

1 <= left <= right <= 106
*/


#include"head.h"
class Solution {
    private:
        vector<bool> vis;
        vector<int> pri;
    public:
        vector<int> closestPrimes(int left, int right) {
            getPrimer(right);
            vector<int> res(2,-1);
            int pre=-1,mn=INT_MAX;
            for(int i=0;i<pri.size();i++)
            {
                int cur=pri[i];
                if(pre>=left&&mn>cur-pre)
                {
                    mn=cur-pre;
                    res[0]=pre;
                    res[1]=cur;
                }
                pre=cur;
            }

            return res;
        }
        void getPrimer(int n)
        {
            vis.resize(n+1,false);
            for(int i=2;i<=n;i++)
            {
                if(!vis[i])
                    pri.push_back(i);
                for(int j=0;j<pri.size();j++)
                {
                    if(1LL*i*pri[j]>n)
                        break;

                    vis[i*pri[j]]=true;
                    if(i%pri[j]==0)
                        break;
                }
            }
        }
};


int main() 
{
    Solution s;
    show(s.closestPrimes(10,19));
    show(s.closestPrimes(4,6));
    return 0;
}
