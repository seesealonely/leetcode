/*
   You are given a 0-indexed array of unique strings words.

   A palindrome pair is a pair of integers (i, j) such that:

   0 <= i, j < word.length,
   i != j, and
   words[i] + words[j] (the concatenation of the two strings) is a
   palindrome
   .

   Return an array of all the palindrome pairs of words.

    

   Example 1:

Input: words = ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]]
Explanation: The palindromes are ["abcddcba","dcbaabcd","slls","llssssll"]

Example 2:

Input: words = ["bat","tab","cat"]
Output: [[0,1],[1,0]]
Explanation: The palindromes are ["battab","tabbat"]

Example 3:

Input: words = ["a",""]
Output: [[0,1],[1,0]]
Explanation: The palindromes are ["a","a"]

 

Constraints:

1 <= words.length <= 5000
0 <= words[i].length <= 300
words[i] consists of lowercase English letters.

*/

#define c11
#include"head.h"
class Solution {
    public:
        vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string,int> h;
        const int n=words.size();

        for(int i=0;i<n;i++)
        {
            string key=words[i];
            reverse(key.begin(),key.end());
            h[key]=i;
        }

        vector<vector<int>> res;
        if(h.count(""))
            for(int i=0;i<n;i++)
                if(check(words[i])&&h[words[i]]!=h[""])
                    res.push_back({h[words[i]],h[""]}),res.push_back({h[""],h[words[i]]});

        for(int i=0;i<n;i++)
        {
            int m=words[i].size();
            for(int j=1;j<=m;j++)
            {
                string pre=words[i].substr(0,j),suf=words[i].substr(j);
                if(h.count(pre)&&check(suf)&&h[pre]!=i&&pre!="")
                    res.push_back({i,h[pre]});

                if(h.count(suf)&&check(pre)&&h[suf]!=i&&suf!="")
                    res.push_back({h[suf],i});
            }
        }

        return res;
        }
        bool check(string &s)
        {
            int n=s.size();
            for(int i=0,j=n-1;i<j;i++,j--)
            {
                if(s[i]!=s[j])
                    return false;
            }

            return true;
        }
};


int main() 
{
    Solution s;
    vector<string> v={"abcd","dcba","lls","s","sssll"};
    show(s.palindromePairs(v));
    cout<<"##############"<<endl;
    v.clear();v={"bat","tab","cat"};
    show(s.palindromePairs(v));
    cout<<"##############"<<endl;
    v.clear();v={"a",""};
    show(s.palindromePairs(v));
    cout<<"##############"<<endl;
    return 0;
}
