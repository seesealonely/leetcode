/*
   Given two numbers, hour and minutes, return the smaller angle (in degrees) formed between the hour and the minute hand.

   Answers within 10-5 of the actual value will be accepted as correct.



   Example 1:

Input: hour = 12, minutes = 30
Output: 165

Example 2:

Input: hour = 3, minutes = 30
Output: 75

Example 3:

Input: hour = 3, minutes = 15
Output: 7.5



Constraints:

1 <= hour <= 12
0 <= minutes <= 59

*/


#include"head.h"
class Solution {
    public:
        double angleClock(int hour, int minutes) {
        hour%=12;
        int h=360/12,m=360/(12*5);

        double angle=abs((double)hour*h+(double)minutes/60*30-(double)minutes*m);
        return angle>180?360-angle:angle;
        }
};


int main() 
{
    Solution s;
    cout<<s.angleClock(12,30)<<endl;
    cout<<s.angleClock(3,30)<<endl;
    cout<<s.angleClock(3,15)<<endl;
    return 0;
}
