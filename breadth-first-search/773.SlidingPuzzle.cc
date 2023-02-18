/*
   On an 2 x 3 board, there are five tiles labeled from 1 to 5, and an empty square represented by 0. A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.

   The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].

   Given the puzzle board board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.



   Example 1:

Input: board = [[1,2,3],[4,0,5]]
Output: 1
Explanation: Swap the 0 and the 5 in one move.

Example 2:

Input: board = [[1,2,3],[5,4,0]]
Output: -1
Explanation: No number of moves will make the board solved.

Example 3:

Input: board = [[4,1,2],[5,0,3]]
Output: 5
Explanation: 5 is the smallest number of moves that solves the board.
An example path:
After move 0: [[4,1,2],[5,0,3]]
After move 1: [[4,1,2],[0,5,3]]
After move 2: [[0,1,2],[4,5,3]]
After move 3: [[1,0,2],[4,5,3]]
After move 4: [[1,2,0],[4,5,3]]
After move 5: [[1,2,3],[4,5,0]]



Constraints:

board.length == 2
board[i].length == 3
0 <= board[i][j] <= 5
Each value board[i][j] is unique.

*/

#define c11
#include"head.h"
class Solution {
    public:
        int slidingPuzzle(vector<vector<int>>& board) {
            string state;
            for(int i=0;i<2;i++)
                for(int j=0;j<3;j++)
                    state+='0'+board[i][j];

            queue<pair<string,int>> q;
            unordered_set<string> vis({state});
            q.push({state,0});
            while(!q.empty())
            {
                pair<string,int> cur=q.front();q.pop();
                if(cur.first=="123450") return cur.second;
                int i=(int)cur.first.find('0');
                for(int j=0;j<6;j++)
                {
                    if(i==j) continue;
                    if(i%3==j%3||(abs(i-j)==1&&j/3==i/3))
                    {
                        string next=cur.first;
                        swap(next[j],next[i]);
                        if(vis.count(next)) continue;
                        q.push({next,cur.second+1});
                        vis.insert(next);
                    }
                }
            }
            return -1;
        }
};


int main() 
{
    Solution s;
    vector<vector<int>> v={{1,2,3},{4,0,5}};
    cout<<s.slidingPuzzle(v)<<endl;
    v.clear();v={{1,2,3},{5,4,0}};
    cout<<s.slidingPuzzle(v)<<endl;
    v.clear();v={{4,1,2},{5,0,3}};
    cout<<s.slidingPuzzle(v)<<endl;
    return 0;
}
