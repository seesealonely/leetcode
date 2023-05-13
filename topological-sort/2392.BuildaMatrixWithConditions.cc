/*
   You are given a positive integer k. You are also given:

   a 2D integer array rowConditions of size n where rowConditions[i] = [abovei, belowi], and
   a 2D integer array colConditions of size m where colConditions[i] = [lefti, righti].

   The two arrays contain integers from 1 to k.

   You have to build a k x k matrix that contains each of the numbers from 1 to k exactly once. The remaining cells should have the value 0.

   The matrix should also satisfy the following conditions:

   The number abovei should appear in a row that is strictly above the row at which the number belowi appears for all i from 0 to n - 1.
   The number lefti should appear in a column that is strictly left of the column at which the number righti appears for all i from 0 to m - 1.

   Return any matrix that satisfies the conditions. If no answer exists, return an empty matrix.



   Example 1:

Input: k = 3, rowConditions = [[1,2],[3,2]], colConditions = [[2,1],[3,2]]
Output: [[3,0,0],[0,0,1],[0,2,0]]
Explanation: The diagram above shows a valid example of a matrix that satisfies all the conditions.
The row conditions are the following:
- Number 1 is in row 1, and number 2 is in row 2, so 1 is above 2 in the matrix.
- Number 3 is in row 0, and number 2 is in row 2, so 3 is above 2 in the matrix.
The column conditions are the following:
- Number 2 is in column 1, and number 1 is in column 2, so 2 is left of 1 in the matrix.
- Number 3 is in column 0, and number 2 is in column 1, so 3 is left of 2 in the matrix.
Note that there may be multiple correct answers.

Example 2:

Input: k = 3, rowConditions = [[1,2],[2,3],[3,1],[2,3]], colConditions = [[2,1]]
Output: []
Explanation: From the first two conditions, 3 has to be below 1 but the third conditions needs 3 to be above 1 to be satisfied.
No matrix can satisfy all the conditions, so we return the empty matrix.



Constraints:

2 <= k <= 400
1 <= rowConditions.length, colConditions.length <= 104
rowConditions[i].length == colConditions[i].length == 2
1 <= abovei, belowi, lefti, righti <= k
abovei != belowi
lefti != righti

*/


#include"head.h"
class Solution {
	public:
		vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
			vector<int> r=topsort(k,rowConditions);

			if(r.empty())
				return {};

			vector<int> c=topsort(k,colConditions);
			if(c.empty())
				return {};

			vector<vector<int>> res(k,vector<int> (k,0));
			for(int i=0;i<k;i++)
				res[r[i]][c[i]]=i+1;

			return res;

		}
		vector<int> topsort(int k,const vector<vector<int>> &edges)
		{
			vector<vector<int>> g(k);
			vector<int> d(k,0);

			for(int i=0;i<edges.size();i++)
			{
				int x=edges[i][0]-1,y=edges[i][1]-1;
				g[x].push_back(y);
				d[y]++;
			}

			queue<int> q;
			for(int i=0;i<k;i++)
				if(d[i]==0)
					q.push(i);

			vector<int> res(k);

			int cnt=0;
			while(!q.empty())
			{
				int u=q.front();
				q.pop();

				res[u]=cnt++;
				for(int i=0;i<g[u].size();i++)
				{
					int v=g[u][i];
					if(--d[v]==0)
						q.push(v);
				}
			}

			for(int i=0;i<k;i++)
				if(d[i]>0)
					return {};
			return res;
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> r={{1,2},{3,2}},c={{2,1},{3,2}};
	show(s.buildMatrix(3,r,c));
	r.clear();r={{1,2},{2,3},{3,1},{2,3}},c={{2,1}};
	show(s.buildMatrix(3,r,c));

	return 0;
}
