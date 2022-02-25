/*
*/
#include"head.h"
class Solution {
    public:
        int eatenApples(vector<int>& apples, vector<int>& days) {
            typedef pair<int,int> pii;
            priority_queue<pii,vector<pii>,greater<pii>> pq;
            const int n=apples.size();

            int res=0;
            for(int i=0;i<n||!pq.empty();i++)
            {
                    while(!pq.empty()&&pq.top().first==i)
                        pq.pop();

                    if(i<n&&apples[i])
                        pq.push({i+days[i],apples[i]});

                    if(!pq.empty())
                    {
                        pii cur=pq.top();
                        pq.pop();
                        res++;
                        cur.second--;
                        if(cur.second>0)
                            pq.push(cur);
                    }
            }
            return res;
        }
};
int main() 
{
    Solution s;
    vector<int> v1={1,2,3,5,2},v2={3,2,1,4,2};
    cout<<s.eatenApples(v1,v2)<<endl;
    v1.clear();v1={3,0,0,0,0,2},v2={3,0,0,0,0,2};
    cout<<s.eatenApples(v1,v2)<<endl;
    return 0;
}
