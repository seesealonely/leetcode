/*
   You have two fruit baskets containing n fruits each. You are given two 0-indexed integer arrays basket1 and basket2 representing the cost of fruit in each basket. You want to make both baskets equal. To do so, you can use the following operation as many times as you want:

   Chose two indices i and j, and swap the ith fruit of basket1 with the jth fruit of basket2.
   The cost of the swap is min(basket1[i],basket2[j]).

   Two baskets are considered equal if sorting them according to the fruit cost makes them exactly the same baskets.

   Return the minimum cost to make both the baskets equal or -1 if impossible.



   Example 1:

Input: basket1 = [4,2,2,2], basket2 = [1,4,1,2]
Output: 1
Explanation: Swap index 1 of basket1 with index 0 of basket2, which has cost 1. Now basket1 = [4,1,2,2] and basket2 = [2,4,1,2]. Rearranging both the arrays makes them equal.

Example 2:

Input: basket1 = [2,3,4,1], basket2 = [3,2,5,1]
Output: -1
Explanation: It can be shown that it is impossible to make both the baskets equal.



Constraints:

basket1.length == bakste2.length
1 <= basket1.length <= 105
1 <= basket1[i],basket2[i] <= 109

*/

#define c11
#include"head.h"
class Solution {
    public:
        long long minCost(vector<int>& basket1, vector<int>& basket2) {
        const int n=basket1.size();
        unordered_map<int,int> cnt;
        for(int i=0;i<n;i++)
        {
            ++cnt[basket1[i]];
            --cnt[basket2[i]];
        }

        int mn=INT_MAX;
        vector<int> a;
        for(unordered_map<int,int>::iterator it=cnt.begin();it!=cnt.end();it++)
        {
            if(it->second%2==1)
                return -1;

            mn=min(mn,it->first);
            for(int i=abs(it->second)/2;i>0;i--)
                a.push_back(it->first);
        }
        long long res=0;
        sort(a.begin(),a.end());
        for(int i=0;i<a.size()/2;i++)
            res+=min(a[i],mn*2);
        return res;
        }
};


int main() 
{
    Solution s;
    vector<int> v1={4,2,2,2},v2={1,4,1,2};
    cout<<s.minCost(v1,v2)<<endl;
    v1.clear();v1={2,3,4,1};
    v2.clear();v2={3,2,5,1};
    cout<<s.minCost(v1,v2)<<endl;
    return 0;
}
