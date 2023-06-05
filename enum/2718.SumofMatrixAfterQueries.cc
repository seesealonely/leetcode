/*
   You are given an integer n and a 0-indexed 2D array queries where queries[i] = [typei, indexi, vali].

   Initially, there is a 0-indexed n x n matrix filled with 0's. For each query, you must apply one of the following changes:

   if typei == 0, set the values in the row with indexi to vali, overwriting any previous values.
   if typei == 1, set the values in the column with indexi to vali, overwriting any previous values.

   Return the sum of integers in the matrix after all queries are applied.



   Example 1:

Input: n = 3, queries = [[0,0,1],[1,2,2],[0,2,3],[1,0,4]]
Output: 23
Explanation: The image above describes the matrix after each query. The sum of the matrix after all queries are applied is 23. 

Example 2:

Input: n = 3, queries = [[0,0,4],[0,1,2],[1,0,1],[0,2,3],[1,2,1]]
Output: 17
Explanation: The image above describes the matrix after each query. The sum of the matrix after all queries are applied is 17.



Constraints:

1 <= n <= 104
1 <= queries.length <= 5 * 104
queries[i].length == 3
0 <= typei <= 1
0 <= indexi < n
0 <= vali <= 105

*/


#include"head.h"
class Solution {
	public:
		long long matrixSumQueries(int n, vector<vector<int>>& queries) {
		vector<bool> row(n,false),col(n,false);
		int r=n,c=n;

		long long res=0;
		for(int i=queries.size()-1;i>=0;i--)
		if(queries[i][0]==0&&row[queries[i][1]]==false)
		{
			res+=(long long)queries[i][2]*c;
			row[queries[i][1]]=true;
			r--;	
		}
		else if(queries[i][0]==1&&col[queries[i][1]]==false)
		{
			res+=(long long)queries[i][2]*r;
			col[queries[i][1]]=true;
			c--;
		}
		return res;
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> queries = {{0,0,1},{1,2,2},{0,2,3},{1,0,4}};
	cout<<s.matrixSumQueries(3,queries)<<endl;
	queries.clear();queries = {{0,0,4},{0,1,2},{1,0,1},{0,2,3},{1,2,1}};
	cout<<s.matrixSumQueries(3,queries)<<endl;
	return 0;
}
