/*
   Given an integer array nums, return the most frequent even element.

   If there is a tie, return the smallest one. If there is no such element, return -1.



   Example 1:

Input: nums = [0,1,2,2,4,4,1]
Output: 2
Explanation:
The even elements are 0, 2, and 4. Of these, 2 and 4 appear the most.
We return the smallest one, which is 2.

Example 2:

Input: nums = [4,4,4,9,2,4]
Output: 4
Explanation: 4 is the even element appears the most.

Example 3:

Input: nums = [29,47,21,41,13,37,25,7]
Output: -1
Explanation: There is no even element.



Constraints:

1 <= nums.length <= 2000
0 <= nums[i] <= 105

*/

#define c11
#include"head.h"
class Solution {
    public:
        int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int> h;

        for(int i=0;i<nums.size();i++)
            if(nums[i]%2==0)
                h[nums[i]]++;

        pair<int,int> res;res.first=INT_MAX,res.second=0;
        for(unordered_map<int,int>::iterator it=h.begin();it!=h.end();it++)
        {
            if(it->second==res.second)
                res.first=min(res.first,it->first),res.second=it->second;
            else if(it->second>res.second)
                res.first=it->first,res.second=it->second;
        }

        return res.second==0?-1:res.first;
        }
};


int main() 
{
    Solution s;
    vector<int> v={0,1,2,2,4,4,1};
    cout<<s.mostFrequentEven(v)<<endl;
    v.clear();v={4,4,4,9,2,4};
    cout<<s.mostFrequentEven(v)<<endl;
    v.clear();v={29,47,21,41,13,37,25,7};
    cout<<s.mostFrequentEven(v)<<endl;
    return 0;
}
