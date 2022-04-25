/*
   There is a group of n people labeled from 0 to n - 1 where each person has a different amount of money and a different level of quietness.

   You are given an array richer where richer[i] = [ai, bi] indicates that ai has more money than bi and an integer array quiet where quiet[i] is the quietness of the ith person. All the given data in richer are logically correct (i.e., the data will not lead you to a situation where x is richer than y and y is richer than x at the same time).

   Return an integer array answer where answer[x] = y if y is the least quiet person (that is, the person y with the smallest value of quiet[y]) among all people who definitely have equal to or more money than the person x.



   Example 1:

Input: richer = [[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]], quiet = [3,2,5,4,6,1,7,0]
Output: [5,5,2,5,4,5,6,7]
Explanation:
answer[0] = 5.
Person 5 has more money than 3, which has more money than 1, which has more money than 0.
The only person who is quieter (has lower quiet[x]) is person 7, but it is not clear if they have more money than person 0.
answer[7] = 7.
Among all people that definitely have equal to or more money than person 7 (which could be persons 3, 4, 5, 6, or 7), the person who is the quietest (has lower quiet[x]) is person 7.
The other answers can be filled out with similar reasoning.

Example 2:

Input: richer = [], quiet = [0]
Output: [0]



Constraints:

n == quiet.length
1 <= n <= 500
0 <= quiet[i] < n
All the values of quiet are unique.
0 <= richer.length <= n 2246.LongestPathWithDifferentAdjacentCharacters 2246.LongestPathWithDifferentAdjacentCharacters.cc 851.LoudandRich.cc head.cc head.h head.o lib.a l.sh makefile (n - 1) / 2
0 <= ai, bi < n
ai != bi
All the pairs of richer are unique.
The observations in richer are all logically consistent.

*/


#include"head.h"
class Solution {
    public:
        vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
            const int n=quiet.size(),m=richer.size();
            vector<int> res(n,0),in(n,0);
            vector<vector<int>> g(n);
            for(int i=0;i<m;i++)
            {
                g[richer[i][0]].push_back(richer[i][1]);
                in[richer[i][1]]++;
            }
            
            queue<int> q;
            for(int i=0;i<n;i++)
            {
                if(!in[i])
                    q.push(i);
                res[i]=i;
            }

            while(!q.empty())
            {
                int cur=q.front();q.pop();int next=0;

                for(int i=0;i<g[cur].size();i++)
                {
                    next=g[cur][i]; 
                    if(quiet[res[cur]]<quiet[res[next]])
                        res[next]=res[cur];
                    if(--in[next]==0)
                        q.push(next);
                }
            }
            return res;
        }
};


int main() 
{
    Solution s;
    vector<vector<int>> v={{1,0},{2,1},{3,1},{3,7},{4,3},{5,3},{6,3}};
    vector<int> q={3,2,5,4,6,1,7,0};
    show(s.loudAndRich(v,q));
    v.clear();
    q.clear();q={0};
    show(s.loudAndRich(v,q));
    return 0;
}
