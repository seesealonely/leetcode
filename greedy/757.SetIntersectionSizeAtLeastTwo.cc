/*
   You are given a 2D integer array intervals where intervals[i] = [starti, endi] represents all the integers from starti to endi inclusively.

   A containing set is an array nums where each interval from intervals has at least two integers in nums.

   For example, if intervals = [[1,3], [3,7], [8,9]], then [1,2,4,7,8,9] and [2,3,4,8,9] are containing sets.

   Return the minimum possible size of a containing set.



   Example 1:

Input: intervals = [[1,3],[3,7],[8,9]]
Output: 5
Explanation: let nums = [2, 3, 4, 8, 9].
It can be shown that there cannot be any containing array of size 4.

Example 2:

Input: intervals = [[1,3],[1,4],[2,5],[3,5]]
Output: 3
Explanation: let nums = [2, 3, 4].
It can be shown that there cannot be any containing array of size 2.

Example 3:

Input: intervals = [[1,2],[2,3],[2,4],[4,5]]
Output: 5
Explanation: let nums = [1, 2, 3, 4, 5].
It can be shown that there cannot be any containing array of size 4.



Constraints:

1 <= intervals.length <= 3000
intervals[i].length == 2
0 <= starti < endi <= 108

*/


#include"head.h"
class Solution {
    public:
        int intersectionSizeTwo(vector<vector<int>>& intervals) {
        const int n=intervals.size();

        sort(intervals.begin(),intervals.end(),cmp);
        int a=-1,b=-1,res=0;
        for(int i=0;i<n;i++)
        {
            int x=intervals[i][0],y=intervals[i][1];
            if(x>b)
            {
                a=y-1;
                b=y;
                res+=2;
            }
            else if(x>a)
            {
                a=b;
                b=y;
                res++;
            }
        }

        return res;
        }
        static bool cmp(vector<int> &a,vector<int> &b)
        {
            return a[1]==b[1]?a[0]>b[0]:a[1]<b[1];
        }
};


int main() 
{
    Solution s;
    vector<vector<int>> v={{1,3},{1,4},{2,5},{3,5}};
    cout<<s.intersectionSizeTwo(v)<<endl;
    v.clear();v={{1,2},{2,3},{2,4},{4,5}};
    cout<<s.intersectionSizeTwo(v)<<endl;
    return 0;
}
