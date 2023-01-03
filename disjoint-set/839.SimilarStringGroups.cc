/*
   Two strings X and Y are similar if we can swap two letters (in different positions) of X, so that it equals Y. Also two strings X and Y are similar if they are equal.

   For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".

   Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}. Notice that "tars" and "arts" are in the same group even though they are not similar. Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.

   We are given a list strs of strings where every string in strs is an anagram of every other string in strs. How many groups are there?

    

   Example 1:

Input: strs = ["tars","rats","arts","star"]
Output: 2

Example 2:

Input: strs = ["omv","ovm"]
Output: 1

 

Constraints:

1 <= strs.length <= 300
1 <= strs[i].length <= 300
strs[i] consists of lowercase letters only.
All words in strs have the same length and are anagrams of each other.

*/


#include"head.h"
class Solution {
    private:
        vector<int> p,sz;
        void init(int n)
        {
            p.resize(n+1);
            sz.resize(n+1);
            for(int i=0;i<=n;i++)
                p[i]=i,sz[i]=1;
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

            if(sz[x]<sz[y])
            {
                p[px]=py;
                sz[py]+=px;
            }
            else
            {
                p[py]=px;
                sz[px]+=py;
            }
        }
        int check(int i,int j,const vector<string> &s)
        {
            int cnt=0,t1=-1,t2=-1;
            for(int m=0;m<s[i].size();m++)
            {
                if(s[i][m]==s[j][m])
                    continue;

                if(cnt==0)
                    t1=m,cnt++;

                else if(cnt==1)
                    t2=m,cnt++;
                else 
                    return false;
            }

            if(cnt==0) return true;
            else if(cnt==1) return false;

            if(s[i][t1]==s[j][t2]&&s[i][t2]==s[j][t1])
                return true;

            return false;
        }
    public:
        int numSimilarGroups(vector<string>& strs) {
        const int n=strs.size();
        init(n);

        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
            {
                if(check(i,j,strs))
                    merge(i,j);
            }

        int res=0;
        for(int i=0;i<n;i++)
            if(i==find(i))
                res++;

        return res;
        }
};


int main() 
{
    Solution s;
    vector<string> v={"tars","rats","arts","star"};
    cout<<s.numSimilarGroups(v)<<endl;
    return 0;
}
