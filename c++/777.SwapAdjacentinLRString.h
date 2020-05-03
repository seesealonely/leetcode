/*
In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a move consists of either replacing one occurrence of "XL" with "LX", or replacing one occurrence of "RX" with "XR". Given the starting string start and the ending string end, return True if and only if there exists a sequence of moves to transform one string to the other.

Example:

Input: start = "RXXLRXRXL", end = "XRLXXRRLX"
Output: True
Explanation:
We can transform start to end following these steps:
RXXLRXRXL ->
XRXLRXRXL ->
XRLXRXRXL ->
XRLXXRRXL ->
XRLXXRRLX

Note:

    1 <= len(start) = len(end) <= 10000.
    Both start and end will only consist of characters in {'L', 'R', 'X'}.

*/

#include"head.h"

class Solution {
public:
    bool canTransform(string start, string end) {
	string s1,s2;
	for(int i=0;i<start.size();i++)
	if(start[i]!='X') s1+=start[i]
	for(int i=0;i<end.size();i++)
	if(end[i]!='X') s2+=end[i]
	if(s1!=s2) return false;
	
    }
};
