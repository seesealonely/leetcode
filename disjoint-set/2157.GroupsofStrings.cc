/*
   You are given a 0-indexed array of strings words. Each string consists of lowercase English letters only. No letter occurs more than once in any string of words.

   Two strings s1 and s2 are said to be connected if the set of letters of s2 can be obtained from the set of letters of s1 by any one of the following operations:

   Adding exactly one letter to the set of the letters of s1.
   Deleting exactly one letter from the set of the letters of s1.
   Replacing exactly one letter from the set of the letters of s1 with any letter, including itself.

   The array words can be divided into one or more non-intersecting groups. A string belongs to a group if any one of the following is true:

   It is connected to at least one other string of the group.
   It is the only string present in the group.

   Note that the strings in words should be grouped in such a manner that a string belonging to a group cannot be connected to a string present in any other group. It can be proved that such an arrangement is always unique.

   Return an array ans of size 2 where:

   ans[0] is the maximum number of groups words can be divided into, and
   ans[1] is the size of the largest group.

    

   Example 1:

Input: words = ["a","b","ab","cde"]
Output: [2,3]
Explanation:
- words[0] can be used to obtain words[1] (by replacing 'a' with 'b'), and words[2] (by adding 'b'). So words[0] is connected to words[1] and words[2].
- words[1] can be used to obtain words[0] (by replacing 'b' with 'a'), and words[2] (by adding 'a'). So words[1] is connected to words[0] and words[2].
- words[2] can be used to obtain words[0] (by deleting 'b'), and words[1] (by deleting 'a'). So words[2] is connected to words[0] and words[1].
- words[3] is not connected to any string in words.
Thus, words can be divided into 2 groups ["a","b","ab"] and ["cde"]. The size of the largest group is 3.  

Example 2:

Input: words = ["a","ab","abc"]
Output: [1,3]
Explanation:
- words[0] is connected to words[1].
- words[1] is connected to words[0] and words[2].
- words[2] is connected to words[1].
Since all strings are connected to each other, they should be grouped together.
Thus, the size of the largest group is 3.

 

Constraints:

1 <= words.length <= 2 * 104
1 <= words[i].length <= 26
words[i] consists of lowercase English letters only.
No letter occurs more than once in words[i].

*/

#define c11
#include"head.h"
class Solution {
    private:
        vector<int> p,sz;
        void init(int n)
        {
            p.resize(n+1);
            sz.resize(n+1);
            for(int i=0;i<=n;i++)
            {
                p[i]=i;
                sz[i]=1;
            }
        }
        int find(int x)
        {
            return x==p[x]?x:p[x]=find(p[x]);
        }
        void merge(int x,int y)
        {
            int px=find(x),py=find(y);
            if(px==py)
                return ;
            if(sz[px]<sz[py])
            {
                p[px]=py;
                sz[py]+=sz[px];
            }
            else
            {
                p[py]=px;
                sz[px]+=sz[py];
            }
        }
    public:
        vector<int> groupStrings(vector<string>& words) {
            const int n=words.size();
            init(n);

            unordered_map<int,int> h;
            for(int i=0;i<n;i++)
            {
                int key=0;
                for(int j=0;j<words[i].size();j++)
                    key+=1<<(words[i][j]-'a');

                if(h.find(key)==h.end()) h[key]=i;
                else
                    merge(h[key],i);
            }

            for(int i=0;i<n;i++)
            {
                int ith=0;
                for(int j=0;j<words[i].size();j++)
                    ith|=1<<(words[i][j]-'a');

                //add .say |
                for(int j=0;j<26;j++)
                {
                    if((ith>>j)&1)
                        continue;

                    int key=ith|(1<<j);
                    if(h.find(key)!=h.end())
                        merge(h[key],i);
                }

                //Oxr .say ^
                for(int j=0;j<26;j++)
                {
                    if(!((ith>>j)&1))
                        continue;

                    int next=ith^(1<<j);
                    for(int m=0;m<26;m++)
                    {
                        if((ith>>m)&1)
                            continue;

                        next|=1<<m;
                        if(h.find(next)!=h.end())
                            merge(h[next],i);

                        next^=1<<m;
                    }
                }
            }
            vector<int> res(2,0);
            for(int i=0;i<n;i++)
            {
                if(i!=find(i))
                    continue;

                res[0]++;
                res[1]=max(res[1],sz[i]);
            }
            return res;
        }
};


int main() 
{
    Solution s;
    vector<string> v={"a","b","ab","cde"};
    show(s.groupStrings(v));
    v.clear();v={"a","ab","abc"};
    show(s.groupStrings(v));
    return 0;
}
