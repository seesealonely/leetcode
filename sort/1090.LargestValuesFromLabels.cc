/*
   There is a set of n items. You are given two integer arrays values and labels where the value and the label of the ith element are values[i] and labels[i] respectively. You are also given two integers numWanted and useLimit.

   Choose a subset s of the n elements such that:

   The size of the subset s is less than or equal to numWanted.
   There are at most useLimit items with the same label in s.

   The score of a subset is the sum of the values in the subset.

   Return the maximum score of a subset s.



   Example 1:

Input: values = [5,4,3,2,1], labels = [1,1,2,2,3], numWanted = 3, useLimit = 1
Output: 9
Explanation: The subset chosen is the first, third, and fifth items.

Example 2:

Input: values = [5,4,3,2,1], labels = [1,3,3,3,2], numWanted = 3, useLimit = 2
Output: 12
Explanation: The subset chosen is the first, second, and third items.

Example 3:

Input: values = [9,8,8,7,6], labels = [0,0,0,1,1], numWanted = 3, useLimit = 1
Output: 16
Explanation: The subset chosen is the first and fourth items.



Constraints:

n == values.length == labels.length
1 <= n <= 2 * 104
0 <= values[i], labels[i] <= 2 * 104
1 <= numWanted, useLimit <= n

*/

#define c11
#include"head.h"
class Solution {
    public:
        int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        const int n=values.size();
        vector<pair<int,int>> num;
        for(int i=0;i<n;i++)
        num.push_back({values[i],labels[i]});

        sort(num.begin(),num.end());
        reverse(num.begin(),num.end());
            
        unordered_map<int,int> cnt;
        int res=0;
        for(int i=0,j=0;i<n;i++)
        {
                if(cnt[num[i].second]++<useLimit)
                {
                    res+=num[i].first;
                    if(++j==numWanted)
                        break;
                }
        }
        
        return res;
        }
};


int main() 
{
    Solution s;
    vector<int> v={5,4,3,2,1},l={1,1,2,2,3};
    cout<<s.largestValsFromLabels(v,l,3,1)<<endl;
    l.clear();l={1,3,3,3,2};
    cout<<s.largestValsFromLabels(v,l,3,2)<<endl;
    v.clear();v={9,8,8,7,6};
    l.clear();l={0,0,0,1,1};
    cout<<s.largestValsFromLabels(v,l,3,1)<<endl;
    return 0;
}
