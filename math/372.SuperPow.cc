/*
   Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.



   Example 1:

Input: a = 2, b = [3]
Output: 8

Example 2:

Input: a = 2, b = [1,0]
Output: 1024

Example 3:

Input: a = 1, b = [4,3,3,8,5,2]
Output: 1



Constraints:

1 <= a <= 231 - 1
1 <= b.length <= 2000
0 <= b[i] <= 9
b does not contain leading zeros.

*/


#include"head.h"
class Solution {
    public:
        #define ll long long 
        const int mod=1337;
        int superPow(int a, vector<int>& b) {
        if(b.empty()) return 1;

        int p1=(ll)power(a,b.back())%mod;
        b.pop_back();
        int p2=(ll)power(superPow(a,b)%mod,10)%mod;
        return (p1%mod)*(p2%mod)%mod; 
        }
        int power(int a,int b)
        {
            if(!b) return 1;

            ll res=1;
            while(b--)
                res=(res*a)%mod;
        
            return res;
        }
};


int main() 
{
    Solution s;
    vector<int> v={3};
    cout<<s.superPow(2,v)<<endl;
    v.clear();v={1,0};
    cout<<s.superPow(2,v)<<endl;
    v.clear();v={4,3,3,8,5,3};
    cout<<s.superPow(1,v)<<endl;
    return 0;
}
