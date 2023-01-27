/*
   Given four integers sx, sy, tx, and ty, return true if it is possible to convert the point (sx, sy) to the point (tx, ty) through some operations, or false otherwise.

   The allowed operation on some point (x, y) is to convert it to either (x, x + y) or (x + y, y).



   Example 1:

Input: sx = 1, sy = 1, tx = 3, ty = 5
Output: true
Explanation:
One series of moves that transforms the starting point to the target is:
(1, 1) -> (1, 2)
(1, 2) -> (3, 2)
(3, 2) -> (3, 5)

Example 2:

Input: sx = 1, sy = 1, tx = 2, ty = 2
Output: false

Example 3:

Input: sx = 1, sy = 1, tx = 1, ty = 1
Output: true



Constraints:

1 <= sx, sy, tx, ty <= 109

*/


#include"head.h"
class Solution {
    public:
        bool reachingPoints(int sx, int sy, int tx, int ty) {

            while(tx>sx&&ty>sy)
            {
                if(tx<ty) ty%=tx;
                else
                    tx%=ty;
            }

            if(tx<sx||ty<sy)
                return false;

            if(sx==tx)
                return (ty-sy)%sx==0;

            return (tx-sx)%sy==0;
        }
};


int main() 
{
    Solution s;
    cout<<s.reachingPoints(1,1,3,5)<<endl;
    cout<<s.reachingPoints(1,1,2,2)<<endl;
    cout<<s.reachingPoints(1,1,1,1)<<endl;
    return 0;
}
