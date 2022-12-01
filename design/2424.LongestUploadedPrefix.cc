/*
 You are given a stream of n videos, each represented by a distinct number from 1 to n that you need to "upload" to a server. You need to implement a data structure that calculates the length of the longest uploaded prefix at various points in the upload process.

We consider i to be an uploaded prefix if all videos in the range 1 to i (inclusive) have been uploaded to the server. The longest uploaded prefix is the maximum value of i that satisfies this definition.

Implement the LUPrefix class:

    LUPrefix(int n) Initializes the object for a stream of n videos.
    void upload(int video) Uploads video to the server.
    int longest() Returns the length of the longest uploaded prefix defined above.

 

Example 1:

Input
["LUPrefix", "upload", "longest", "upload", "longest", "upload", "longest"]
[[4], [3], [], [1], [], [2], []]
Output
[null, null, 0, null, 1, null, 3]

Explanation
LUPrefix server = new LUPrefix(4);   // Initialize a stream of 4 videos.
server.upload(3);                    // Upload video 3.
server.longest();                    // Since video 1 has not been uploaded yet, there is no prefix.
                                     // So, we return 0.
server.upload(1);                    // Upload video 1.
server.longest();                    // The prefix [1] is the longest uploaded prefix, so we return 1.
server.upload(2);                    // Upload video 2.
server.longest();                    // The prefix [1,2,3] is the longest uploaded prefix, so we return 3.

 

Constraints:

    1 <= n <= 105
    1 <= video <= n
    All values of video are distinct.
    At most 2 * 105 calls in total will be made to upload and longest.
    At least one call will be made to longest.

*/


#include"head.h"
class LUPrefix {
    public:
        LUPrefix(int n) {
        uf(n);
        nn=n;
        }

        void upload(int video) {
        up[--video]=true; 
        if(video>0&&up[video-1])
            merge(video-1,video);

        if(video+1<nn&&up[video+1])
            merge(video,video+1);
        }

        int longest() {
            if(!up[0])
                return 0;

            return sz[find(0)];
        }
        void uf(int n)
        {
            p.resize(n);
            up.resize(n);
            sz.resize(n);
            for(int i=0;i<n;i++)
                p[i]=i,sz[i]=1,up[i]=false;
        }

        int find(int x)
        {
            return x==p[x]?x:p[x]=find(p[x]);
        }

        void merge(int x,int y)
        {
            int px=find(x),py=find(y);
            if(px==py)
                return ;
            if(sz[px]<sz[py])
            {
                p[px]=py;
                sz[py]+=sz[px];
            }
            else
            {
                p[py]=px;
                sz[px]+=sz[py];
            }
        }
    private:
        int nn;
        vector<int> p,sz;
        vector<bool> up;
};


int main() 
{
    LUPrefix l(3);
    l.upload(3);
    cout<<l.longest()<<endl;
    l.upload(1);
    cout<<l.longest()<<endl;
    l.upload(2);
    cout<<l.longest()<<endl;
    return 0;
}
