/*
   You are given a rectangular cake of size h x w and two arrays of integers horizontalCuts and verticalCuts where:

   horizontalCuts[i] is the distance from the top of the rectangular cake to the ith horizontal cut and similarly, and
   verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.

   Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays horizontalCuts and verticalCuts. Since the answer can be a large number, return this modulo 109 + 7.



   Example 1:

Input: h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
Output: 4
Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green piece of cake has the maximum area.

Example 2:

Input: h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]
Output: 6
Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green and yellow pieces of cake have the maximum area.

Example 3:

Input: h = 5, w = 4, horizontalCuts = [3], verticalCuts = [3]
Output: 9



Constraints:

2 <= h, w <= 109
1 <= horizontalCuts.length <= min(h - 1, 105)
1 <= verticalCuts.length <= min(w - 1, 105)
1 <= horizontalCuts[i] < h
1 <= verticalCuts[i] < w
All the elements in horizontalCuts are distinct.
All the elements in verticalCuts are distinct.

*/


#include"head.h"
class Solution {
    public:
        int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        const int ho=horizontalCuts.size(),v=verticalCuts.size(),mod=1e9+7;

        int maxh=h-horizontalCuts.back(),maxv=w-verticalCuts.back();
        for(int i=0,pre=0;i<ho;i++)
            maxh=max(maxh,horizontalCuts[i]-pre),pre=horizontalCuts[i];

        for(int i=0,pre=0;i<v;i++)
            maxv=max(maxv,verticalCuts[i]-pre),pre=verticalCuts[i];
         
        return (long long)maxh*maxv%mod;
        }
};


int main() 
{
    Solution s;
    vector<int> h={1,2,4},v={1,3};
    cout<<s.maxArea(5,4,h,v)<<endl;
    h.clear();h={3,1};
    v.clear();v={1};
    cout<<s.maxArea(5,4,h,v)<<endl;
    h.clear();h={3};
    v.clear();v={3};
    cout<<s.maxArea(5,4,h,v)<<endl;
    return 0;
}
