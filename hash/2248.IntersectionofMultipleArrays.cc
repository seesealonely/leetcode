/*
   Given a 2D integer array nums where nums[i] is a non-empty array of distinct positive integers, return the list of integers that are present in each array of nums sorted in ascending order.



   Example 1:

Input: nums = [[3,1,2,4,5],[1,2,3,4],[3,4,5,6]]
Output: [3,4]
Explanation:
The only integers present in each of nums[0] = [3,1,2,4,5], nums[1] = [1,2,3,4], and nums[2] = [3,4,5,6] are 3 and 4, so we return [3,4].

Example 2:

Input: nums = [[1,2,3],[4,5,6]]
Output: []
Explanation:
There does not exist any integer present both in nums[0] and nums[1], so we return an empty list [].



Constraints:

1 <= nums.length <= 1000
1 <= sum(nums[i].length) <= 1000
1 <= nums[i][j] <= 1000
All the values of nums[i] are unique.
*/

#define c11
#include"head.h"
class Solution {
    public:
        vector<int> intersection(vector<vector<int>>& nums) {
            unordered_set<int> pre(nums[0].begin(),nums[0].end());

            for(int i=1;i<nums.size();i++)
            {
                unordered_set<int> intersection;
                for(int j=0;j<nums[i].size();j++)
                    if(pre.count(nums[i][j]))
                        intersection.insert(nums[i][j]);
                pre=intersection;
            }

            vector<int> res;
            for(unordered_set<int>::iterator it=pre.begin();it!=pre.end();it++)
                res.push_back(*it);
            sort(res.begin(),res.end());

            return res;
        }
};


int main() 
{
    Solution s;
    vector<vector<int> > v={{3,1,2,4,5},{1,2,3,4},{3,4,5,6}};
    show(s.intersection(v));
    v.clear();v={{1,2,3},{4,5,6}};
    show(s.intersection(v));
    return 0;
}
