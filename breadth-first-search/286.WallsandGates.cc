/*
   You are given a m x n 2D grid initialized with these three possible values.

   -1 - A wall or an obstacle.
   0 - A gate.
   INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.

   Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

   For example, given the 2D grid:

   INF -1 0 INF
   INF INF INF -1
   INF -1 INF -1
   0 -1 INF INF

   After running your function, the 2D grid should be:

   3 -1 0 1
   2 2 1 -1
   1 -1 2 -1
   0 -1 3 4

*/


#include"head.h"
class Solution {
    public:
        void wallsAndGates(vector<vector<int>>& rooms) {
            queue<pair<int, int>> q;
            vector<vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
            for (int i = 0; i < rooms.size(); ++i) {
                for (int j = 0; j < rooms[i].size(); ++j) {
                    if (rooms[i][j] == 0) q.push({i, j});
                }
            }
            while (!q.empty()) {
                int i = q.front().first, j = q.front().second; q.pop();
                for (int k = 0; k < dirs.size(); ++k) {
                    int x = i + dirs[k][0], y = j + dirs[k][1];
                    if (x < 0 || x >= rooms.size() || y < 0 || y >= rooms[0].size() || rooms[x][y] < rooms[i][j] + 1) continue;
                    rooms[x][y] = rooms[i][j] + 1;
                    q.push({x, y});
                }
            }
        }
};


int main() 
{
    Solution s;
    vector<vector<int>> v={{2147483647,-1,0,2147483647},{2147483647,2147483647,2147483647,-1},{2147483647,-1,2147483647,-1},{0,-1,2147483647,2147483647}};
    s.wallsAndGates(v);
    show(v);
    v.clear();v={{0,-1},{2147483647,2147483647}};
    s.wallsAndGates(v);
    show(v);
    return 0;
}
