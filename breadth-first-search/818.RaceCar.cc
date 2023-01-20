/*
   Your car starts at position 0 and speed +1 on an infinite number line. Your car can go into negative positions. Your car drives automatically according to a sequence of instructions 'A' (accelerate) and 'R' (reverse):

   When you get an instruction 'A', your car does the following:
   position += speed
   speed *= 2
   When you get an instruction 'R', your car does the following:
   If your speed is positive then speed = -1
   otherwise speed = 1
   Your position stays the same.

   For example, after commands "AAR", your car goes to positions 0 --> 1 --> 3 --> 3, and your speed goes to 1 --> 2 --> 4 --> -1.

   Given a target position target, return the length of the shortest sequence of instructions to get there.

    

   Example 1:

Input: target = 3
Output: 2
Explanation:
The shortest instruction sequence is "AA".
Your position goes from 0 --> 1 --> 3.

Example 2:

Input: target = 6
Output: 5
Explanation:
The shortest instruction sequence is "AAARA".
Your position goes from 0 --> 1 --> 3 --> 7 --> 7 --> 6.

 

Constraints:

1 <= target <= 104

*/


#include"head.h"
class Solution {
    public:
        int racecar(int target) {
        vector<vector<vector<int>>> dis(2*target+1,vector<vector<int>>(21,vector<int>(2,INT_MAX)));

        dis[0][0][0]=0;
        queue<vector<int>> q;
        q.push({0,0,0});
        while(!q.empty())
        {
            vector<int> cur(q.front());
            q.pop();
            int len=cur[0],speed=1<<cur[1];
            if(cur[2]==1)
                speed=-speed;

            if(len==target)
                return dis[cur[0]][cur[1]][cur[2]];

            //instruction A
            if(len+speed<=target*2&&len+speed>=0)
            {
                vector<int> next({len+speed,cur[1]+1,cur[2]});
                if(dis[next[0]][next[1]][next[2]]>dis[cur[0]][cur[1]][cur[2]]+1)
                {
                    dis[next[0]][next[1]][next[2]]=dis[cur[0]][cur[1]][cur[2]]+1;
                    q.push(next);
                }
            }
            //instruction R
            vector<int> next({len,0,1-cur[2]});
            if(dis[next[0]][next[1]][next[2]]>dis[cur[0]][cur[1]][cur[2]]+1)
            {
                dis[next[0]][next[1]][next[2]]=dis[cur[0]][cur[1]][cur[2]]+1;
                q.push(next);
            }
        }
        return -1;
        }
};


int main() 
{
    Solution s;
    cout<<s.racecar(3)<<endl;
    cout<<s.racecar(6)<<endl;
    return 0;
}
