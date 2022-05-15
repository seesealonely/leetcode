/*
*/


#include"head.h"
class Solution {
    public:
        int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
            int mx=0,n=tiles.size(),res=0;
            sort(begin(tiles),end(tiles)); 
            for(int l=0,r=0,cover=0;res<carpetLen&&r<n;)
            {
                if(l==r||tiles[r][1]-tiles[l][0]<carpetLen)
                {
                    cover+=min(carpetLen,tiles[r][1]-tiles[r][0]+1);
                    res=max(res,cover);
                    r++;
                }
                else
                {
                    int part=max(0,tiles[l][0]+carpetLen-tiles[r][0]);
                    res=max(res,cover+part);
                    cover-=tiles[l][1]-tiles[l][0]+1;
                    ++l;
                }
            }
            return res;
        }
};


int main() 
{
    Solution s;
    vector<vector<int>> v={{1,5},{10,11},{12,18},{20,25},{30,32}};
    cout<<s.maximumWhiteTiles(v,10)<<endl;
    v.clear();v={{10,11},{1,1}};
    cout<<s.maximumWhiteTiles(v,2)<<endl;
    return 0;
}
