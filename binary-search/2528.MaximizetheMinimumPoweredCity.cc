/*
   You are given a 0-indexed integer array stations of length n, where stations[i] represents the number of power stations in the ith city.

   Each power station can provide power to every city in a fixed range. In other words, if the range is denoted by r, then a power station at city i can provide power to all cities j such that |i - j| <= r and 0 <= i, j <= n - 1.

   Note that |x| denotes absolute value. For example, |7 - 5| = 2 and |3 - 10| = 7.

   The power of a city is the total number of power stations it is being provided power from.

   The government has sanctioned building k more power stations, each of which can be built in any city, and have the same range as the pre-existing ones.

   Given the two integers r and k, return the maximum possible minimum power of a city, if the additional power stations are built optimally.

   Note that you can build the k power stations in multiple cities.

    

   Example 1:

Input: stations = [1,2,4,5,0], r = 1, k = 2
Output: 5
Explanation:
One of the optimal ways is to install both the power stations at city 1.
So stations will become [1,4,4,5,0].
- City 0 is provided by 1 + 4 = 5 power stations.
- City 1 is provided by 1 + 4 + 4 = 9 power stations.
- City 2 is provided by 4 + 4 + 5 = 13 power stations.
- City 3 is provided by 5 + 4 = 9 power stations.
- City 4 is provided by 5 + 0 = 5 power stations.
So the minimum power of a city is 5.
Since it is not possible to obtain a larger power, we return 5.

Example 2:

Input: stations = [4,4,4,4], r = 0, k = 3
Output: 4
Explanation:
It can be proved that we cannot make the minimum power of a city greater than 4.

 

Constraints:

n == stations.length
1 <= n <= 105
0 <= stations[i] <= 105
0 <= r <= n - 1
0 <= k <= 109

*/


#include"head.h"
class Solution {
    public:
        typedef long long ll;
        long long maxPower(vector<int>& stations, int r, int k) {
        ll l=0,ri=1e16;
        vector<ll> s;
        for(int i=0;i<stations.size();i++)
            s.push_back(stations[i]);
        while(l<ri)
        {
            ll m=(l+ri+1)>>1;
            if(check(s,m,r,k))
                l=m;
            else
                ri=m-1;
        }
        return l;
        }
        bool check(vector<ll> s,ll m,int ra,int k)
        {
            const int n=s.size();
            int l=0,r=ra;

            ll sum=0LL;
            for(int i=0;i<r;i++)
                sum+=s[i];

            for(int i=0;i<n;i++)
            {
                if(r<n)
                    sum+=s[r];

                if(m>sum)
                {
                    if(sum+k-m<0)
                        return false;

                    k-=m-sum;

                    if(r<n)
                        s[r]+=m-sum;

                    sum=m;
                }

                if(i-l==ra)
                    sum-=s[l++];

                r++;
            }
            return true;
        }
};


int main() 
{
    Solution s;
    vector<int> v={1,2,4,5,0};
    cout<<s.maxPower(v,1,2)<<endl;
    v.clear();v={4,4,4,4};
    cout<<s.maxPower(v,0,3)<<endl;
    return 0;
}
