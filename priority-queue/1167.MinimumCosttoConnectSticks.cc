/*
   You have some sticks with positive integer lengths.

   You can connect any two sticks of lengths X and Y into one stick by paying a cost of X + Y. You perform this action until there is one stick remaining.

   Return the minimum cost of connecting all the given sticks into one stick in this way.

   Example 1:

   Example 2:

Constraints:

1 <= sticks.length <= 10^4
1 <= sticks[i] <= 10^4

*/


#include"head.h"
class Solution {
    public:
        int connectSticks(vector<int>& sticks) {

            priority_queue<int, vector<int>, greater<int>> pq;
            for(int stick: sticks) pq.push(stick);
            int res = 0;
            while(pq.size() > 1){
                int cost = pq.top();
                pq.pop();
                cost += pq.top();
                pq.pop();

                res += cost;
                pq.push(cost);
            }
            return res;
        }
        int usingSort(vector<int>& sticks) {
            if(sticks.size()<2)
                return  0;
            int n=sticks.size(),len=n;
            sort(sticks.begin(),sticks.end());
            int res=0;
            for(int i=0;i<sticks.size();i++)
                res+=sticks[i]*n--;
            return res-((len&1)==1?sticks[0]:0);
        }
};


int main() 
{
    Solution s;
    vector<int> v={2,4,3};
    cout<<s.connectSticks(v)<<endl;
    cout<<s.usingSort(v)<<endl;
    v.clear();v={1,8,3,5};
    cout<<s.usingSort(v)<<endl;
    cout<<s.usingSort(v)<<endl;
    v.clear();v={5};
    cout<<s.usingSort(v)<<endl;
    cout<<s.usingSort(v)<<endl;
    return 0;
}
