/*
   You have a pointer at index 0 in an array of size arrLen. At each step, you can move 1 position to the left, 1 position to the right in the array, or stay in the same place (The pointer should not be placed outside the array at any time).

   Given two integers steps and arrLen, return the number of ways such that your pointer still at index 0 after exactly steps steps. Since the answer may be too large, return it modulo 109 + 7.



   Example 1:

Input: steps = 3, arrLen = 2
Output: 4
Explanation: There are 4 differents ways to stay at index 0 after 3 steps.
Right, Left, Stay
Stay, Right, Left
Right, Stay, Left
Stay, Stay, Stay

Example 2:

Input: steps = 2, arrLen = 4
Output: 2
Explanation: There are 2 differents ways to stay at index 0 after 2 steps
Right, Left
Stay, Stay

Example 3:

Input: steps = 4, arrLen = 2
Output: 8



Constraints:

1 <= steps <= 500
1 <= arrLen <= 106

*/


#include"head.h"
class Solution {
    public:
        int numWays(int steps, int arrLen) {
        if(arrLen==1)
             return 1;

        int n=min(steps+1,arrLen),mod=1e9+7;
        vector<int>  pre(n,0),cur(n,0);

        pre[0]=1;
        for(int i=1;i<=steps;i++)
        {
            for(int j=0;j<arrLen;j++)
            {
                cur[j]=pre[j];
                if(j>0)
                cur[j]=(cur[j]+pre[j-1])%mod;
                if(j+1<n)
                cur[j]=(cur[j]+pre[j+1])%mod;
            }
            pre=cur;
        }
        return cur[0];
        }
};


int main() 
{
    Solution s;
    cout<<s.numWays(3,2)<<endl;
    cout<<s.numWays(2,4)<<endl;
    cout<<s.numWays(4,2)<<endl;
    return 0;
}
