/*
   You are given a 0-indexed array nums consisting of n positive integers.

   The array nums is called alternating if:

   nums[i - 2] == nums[i], where 2 <= i <= n - 1.
   nums[i - 1] != nums[i], where 1 <= i <= n - 1.

   In one operation, you can choose an index i and change nums[i] into any positive integer.

   Return the minimum number of operations required to make the array alternating.



   Example 1:

Input: nums = [3,1,3,2,4,3]
Output: 3
Explanation:
One way to make the array alternating is by converting it to [3,1,3,1,3,1].
The number of operations required in this case is 3.
It can be proven that it is not possible to make the array alternating in less than 3 operations.

Example 2:

Input: nums = [1,2,2,2,2]
Output: 2
Explanation:
One way to make the array alternating is by converting it to [1,2,1,2,1].
The number of operations required in this case is 2.
Note that the array cannot be converted to [2,2,2,2,2] because in this case nums[0] == nums[1] which violates the conditions of an alternating array.



Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 105

*/

#define c11
#include"head.h"
class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            unordered_map<int,int> oh,eh;
            const int n=nums.size();
            for(int i=0;i<n;i++)
                if(i&1)
                    oh[nums[i]]++;
                else
                    eh[nums[i]]++;
            int maxoi=max_element(oh);
            int maxei=max_element(eh);
            //           int maxoi=*max_element(oh.begin(),oh.end());
            //          int maxei=*max_element(eh.begin(),eh.end());
            if(maxoi!=maxei)
                return n-oh[maxoi]-eh[maxei];
            else
            {
                int mx1=oh[maxoi],mx2=eh[maxei];
                oh[maxoi]=0;
                mx2+=oh[max_element(oh)];
                eh[maxei]=0;
                mx1+=eh[max_element(eh)];
                return n-max(mx1,mx2);
            }
        }
           int max_element(unordered_map<int,int> &h)
           {
           int mval=0,index=0;
           for(unordered_map<int,int>::iterator it=h.begin();it!=h.end();it++)
           if(it->second>mval)
           mval=max(it->second,mval),index=it->first;
           return index;

           }
};


int main() 
{
    Solution s;
    vector<int> v={3,1,3,2,4,3};
    cout<<s.minimumOperations(v)<<endl;
    v.clear();v={1,2,2,2,2};
    cout<<s.minimumOperations(v)<<endl;
    v.clear();v={69,45,24,74,63,43,15,91,40,15,74,37,51,5,59,36,62,54,41,39,87,29,96,17,61,39,80,55,67,3,58,44,53,92,94,49,45,61,82,9,64,93,34,13,61,44,66,45,7,29,58,54,14,68,84,13,11,16,80,28,61,99,51,100,89,58,42,32,42,37,71,12,41,62,29,78,4,1,17,13,46,26,75};
    cout<<s.minimumOperations(v)<<endl;
    return 0;
}
