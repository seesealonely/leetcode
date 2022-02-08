/*
*/
#include"head.h"
class Solution {
    public:
        string getSmallestString(int n, int k) {
        string res;
        for(int i=n-1;i>=0;i--)
        {
            int remainder=k-26*i;
            if(remainder>0)
                res+='a'+remainder-1,k-=remainder;
            else
                res+='a',k--;
        }
        return res;
        }
};
int main() 
{
    Solution s;
    cout<<s.getSmallestString(3,27)<<endl;
    cout<<s.getSmallestString(5,73)<<endl;
    return 0;
}
