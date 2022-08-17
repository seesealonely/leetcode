/*
   Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper and citations is sorted in an ascending order, return compute the researcher's h-index.

   According to the definition of h-index on Wikipedia: A scientist has an index h if h of their n papers have at least h citations each, and the other n − h papers have no more than h citations each.

   If there are several possible values for h, the maximum one is taken as the h-index.

   You must write an algorithm that runs in logarithmic time.



   Example 1:

Input: citations = [0,1,3,5,6]
Output: 3
Explanation: [0,1,3,5,6] means the researcher has 5 papers in total and each of them had received 0, 1, 3, 5, 6 citations respectively.
Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, their h-index is 3.

Example 2:

Input: citations = [1,2,100]
Output: 2



Constraints:

n == citations.length
1 <= n <= 105
0 <= citations[i] <= 1000
citations is sorted in ascending order.

*/


#include"head.h"
class Solution {
    public:
        int hIndex(vector<int>& citations) {
        if(citations.empty()) return 0;

        int l=0,r=citations.size()-1;
        while(l<r)
        {
            int mid=(l+r)>>1;
            if(citations.size()-mid<=citations[mid]) r=mid;
            else
                l=mid+1;
        }

        if(citations.size()-l<=citations[l]) 
            return citations.size()-l;

        return 0;
        }
};


int main() 
{
    Solution s;
    vector<int> v={0,1,3,5,6};
    cout<<s.hIndex(v)<<endl;
    v.clear();v={1,2,100};
    cout<<s.hIndex(v)<<endl;
    return 0;
}
