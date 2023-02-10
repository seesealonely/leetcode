/*
   You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.

   For each index i, names[i] and heights[i] denote the name and height of the ith person.

   Return names sorted in descending order by the people's heights.



   Example 1:

Input: names = ["Mary","John","Emma"], heights = [180,165,170]
Output: ["Mary","Emma","John"]
Explanation: Mary is the tallest, followed by Emma and John.

Example 2:

Input: names = ["Alice","Bob","Bob"], heights = [155,185,150]
Output: ["Bob","Alice","Bob"]
Explanation: The first Bob is the tallest, followed by Alice and the second Bob.



Constraints:

n == names.length == heights.length
1 <= n <= 103
1 <= names[i].length <= 20
1 <= heights[i] <= 105
names[i] consists of lower and upper case English letters.
All the values of heights are distinct.

*/


#include"head.h"
class Solution {
    public:
        vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
            const int n=names.size();
            vector<pair<string,int>> pairs;
            for(int i=0;i<n;i++)
                pairs.push_back({names[i],heights[i]});

            sort(pairs.begin(),pairs.end(),check);

            vector<string> res;
            for(int i=0;i<n;i++)
                res.push_back(pairs[i].first);

            return res;
        }
        static bool check(pair<string,int> &a,pair<string,int>&b)
        {
            return a.second>b.second;

        }
};


int main() 
{
    Solution s;
    vector<string> vs={"Mary","John","Emma"};
    vector<int> v={180,165,170};
    show(s.sortPeople(vs,v));
    vs.clear();vs={"Alice","Bob","Bob"};
    v.clear();v={155,185,150};
    show(s.sortPeople(vs,v));
    return 0;
}
