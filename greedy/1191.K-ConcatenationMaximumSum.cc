/*
   Given an integer array arr and an integer k, modify the array by repeating it k times.

   For example, if arr = [1, 2] and k = 3 then the modified array will be [1, 2, 1, 2, 1, 2].

   Return the maximum sub-array sum in the modified array. Note that the length of the sub-array can be 0 and its sum in that case is 0.

   As the answer can be very large, return the answer modulo 109 + 7.



   Example 1:

Input: arr = [1,2], k = 3
Output: 9

Example 2:

Input: arr = [1,-2,1], k = 5
Output: 2

Example 3:

Input: arr = [-1,-2], k = 7
Output: 0



Constraints:

1 <= arr.length <= 105
1 <= k <= 105
-104 <= arr[i] <= 104

*/


#include"head.h"
class Solution {
    public:
        int kConcatenationMaxSum(vector<int>& arr, int k) {
            const int n=arr.size();
            typedef long long ll;
            vector<ll> sum(n+1,0),premin(n+1,0),premax(n+1,0);

            int mod=1e9+7;
            ll res=0;
            for(int i=1;i<=n;i++)
            {
                sum[i]=sum[i-1]+arr[i-1];
                premin[i]=min(premin[i-1],sum[i]);
                premax[i]=max(premax[i-1],sum[i]);
                res=max(res,sum[i]-premin[i]);
            }

            if(k>=2)
                res=max(res,max(sum[n]-premin[n]+premax[n],sum[n]-premin[n]+premax[n]+(k-2)*sum[n]));

            return res%mod;
        }
};


int main() 
{
    Solution s;
    vector<int> v={1,2};
    cout<<s.kConcatenationMaxSum(v,3)<<endl;
    v.clear();v={1,-2,1};
    cout<<s.kConcatenationMaxSum(v,5)<<endl;
    v.clear();v={-1,-2};
    cout<<s.kConcatenationMaxSum(v,7)<<endl;
    return 0;
}
