/*
   You are given two strings current and correct representing two 24-hour times.

   24-hour times are formatted as "HH:MM", where HH is between 00 and 23, and MM is between 00 and 59. The earliest 24-hour time is 00:00, and the latest is 23:59.

   In one operation you can increase the time current by 1, 5, 15, or 60 minutes. You can perform this operation any number of times.

   Return the minimum number of operations needed to convert current to correct.



   Example 1:

Input: current = "02:30", correct = "04:35"
Output: 3
Explanation:
We can convert current to correct in 3 operations as follows:
- Add 60 minutes to current. current becomes "03:30".
- Add 60 minutes to current. current becomes "04:30".
- Add 5 minutes to current. current becomes "04:35".
It can be proven that it is not possible to convert current to correct in fewer than 3 operations.

Example 2:

Input: current = "11:00", correct = "11:01"
Output: 1
Explanation: We only have to add one minute to current, so the minimum number of operations needed is 1.



Constraints:

current and correct are in the format "HH:MM"
current <= correct

*/


#include"head.h"
class Solution {
    public:
        int convertTime(string current, string correct) {
            vector<int> m={1,5,15,60};
        int h1=stoi(current.substr(0,2)),m1=stoi(current.substr(3)),
            h2=stoi(correct.substr(0,2)),m2=stoi(correct.substr(3)),
            sub=0;
        if(m2<m1)
            sub=m2+60-m1,--h2;
        else
            sub=m2-m1;
        sub+=(h2-h1)*60;
        int res=0;
        for(int i=3;i>=0;i--)
            if(sub/m[i])
            res+=sub/m[i],sub%=m[i];
        return res;
        }
};


int main() 
{
    Solution s;
    cout<<s.convertTime("02:30","04:35")<<endl;
    cout<<s.convertTime("11:00","11:01")<<endl;
    return 0;
}
