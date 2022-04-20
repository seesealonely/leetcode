/*
   Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

   For example, given nums = [-2, 0, 1, 3], and target = 2.

   Return 2. Because there are two triplets which sums are less than 2:

   [-2, 0, 1]
   [-2, 0, 3]

   Follow up:

   Could you solve it in O(n^2) runtime?

*/


#include"head.h"
class Solution {
    public:
        int threeSumSmaller(vector<int>& nums, int target) {
            if(nums.size()<3)
                return 0;
            int res=0,n=nums.size();
            sort(nums.begin(),nums.end());
            for(int i=0;i<n;i++)
            {
                int l=i+1,r=n-1;
                while(l<r)
                {
                    if(nums[i]+nums[l]+nums[r]<target)
                        res+=r-l++;
                    else
                        r--;
                }
            }
            return res;
        }
};


int main() 
{
    Solution s;
    vector<int> v={-2,0,1,3};
    cout<<s.threeSumSmaller(v,2)<<endl;
    return 0;
}
