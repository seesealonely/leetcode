/*
   A frog is crossing a river. The river is divided into some number of units, and at each unit, there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.

   Given a list of stones' positions (in units) in sorted ascending order, determine if the frog can cross the river by landing on the last stone. Initially, the frog is on the first stone and assumes the first jump must be 1 unit.

   If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units. The frog can only jump in the forward direction.



   Example 1:

Input: stones = [0,1,3,5,6,8,12,17]
Output: true
Explanation: The frog can jump to the last stone by jumping 1 unit to the 2nd stone, then 2 units to the 3rd stone, then 2 units to the 4th stone, then 3 units to the 6th stone, 4 units to the 7th stone, and 5 units to the 8th stone.

Example 2:

Input: stones = [0,1,2,3,4,8,9,11]
Output: false
Explanation: There is no way to jump to the last stone as the gap between the 5th and 6th stone is too large.



Constraints:

2 <= stones.length <= 2000
0 <= stones[i] <= 231 - 1
stones[0] == 0
stones is sorted in a strictly increasing order.

*/


#define c11
#include"head.h"
class Solution {
    public:
        bool canCross(vector<int>& stones) {
            unordered_map<int,int> exist;
            const int n=stones.size();
            for(int i=0;i<n;i++)
                exist[stones[i]]=i;

            vector<vector<bool> > vis(n,vector<bool>(n,false));
            vis[0][0]=true;
            queue<pair<int,int>> q;q.push({0,0});

            while(!q.empty())
            {
                pair<int,int> cur=q.front();
                int i=q.front().first,k=q.front().second;
                q.pop();
                if(i==n-1)
                    return true;
                for(int j=-1;j<=1;j++)
                {
                    int nextk=k+j,nextx=stones[i]+nextk;
                    if(nextk<=0)
                        continue;
                    if(exist.find(nextx)!=exist.end())
                    {
                        int ni=exist[nextx];
                        if(!vis[ni][nextk])
                        {
                            vis[ni][nextk]=true;
                            q.push({ni,nextk});
                        }
                    }
                }
            }
            return false;
        }
};


int main() 
{
    Solution s;
    vector<int> v={0,1,3,5,6,8,12,17};
    cout<<s.canCross(v)<<endl;
    v.clear();v={0,1,2,3,4,8,9,11};
    cout<<s.canCross(v)<<endl;
    return 0;
}
