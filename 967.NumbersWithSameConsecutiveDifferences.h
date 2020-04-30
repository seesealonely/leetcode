/*
Return all non-negative integers of length N such that the absolute difference between every two consecutive digits is K.

Note that every number in the answer must not have leading zeros except for the number 0 itself. For example, 01 has one leading zero and is invalid, but 0 is valid.

You may return the answer in any order.

 

Example 1:

Input: N = 3, K = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.

Example 2:

Input: N = 2, K = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]

 

Note:

    1 <= N <= 9
    0 <= K <= 9

*/

#include"head.h"

class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
 	vector<int> v={1,2,3,4,5,6,7,8,9,0};
	for(int i=1;i<N;i++)
	{
		vector<int> tmp;
		for(int j=0;j<v.size();j++)
		{
			int x=v[j]%10;
			if(v[j]>0&&x+K<10&&x+K!=x-K)
				tmp.push_back(v[j]*10+x+K);
			if(v[j]>0&&x-K>=0)
				tmp.push_back(v[j]*10+x-K);
		}
		v=tmp;
	}       
	return v;
    }
};
