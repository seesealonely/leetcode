/*
   You are given a string num representing a large integer. An integer is good if it meets the following conditions:

   It is a substring of num with length 3.
   It consists of only one unique digit.

   Return the maximum good integer as a string or an empty string "" if no such integer exists.

Note:

A substring is a contiguous sequence of characters within a string.
There may be leading zeroes in num or a good integer.



Example 1:

Input: num = "6777133339"
Output: "777"
Explanation: There are two distinct good integers: "777" and "333".
"777" is the largest, so we return "777".

Example 2:

Input: num = "2300019"
Output: "000"
Explanation: "000" is the only good integer.

Example 3:

Input: num = "42352338"
Output: ""
Explanation: No substring of length 3 consists of only one unique digit. Therefore, there are no good integers.



Constraints:

3 <= num.length <= 1000
num only consists of digits.

*/


#include"head.h"
class Solution {
    public:
        string largestGoodInteger(string num) {
        vector<int> fre(10,0);
        const int n=num.size();
        for(int i=0;i<3;i++)
            fre[num[i]-'0']++;

        string res;;
        if(fre[num[2]-'0']==3) res=string(3,num[2]);
        if(n==3) return res;
        for(int i=3;i<n;i++)
        {
            fre[num[i-3]-'0']--,fre[num[i]-'0']++;
            if(fre[num[i]-'0']==3)
                res=max(res,string(3,num[i]));
        }

        return res;
        }
};


int main() 
{
    Solution s;
    cout<<s.largestGoodInteger("6777133339")<<endl;
    cout<<s.largestGoodInteger("2300019")<<endl;
    cout<<s.largestGoodInteger("42352338")<<endl;
    return 0;
}
