/*
   Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.



   Example 1:

Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

Example 2:

Input: matrix = [["0"]]
Output: 0

Example 3:

Input: matrix = [["1"]]
Output: 1



Constraints:

rows == matrix.length
cols == matrix[i].length
1 <= row, cols <= 200
matrix[i][j] is '0' or '1'.

*/


#include"head.h"
class Solution {
	public:
		int maximalRectangle(vector<vector<char>>& matrix) {
		if(matrix.size()==0) return 0;

		const int r=matrix.size(),c=matrix.back().size();
		vector<int> heights(c+1,0);
		heights[c]=-1;

		int res=0;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
				heights[j]=matrix[i][j]=='0'?0:heights[j]+1;

			stack<int> st;
			for(int j=0;j<=c;j++)
			{
				while(!st.empty()&&heights[j]<heights[st.top()])
				{
					int cur=st.top();
					st.pop();

					if(st.empty())
						res=max(res,heights[cur]*j);
					else 
						res=max(res,heights[cur]*(j-st.top()-1));
				}
				st.push(j);
			}
		}

		return res;
		}
};


int main() 
{
	Solution s;
	vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
	cout<<s.maximalRectangle(matrix)<<endl;
	matrix.clear();matrix={{'0'}};
	cout<<s.maximalRectangle(matrix)<<endl;
	matrix.clear();matrix={{'1'}};
	cout<<s.maximalRectangle(matrix)<<endl;
	return 0;
}
