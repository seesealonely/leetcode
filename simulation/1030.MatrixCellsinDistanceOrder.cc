/*
   You are given four integers row, cols, rCenter, and cCenter. There is a rows x cols matrix and you are on the cell with the coordinates (rCenter, cCenter).

   Return the coordinates of all cells in the matrix, sorted by their distance from (rCenter, cCenter) from the smallest distance to the largest distance. You may return the answer in any order that satisfies this condition.

   The distance between two cells (r1, c1) and (r2, c2) is |r1 - r2| + |c1 - c2|.



   Example 1:

Input: rows = 1, cols = 2, rCenter = 0, cCenter = 0
Output: [[0,0],[0,1]]
Explanation: The distances from (0, 0) to other cells are: [0,1]

Example 2:

Input: rows = 2, cols = 2, rCenter = 0, cCenter = 1
Output: [[0,1],[0,0],[1,1],[1,0]]
Explanation: The distances from (0, 1) to other cells are: [0,1,1,2]
The answer [[0,1],[1,1],[0,0],[1,0]] would also be accepted as correct.

Example 3:

Input: rows = 2, cols = 3, rCenter = 1, cCenter = 2
Output: [[1,2],[0,2],[1,1],[0,1],[1,0],[0,0]]
Explanation: The distances from (1, 2) to other cells are: [0,1,1,2,2,3]
There are other answers that would also be accepted as correct, such as [[1,2],[1,1],[0,2],[1,0],[0,1],[0,0]].



Constraints:

1 <= rows, cols <= 100
0 <= rCenter < rows
0 <= cCenter < cols

*/


#include"head.h"
class Solution {
    public:
        vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
            return dir(rows,cols,rCenter,cCenter);
            return bfs(rows,cols,rCenter,cCenter);
            return bucketsort(rows,cols,rCenter,cCenter);
            return bysort(rows,cols,rCenter,cCenter);
        }

        vector<vector<int>> bysort(int R, int C, int rCenter, int cCenter) {
            vector<vector<int>> res;
            for(int i=0;i<R;i++)
                for(int j=0;j<C;j++)
                    res.push_back({i,j});
            sort(res.begin(),res.end(),[&](vector<int>&a,vector<int> &b)
                    {
                    return abs(a[0]-rCenter)+abs(a[1]-cCenter)<abs(b[0]-rCenter)+abs(b[1]-cCenter);
                    }
                );

            return res;
        }
        vector<vector<int>> bucketsort(int R, int C, int rCenter, int cCenter) {
            const int n=max(rCenter,R-1-rCenter)+max(cCenter,C-1-cCenter);
            vector<vector<vector<int>>> bucket(n+1);

            for(int i=0;i<R;i++)
                for(int j=0;j<C;j++)
                {
                    int d=dist(rCenter,cCenter,i,j);
                    vector<int> cur={i,j};
                    bucket[d].push_back(move(cur));
                }

            vector<vector<int> > res;
            for(int i=0;i<n+1;i++)
                for(int j=0;j<bucket[i].size();j++)
                    res.push_back(bucket[i][j]);

            return res;
        }
        int dist(int r,int c,int x,int y)
        {
            return abs(r-x)+abs(c-y);
        }
        vector<vector<int>> bfs(int R, int C, int rCenter, int cCenter) {
            vector<vector<int> > res;
            vector<int> dir={-1,1};
            for(int d=0;d<=max(rCenter,R-1-rCenter)+max(cCenter,C-1-cCenter);d++)
            {
                for(int rd=0;rd<=d;rd++)
                {
                    for(int m=0;m<2;m++)
                    {
                        int x=rCenter+rd*dir[m];
                        for(int n=0;n<2;n++)
                        {
                            int y=cCenter+(d-rd)*dir[n];
                            if(x>=0&&x<R&&y<C&&y>=0)
                                res.push_back({x,y});
                            if(res.size()==R*C) return res;
                            if(d-rd==0) break;
                        }
                        if(rd==0) break;
                    }
                }
            }
            return vector<vector<int>> ();
        }
        vector<vector<int>> dir(int R, int C, int rCenter, int cCenter) {
            int maxdist=max(rCenter,R-1-rCenter)+max(cCenter,C-1-cCenter);
            vector<vector<int>> dir={{1,1},{1,-1},{-1,-1},{-1,1}};

            vector<vector<int>> res;
            int r=rCenter,c=cCenter;
            res.push_back({r,c});
            for(int i=1;i<=maxdist;i++)
            {
                r--;
                for(int j=0;j<dir.size();j++)
                {
                    while(j%2==0&&r!=rCenter||j%2&&c!=cCenter)
                    {
                        if(r>=0&&r<R&&c>=0&&c<C)
                            res.push_back({r,c});
                        r+=dir[j][0];
                        c+=dir[j][1];
                    }

                }
            }
            return res;
        }
};


int main() 
{
    Solution s;
    show(s.allCellsDistOrder(1,2,0,0));
    cout<<"$$$$$$$$"<<endl;
    show(s.allCellsDistOrder(2,2,0,1));
    cout<<"$$$$$$$$"<<endl;
    show(s.allCellsDistOrder(2,3,1,2));
    cout<<"$$$$$$$$"<<endl;
    return 0;
}
