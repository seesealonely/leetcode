/*
   You are given an integer array arr.

   We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.

   Return the largest number of chunks we can make to sort the array.



   Example 1:

Input: arr = [5,4,3,2,1]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [5, 4], [3, 2, 1] will result in [4, 5, 1, 2, 3], which isn't sorted.

Example 2:

Input: arr = [2,1,3,4,4]
Output: 4
Explanation:
We can split into two chunks, such as [2, 1], [3, 4, 4].
However, splitting into [2, 1], [3], [4], [4] is the highest number of chunks possible.



Constraints:

1 <= arr.length <= 2000
0 <= arr[i] <= 108

*/


#include"head.h"
class Solution {
    public:
        int maxChunksToSorted(vector<int>& arr) {
        return greedy(arr);
        }
        int mstack(vector<int> &arr)
        {
            stack<int> st;
            const int n=arr.size();
            for(int i=0;i<n;i++)
            {
                if(st.empty()||arr[st.top()]<=arr[i])
                    st.push(i);
                else
                {
                    int mx=st.top();
                    while(!st.empty()&&arr[st.top()]>arr[i])
                        st.pop();
                    st.push(mx);
                }
            }
            return st.size();
        }
};


int main() 
{
    Solution s;
    vector<int> v={5,4,3,2,1};
    cout<<s.maxChunksToSorted(v)<<endl;
    v.clear();v={2,1,3,4,4};
    cout<<s.maxChunksToSorted(v)<<endl;
    return 0;
}
