/*
Given a m * n matrix mat of integers, sort it diagonally in ascending order from the top-left to the bottom-right then return the sorted array.

 

Example 1:

Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]

 

Constraints:

    m == mat.length
    n == mat[i].length
    1 <= m, n <= 100
    1 <= mat[i][j] <= 100

*/

#define c11
#include"head.h"

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
	unordered_map<int,priority_queue<int,vector<int> ,greater<int> > > h;
	for(int i=0;i<mat.size();i++)
		for(int j=0;j<mat[0].size();j++)
		{
			if(!h.count(i-j))
			{
			priority_queue<int,vector<int>, greater<int> > pq;
			h[i-j]=pq;
			}
			h[i-j].push(mat[i][j]);
		}        
	
	for(int i=0;i<mat.size();i++)
		for(int j=0;j<mat[0].size();j++)
		{
			mat[i][j]=h[i-j].top();
			h[i-j].pop();
		}
	return mat;
    }
};
