/*
   There are n people standing in a line labeled from 1 to n. The first person in the line is holding a pillow initially. Every second, the person holding the pillow passes it to the next person standing in the line. Once the pillow reaches the end of the line, the direction changes, and people continue passing the pillow in the opposite direction.

   For example, once the pillow reaches the nth person they pass it to the n - 1th person, then to the n - 2th person and so on.

   Given the two positive integers n and time, return the index of the person holding the pillow after time seconds.



   Example 1:

Input: n = 4, time = 5
Output: 2
Explanation: People pass the pillow in the following way: 1 -> 2 -> 3 -> 4 -> 3 -> 2.
Afer five seconds, the pillow is given to the 2nd person.

Example 2:

Input: n = 3, time = 2
Output: 3
Explanation: People pass the pillow in the following way: 1 -> 2 -> 3.
Afer two seconds, the pillow is given to the 3rd person.



Constraints:

2 <= n <= 1000
1 <= time <= 1000

*/


#include"head.h"
class Solution {
	public:
		int passThePillow(int n, int time) {
		int x=time%(2*n-2);

		return x<=n-1?x+1:2*n-x-1;
		}
};


int main() 
{
	Solution s;
	cout<<s.passThePillow(4,5)<<endl;
	cout<<s.passThePillow(3,2)<<endl;
	return 0;
}
