/*
   You are given an integer array nums and an array queries where queries[i] = [vali, indexi].

   For each query i, first, apply nums[indexi] = nums[indexi] + vali, then print the sum of the even values of nums.

   Return an integer array answer where answer[i] is the answer to the ith query.



   Example 1:

Input: nums = [1,2,3,4], queries = [[1,0],[-3,1],[-4,0],[2,3]]
Output: [8,6,2,4]
Explanation: At the beginning, the array is [1,2,3,4].
After adding 1 to nums[0], the array is [2,2,3,4], and the sum of even values is 2 + 2 + 4 = 8.
After adding -3 to nums[1], the array is [2,-1,3,4], and the sum of even values is 2 + 4 = 6.
After adding -4 to nums[0], the array is [-2,-1,3,4], and the sum of even values is -2 + 4 = 2.
After adding 2 to nums[3], the array is [-2,-1,3,6], and the sum of even values is -2 + 6 = 4.

Example 2:

Input: nums = [1], queries = [[4,0]]
Output: [0]



Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
1 <= queries.length <= 104
-104 <= vali <= 104
0 <= indexi < nums.length

*/


#include"head.h"
class Solution {
    public:
        vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size(),m=queries.size(),sum=0;
        for(int i=0;i<n;i++)
            if(nums[i]%2==0)
                sum+=nums[i];

        vector<int> res;
        for(int i=0;i<m;i++)
        {
            int val=queries[i][0],idx=queries[i][1];

            if(val%2==0)
            {
                if(nums[idx]%2==0)
                    sum+=val;
            }
            else
            {
                if(nums[idx]%2==0)
                    sum-=nums[idx];
                else
                    sum+=nums[idx]+val;
            }

            nums[idx]+=val;
            res.push_back(sum);
        }
        return res;
        }
};


int main() 
{
    Solution s;
    vector<int> n={1,2,3,4};
    vector<vector<int>> q={{1,0},{-3,1},{-4,0},{2,3}};
    show(s.sumEvenAfterQueries(n,q));
    n.clear();n={1};
    q.clear();q={{4,0}};
    show(s.sumEvenAfterQueries(n,q));
    return 0;
}
