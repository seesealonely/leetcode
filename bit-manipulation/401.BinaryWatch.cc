/*
   A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59). Each LED represents a zero or one, with the least significant bit on the right.

   For example, the below binary watch reads "4:51".

   Given an integer turnedOn which represents the number of LEDs that are currently on, return all possible times the watch could represent. You may return the answer in any order.

   The hour must not contain a leading zero.

   For example, "01:00" is not valid. It should be "1:00".

   The minute must be consist of two digits and may contain a leading zero.

   For example, "10:2" is not valid. It should be "10:02".



   Example 1:

Input: turnedOn = 1
Output: ["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]

Example 2:

Input: turnedOn = 9
Output: []



Constraints:

0 <= turnedOn <= 10

*/


#include"head.h"
class Solution {
    public:
        vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        for(int i=0;i<12;i++)
            for(int j=0;j<60;j++)
            if(bit(i)+bit(j)==turnedOn)
                res.push_back(to_string(i)+":"+(j<10?"0":"")+to_string(j));

        return res;
        }
        vector<string> readBinaryWatch1(int turnedOn) {
        vector<string> res;
        for(int i=0;i<1024;i++)
        {
            int m=i&63,h=(i>>6);
            if(h<12&m<60&&bit(i)==turnedOn)
                res.push_back(to_string(h)+":"+(m<10?"0":"")+to_string(m));
        }
        return res;
        }
        int bit(int n)
        {
            int res=0;
            while(n)
            {
                res+=n&1;
                n>>=1;
            }
            return res;
        }
};


int main() 
{
    Solution s;
    show(s.readBinaryWatch(1));
    show(s.readBinaryWatch(9));
    show(s.readBinaryWatch1(1));
    show(s.readBinaryWatch1(9));
    return 0;
}
