/*
   You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.

   You can swap the characters at any pair of indices in the given pairs any number of times.

   Return the lexicographically smallest string that s can be changed to after using the swaps.



   Example 1:

Input: s = "dcab", pairs = [[0,3],[1,2]]
Output: "bacd"
Explaination:
Swap s[0] and s[3], s = "bcad"
Swap s[1] and s[2], s = "bacd"

Example 2:

Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
Output: "abcd"
Explaination:
Swap s[0] and s[3], s = "bcad"
Swap s[0] and s[2], s = "acbd"
Swap s[1] and s[2], s = "abcd"

Example 3:

Input: s = "cba", pairs = [[0,1],[1,2]]
Output: "abc"
Explaination:
Swap s[0] and s[1], s = "bca"
Swap s[1] and s[2], s = "bac"
Swap s[0] and s[1], s = "abc"



Constraints:

1 <= s.length <= 10^5
0 <= pairs.length <= 10^5
0 <= pairs[i][0], pairs[i][1] < s.length
s only contains lower case English letters.

*/
#define c11
#include"head.h"
class Solution {
    public:
        string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        const int n=s.size(),m=pairs.size();
        p.resize(n);

        for(int i=0;i<n;i++)
                p[i]=i;
        for(int i=0;i<m;i++)
            u(pairs[i][0],pairs[i][1]);

        unordered_map<int,vector<int>> index;
        for(int i=0;i<n;i++)
            index[f(i)].push_back(i);

        string res(n,' ');
        for(unordered_map<int,vector<int>>::iterator it=index.begin();it!=index.end();it++)
        {
            string cur;
            for(int i=0;i<it->second.size();i++)
                cur+=s[it->second[i]];
            sort(cur.begin(),cur.end());
            for(int i=0;i<it->second.size();i++)
                res[it->second[i]]=cur[i];
        }
        return res;
        }
        vector<int> p;
        int f(int n)
        {
            if(p[n]==n) return n;
            return f(p[n]);
        }
        void u(int x,int y)
        {
            int a=f(x);
            int b=f(y);
            if(a>b)
                p[a]=b;
            else
                p[b]=a;
        }
};
int main() 
{
    Solution s;
    vector<vector<int> > v={{0,3},{1,2}};
    cout<<s.smallestStringWithSwaps("dcab",v)<<endl;
    v.push_back({0,2});
    cout<<s.smallestStringWithSwaps("dcab",v)<<endl;
    v.clear();v={{0,1},{1,2}};
    cout<<s.smallestStringWithSwaps("cba",v)<<endl;
    return 0;
}
