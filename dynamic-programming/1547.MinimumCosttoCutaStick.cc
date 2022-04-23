/*
   Given a wooden stick of length n units. The stick is labelled from 0 to n. For example, a stick of length 6 is labelled as follows:

   Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.

   You should perform the cuts in order, you can change the order of the cuts as you wish.

   The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Please refer to the first example for a better explanation.

   Return the minimum total cost of the cuts.



   Example 1:

Input: n = 7, cuts = [1,3,4,5]
Output: 16
Explanation: Using cuts order = [1, 3, 4, 5] as in the input leads to the following scenario:

The first cut is done to a rod of length 7 so the cost is 7. The second cut is done to a rod of length 6 (i.e. the second part of the first cut), the third is done to a rod of length 4 and the last cut is to a rod of length 3. The total cost is 7 + 6 + 4 + 3 = 20.
Rearranging the cuts to be [3, 5, 1, 4] for example will lead to a scenario with total cost = 16 (as shown in the example photo 7 + 4 + 3 + 2 = 16).

Example 2:

Input: n = 9, cuts = [5,6,1,4,2]
Output: 22
Explanation: If you try the given cuts ordering the cost will be 25.
There are much ordering with total cost <= 25, for example, the order [4, 6, 5, 2, 1] has total cost = 22 which is the minimum possible.



Constraints:

2 <= n <= 106
1 <= cuts.length <= min(n - 1, 1G00)
1 <= cuts[i] <= n - 1
All the integers in cuts array are distinct.

*/


#include"head.h"
class Solution {
    public:
        int minCost(int n, vector<int>& cuts) {
            return minCost1(n,cuts);
         //   return minCost0(n,cuts);
        }
        /*
        int minCost0(int n, vector<int>& cuts) {
            sort(cuts.begin(),cuts.end());
            cuts.insert(cuts.begin(),0);
            cuts.push_back(n);
            vector<vector<int>> dp(cuts.size(),vector<int>(cuts.size(),INT_MAX));
            return dfs(dp,cuts,0,cuts.size()-1);
        }
        int dfs(vector<vector<int>> &dp,vector<int> &cuts,int l,int r)
        {
            if(dp[l][r]!=INT_MAX)
                return dp[l][r];
            if(l==r||l+1==r)
                dp[l][r]=0;
            for(int i=l+1;i<r;i++)
                dp[l][r]=min(dp[l][r],dfs(dp,cuts,l,i)+dfs(dp,cuts,i,r)+cuts[r]-cuts[l]);
            return dp[l][r];
        }
        */
        int minCost1(int n, vector<int>& cuts) {
            sort(cuts.begin(),cuts.end());
            cuts.insert(cuts.begin(),0);
            cuts.push_back(n);
            const int c=cuts.size();
            vector<vector<int>> dp(c,vector<int>(c,INT_MAX));
            for(int i=0;i+1<c;i++)
                dp[i][i+1]=0;

            for(int len=2;len<c;len++)
                for(int i=0;i+len<c;i++)
                {
                    int j=i+len;
                    for(int k=i+1;k<j;k++)
                        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+cuts[j]-cuts[i]);
                }

            return dp[0][c-1];
        }
};


int main() 
{
    Solution s;
    vector<int> v={1,3,4,5};
    cout<<s.minCost(7,v)<<endl;
    v.clear();v={5,6,1,4,2};
    cout<<s.minCost(9,v)<<endl;
    return 0;
}
