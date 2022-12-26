/*
   You are given an array of positive integers price where price[i] denotes the price of the ith candy and a positive integer k.

   The store sells baskets of k distinct candies. The tastiness of a candy basket is the smallest absolute difference of the prices of any two candies in the basket.

   Return the maximum tastiness of a candy basket.

    

   Example 1:

Input: price = [13,5,1,8,21,2], k = 3
Output: 8
Explanation: Choose the candies with the prices [13,5,21].
The tastiness of the candy basket is: min(|13 - 5|, |13 - 21|, |5 - 21|) = min(8, 8, 16) = 8.
It can be proven that 8 is the maximum tastiness that can be achieved.

Example 2:

Input: price = [1,3,1], k = 2
Output: 2
Explanation: Choose the candies with the prices [1,3].
The tastiness of the candy basket is: min(|1 - 3|) = min(2) = 2.
It can be proven that 2 is the maximum tastiness that can be achieved.

Example 3:

Input: price = [7,7,7,7], k = 2
Output: 0
Explanation: Choosing any two distinct candies from the candies we have will result in a tastiness of 0.

 

Constraints:

2 <= k <= price.length <= 105
1 <= price[i] <= 109

*/


#include"head.h"
class Solution {
    public:
        int maximumTastiness(vector<int>& price, int k) {
            sort(price.begin(),price.end());

            int l=0,r=1e9;
                while(l<r)
                {
                    int m=(l+r+1)>>1;
                    if(check(m,price,k))
                        l=m;
                    else
                        r=m-1;
                }
            return l;
        }
        bool check(int target,const vector<int>&p,int k)
        {
            int cnt=1,n=p.size();
            for(int i=1,pre=0;i<n;i++)
            {
                if(p[i]-p[pre]>=target)
                {
                    pre=i;
                    cnt++;
                }
            }

            return cnt>=k;
        }
};


int main() 
{
    Solution s;
    vector<int> v={13,5,1,8,21,2};
    cout<<s.maximumTastiness(v,3)<<endl;
    v.clear();v={1,3,1};
    cout<<s.maximumTastiness(v,2)<<endl;
    v.clear();v={7,7,7,7};
    cout<<s.maximumTastiness(v,2)<<endl;
    return 0;
}
