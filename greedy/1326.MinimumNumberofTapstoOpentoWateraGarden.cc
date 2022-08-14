/*
   There is a one-dimensional garden on the x-axis. The garden starts at the point 0 and ends at the point n. (i.e The length of the garden is n).

   There are n + 1 taps located at points [0, 1, ..., n] in the garden.

   Given an integer n and an integer array ranges of length n + 1 where ranges[i] (0-indexed) means the i-th tap can water the area [i - ranges[i], i + ranges[i]] if it was open.

   Return the minimum number of taps that should be open to water the whole garden, If the garden cannot be watered return -1.



   Example 1:

Input: n = 5, ranges = [3,4,1,1,0,0]
Output: 1
Explanation: The tap at point 0 can cover the interval [-3,3]
The tap at point 1 can cover the interval [-3,5]
The tap at point 2 can cover the interval [1,3]
The tap at point 3 can cover the interval [2,4]
The tap at point 4 can cover the interval [4,4]
The tap at point 5 can cover the interval [5,5]
Opening Only the second tap will water the whole garden [0,5]

Example 2:

Input: n = 3, ranges = [0,0,0,0]
Output: -1
Explanation: Even if you activate all the four taps you cannot water the whole garden.



Constraints:

1 <= n <= 104
ranges.length == n + 1
0 <= ranges[i] <= 100

*/


#include"head.h"
class Solution {
    public:
        int minTaps(int n, vector<int>& ranges) {
        vector<pair<int,int>> mx(n+1);
        for(int i=0;i<=n;i++)
            mx[i]={max(0,i-ranges[i]),min(n,i+ranges[i])};

        sort(mx.begin(),mx.end());

        int res=0;
        for(int i=0,end=0;i<=n&&end<n;)
        {
            int curEnd=0;
            while(i<=n&&mx[i].first<=end)
            {
                curEnd=max(curEnd,mx[i].second);
                i++;
            }

            if(curEnd==end)
                return -1;

            end=curEnd;
            res++;
        }

        return res;
        }
};


int main() 
{
    Solution s;
    vector<int> v={3,4,1,1,0,0};
    cout<<s.minTaps(5,v)<<endl;
    v.clear();v={0,0,0,0};
    cout<<s.minTaps(3,v)<<endl;
    v.clear();v={0,1,0,0};
    cout<<s.minTaps(3,v)<<endl;
    return 0;
}
