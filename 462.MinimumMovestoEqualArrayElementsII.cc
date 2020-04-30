/*
Given a non-empty integer array, find the minimum number of moves required to make all array elements equal, where a move is incrementing a selected element by 1 or decrementing a selected element by 1.

You may assume the array's length is at most 10,000.

Example:

Input:
[1,2,3]

Output:
2

Explanation:
Only two moves are needed (remember each move increments or decrements one element):

[1,2,3]  =>  [2,2,3]  =>  [2,2,2]

*/
#include"462.MinimumMovestoEqualArrayElementsII.h"

int main()
{
	int vv[]={1,0,0,8,6};
	vector<int> v(vv,vv+5);
	int vv2[]={1,2};
	vector<int> v2(vv2,vv2+2);
	Solution s;
	cout<<s.minMoves2(v)<<endl;
	Solution s2;
	cout<<s2.minMoves2(v2)<<endl;
	return 0;
}
