/*
   You are given a positive integer num. You may swap any two digits of num that have the same parity (i.e. both odd digits or both even digits).

   Return the largest possible value of num after any number of swaps.



   Example 1:

Input: num = 1234
Output: 3412
Explanation: Swap the digit 3 with the digit 1, this results in the number 3214.
Swap the digit 2 with the digit 4, this results in the number 3412.
Note that there may be other sequences of swaps but it can be shown that 3412 is the largest possible number.
Also note that we may not swap the digit 4 with the digit 1 since they are of different parities.

Example 2:

Input: num = 65875
Output: 87655
Explanation: Swap the digit 8 with the digit 6, this results in the number 85675.
Swap the first digit 5 with the digit 7, this results in the number 87655.
Note that there may be other sequences of swaps but it can be shown that 87655 is the largest possible number.



Constraints:

1 <= num <= 109

*/


#include"head.h"
class Solution {
    public:
        int largestInteger(int num) {
            vector<int> o,e;
            string s=to_string(num);
            int n=s.size();
            for(int i=0,cur;i<n;i++)
            {
                cur=s[i]-'0';
                if(cur%2)
                    o.push_back(cur);
                else
                    e.push_back(cur);
            }

            sort(o.begin(),o.end());
            sort(e.begin(),e.end());
            int res=0;
            for(int i=0;i<n;i++)
            {
                if((s[i]-'0')%2)
                    res=res*10+o.back(),o.pop_back();
                else
                    res=res*10+e.back(),e.pop_back();
            }
            return res;

        }
};


int main() 
{
    Solution s;
    cout<<s.largestInteger(1234)<<endl;
    cout<<s.largestInteger(65875)<<endl;
    return 0;
}
