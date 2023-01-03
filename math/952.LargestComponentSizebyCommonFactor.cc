/*
   You are given an integer array of unique positive integers nums. Consider the following graph:

   There are nums.length nodes, labeled nums[0] to nums[nums.length - 1],
   There is an undirected edge between nums[i] and nums[j] if nums[i] and nums[j] share a common factor greater than 1.

   Return the size of the largest connected component in the graph.

    

   Example 1:

Input: nums = [4,6,15,35]
Output: 4

Example 2:

Input: nums = [20,50,9,63]
Output: 2

Example 3:

Input: nums = [2,3,6,7,4,12,21,39]
Output: 8

 

Constraints:

1 <= nums.length <= 2 * 104
1 <= nums[i] <= 105
All the values of nums are unique.

*/

#define c11
#include"head.h"
class uf
{
    public:
        vector<int> p,sz;
        uf(int n)
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
                return;
            if(sz[px]<sz[py])
            {
                p[py]=px;
                sz[px]+=sz[py];
            }
            else
            {
                p[px]=py;
                sz[py]+=sz[px];
            }
        }
};
class Solution {
    public:
        int largestComponentSize(vector<int>& nums) {
            const int n=nums.size();
            unordered_map<int,vector<int>> h;
            uf u(100001);
            for(int i=0;i<n;i++)
            {
                int cur=nums[i];
                for(int j=2;j*j<=cur;j++)
                {
                    if(cur%j==0)
                        h[j].push_back(i);
                    while(cur%j==0)
                        cur/=j;
                }
                if(cur>1)
                    h[cur].push_back(i);
            }

            for(unordered_map<int,vector<int>> ::iterator it=h.begin();it!=h.end();it++)
            {
                for(int i=1;i<it->second.size();i++)
                {
                    int x=it->second[0],y=it->second[i];
                    u.merge(x,y);
                }
            }

            int res=0;
            for(int i=0;i<n;i++)
                res=max(res,u.sz[i]);
            return res;
        }
};


int main() 
{
    Solution s;
    vector<int> v={4,6,15,35};
    cout<<s.largestComponentSize(v)<<endl;
    v.clear();v={20,50,9,63};
    cout<<s.largestComponentSize(v)<<endl;
    v.clear();v={2,3,6,7,4,12,21,39};
    cout<<s.largestComponentSize(v)<<endl;
    return 0;
}
