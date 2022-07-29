/*
   You are given an array of strings equations that represent relationships between variables where each string equations[i] is of length 4 and takes one of two different forms: "xi==yi" or "xi!=yi".Here, xi and yi are lowercase letters (not necessarily different) that represent one-letter variable names.

   Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.



   Example 1:

Input: equations = ["a==b","b!=a"]
Output: false
Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
There is no way to assign the variables to satisfy both equations.

Example 2:

Input: equations = ["b==a","a==b"]
Output: true
Explanation: We could assign a = 1 and b = 1 to satisfy both equations.



Constraints:

1 <= equations.length <= 500
equations[i].length == 4
equations[i][0] is a lowercase letter.
equations[i][1] is either '=' or '!'.
equations[i][2] is '='.
equations[i][3] is a lowercase letter.

*/


#include"head.h"
class uf
{
    public:
        uf(int n):p(n),r(n,1)
        {
            for(int i=0;i<n;i++)
                p[i]=i;
        }
        int find(int x)
        {
            return x==p[x]?x:p[x]=find(p[x]);
        }

        void merge(int x,int y)
        {
            int px=find(x),py=find(y);

            if(px!=py)
            {
                if(r[px]<r[py])
                {
                    p[px]=py;
                    r[py]+=r[px];
                }
                else
                {
                    p[py]=px;
                    r[px]+=r[py];
                }
            }
        }
    private:
        vector<int> p,r;
};
class Solution {
    public:
        bool equationsPossible(vector<string>& s) {
        uf p(26);
        const int n=s.size();

        for(int i=0;i<n;i++)
            if(s[i][1]=='=')
                p.merge(s[i][0]-'a',s[i][3]-'a');

        for(int i=0;i<n;i++)
            if(s[i][1]=='!')
            {
                if(p.find(s[i][0]-'a')==p.find(s[i][3]-'a'))
                    return false;
            }

        return true;
        }
};


int main() 
{
    Solution s;
    vector<string> v={"a==b","b!=a"};
    cout<<s.equationsPossible(v)<<endl;
    v.clear();v={"b==a","a==b"};
    cout<<s.equationsPossible(v)<<endl;

    return 0;
}
