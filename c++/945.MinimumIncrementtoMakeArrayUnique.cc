/*
Given an array of integers A, a move consists of choosing any A[i], and incrementing it by 1.

Return the least number of moves to make every value in A unique.

 

Example 1:

Input: [1,2,2]
Output: 1
Explanation:  After 1 move, the array could be [1, 2, 3].

Example 2:

Input: [3,2,1,2,1,7]
Output: 6
Explanation:  After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
It can be shown with 5 or less moves that it is impossible for the array to have all unique values.

 

Note:

    0 <= A.length <= 40000
    0 <= A[i] < 40000
Given an array of integers A, a move consists of choosing any A[i], and incrementing it by 1.

Return the least number of moves to make every value in A unique.

 

Example 1:

Input: [1,2,2]
Output: 1
Explanation:  After 1 move, the array could be [1, 2, 3].

Example 2:

Input: [3,2,1,2,1,7]
Output: 6
Explanation:  After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
It can be shown with 5 or less moves that it is impossible for the array to have all unique values.

 

Note:

    0 <= A.length <= 40000
    0 <= A[i] < 40000

*/

#include"945.MinimumIncrementtoMakeArrayUnique.h"

int main()
{
	vector<int> v;
	Solution s;
	v.push_back(1);v.push_back(2);v.push_back(2);
	cout<<s.minIncrementForUnique(v)<<endl;
	v.clear();v.push_back(3);v.push_back(2);v.push_back(1);v.push_back(2);v.push_back(1);v.push_back(7);
	cout<<s.minIncrementForUnique(v)<<endl;
	return 0;
}
