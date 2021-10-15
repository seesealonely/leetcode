/*
   You are given an m x n integer matrix mat and an integer target.

   Choose one integer from each row in the matrix such that the absolute difference between target and the sum of the chosen elements is minimized.

   Return the minimum absolute difference.

   The absolute difference between two numbers a and b is the absolute value of a - b.



   Example 1:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], target = 13
Output: 0
Explanation: One possible choice is to:
- Choose 1 from the first row.
- Choose 5 from the second row.
- Choose 7 from the third row.
The sum of the chosen elements is 13, which equals the target, so the absolute difference is 0.

Example 2:

Input: mat = [[1],[2],[3]], target = 100
Output: 94
Explanation: The best possible choice is to:
- Choose 1 from the first row.
- Choose 2 from the second row.
- Choose 3 from the third row.
The sum of the chosen elements is 6, and the absolute difference is 94.

Example 3:

Input: mat = [[1,2,9,8,7]], target = 6
Output: 1
Explanation: The best choice is to choose 7 from the first row.
The absolute difference is 1.



Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 70
1 <= mat[i][j] <= 70
1 <= target <= 800

*/
#include"head.h"
class Solution {
	public:
		int minimizeTheDifference(vector<vector<int>>& mat, int target) {
			return dp0(mat,target);
			return dp(mat,target);
			return dfs(mat,target);
		}
		int dp0(vector<vector<int> >& mat,int target)
		{
			int r=mat.size(),c=mat[0].size(),res=INT_MAX;
			bitset<4901> pre,cur;
			for(int i=0;i<c;i++)
				pre[mat[0][i]]=1;
			for(int i=1;i<r;i++)
			{
				for(int j=0;j<c;j++)
					cur|=pre<<mat[i][j];
				pre=cur;
				cur=0;
			}
			for(int i=0;i<pre.size();i++)
				if(pre[i]==1)
				res=min(res,abs(i-target));
			return res;
		}
		int dp(vector<vector<int>>& mat, int target) {
			int r=mat.size(),c=mat[0].size(),res=INT_MAX;
			vector<vector<bool>>  d(71,vector<bool> (4901,false));
			dp(mat,target,res,0,0,d);
			return res;	
		}
		void dp(vector<vector<int>>& mat, int target,int &res,int r,int cur,vector<vector<bool>> & d) {
			if(r==mat.size())
			{
				res=min(res,abs(cur-target));
				return;
			}
			if(cur-target>res||d[r][cur])
				return ;
			d[r][cur]=true;
			for(int i=0;i<mat[0].size();i++)
				dp(mat,target,res,r+1,cur+mat[r][i],d);
		}
		int dfs(vector<vector<int>>& mat, int target) {
			int r=mat.size(),c=mat[0].size(),res=INT_MAX;
			dfs(mat,target,res,0,0);
			return res;	
		}
		void dfs(vector<vector<int>>& mat, int target,int &res,int r,int cur) {
			if(r==mat.size())
			{
				res=min(res,abs(cur-target));
				return ;
			}
			for(int i=0;i<mat[0].size();i++)
				dfs(mat,target,res,r+1,cur+mat[r][i]);
		}
};
