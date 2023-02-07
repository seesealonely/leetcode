/*
   You are given a 0-indexed array of strings words and a 2D array of integers queries.

   Each query queries[i] = [li, ri] asks us to find the number of strings present in the range li to ri (both inclusive) of words that start and end with a vowel.

   Return an array ans of size queries.length, where ans[i] is the answer to the ith query.

   Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.



   Example 1:

Input: words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]]
Output: [2,3,0]
Explanation: The strings starting and ending with a vowel are "aba", "ece", "aa" and "e".
The answer to the query [0,2] is 2 (strings "aba" and "ece").
to query [1,4] is 3 (strings "ece", "aa", "e").
to query [1,1] is 0.
We return [2,3,0].

Example 2:

Input: words = ["a","e","i"], queries = [[0,2],[0,1],[2,2]]
Output: [3,2,1]
Explanation: Every string satisfies the conditions, so we return [3,2,1].



Constraints:

1 <= words.length <= 105
1 <= words[i].length <= 40
words[i] consists only of lowercase English letters.
sum(words[i].length) <= 3 * 105
1 <= queries.length <= 105
0 <= li <= ri < words.length

*/

#define c11
#include"head.h"
class Solution {
    public:
        vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
            const int m=words.size(),n=queries.size();
            unordered_set<char> s({'a','e','i','o','u'});
            vector<int> cnt(m,0);
            for(int i=0;i<m;i++)
                if(s.count(words[i][0])&&s.count(words[i].back()))
                    cnt[i]++;

            vector<int> pre(m+1,0);
            for(int i=0;i<m;i++)
                pre[i+1]=pre[i]+cnt[i];

            vector<int> res;
            for(int i=0;i<n;i++)
                res.push_back(pre[queries[i][1]+1]-pre[queries[i][0]]);

            return res;
        }
};


int main() 
{
    Solution s;
    vector<string> w={"aba","bcb","ece","aa","e"};
    vector<vector<int>> q={{0,2},{1,4},{1,1}};
    show(s.vowelStrings(w,q));
    w.clear();w={"a","e","i"};
    q.clear();q={{0,2},{0,1},{2,2}};
    show(s.vowelStrings(w,q));
    return 0;
}
