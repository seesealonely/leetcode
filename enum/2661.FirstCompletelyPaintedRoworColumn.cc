/*
   You are given a 0-indexed integer array arr, and an m x n integer matrix mat. arr and mat both contain all the integers in the range [1, m * n].

   Go through each index i in arr starting from index 0 and paint the cell in mat containing the integer arr[i].

   Return the smallest index i at which either a row or a column will be completely painted in mat.



   Example 1:
   image explanation for example 1

Input: arr = [1,3,4,2], mat = [[1,4],[2,3]]
Output: 2
Explanation: The moves are shown in order, and both the first row and second column of the matrix become fully painted at arr[2].

Example 2:
image explanation for example 2

Input: arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
Output: 3
Explanation: The second column becomes fully painted at arr[3].



Constraints:

m == mat.length
n = mat[i].length
arr.length == m * n
1 <= m, n <= 105
1 <= m * n <= 105
1 <= arr[i], mat[r][c] <= m * n
All the integers of arr are unique.
All the integers of mat are unique.

*/


#include"head.h"
class Solution {
	public:
		int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
		const int r=mat.size(),c=mat.front().size();

		vector<pair<int,int>> idx(r*c+1);
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				idx[mat[i][j]]={i,j};

		vector<int> row(r,0),col(c,0);
		for(int i=0;i<r*c;i++)
		{
			int key=arr[i];

			int x=idx[key].first,y=idx[key].second;
			if(++row[x]==c||++col[y]==r) return i;
		}
		return 0;
		}
};


int main() 
{
	Solution s;
	vector<int> arr={1,3,4,2};
	vector<vector<int>> mat={{1,4},{2,3}};
	cout<<s.firstCompleteIndex(arr,mat)<<endl;
	arr.clear();arr={2,8,7,4,1,3,5,6,9};
	mat.clear();mat={{3,2,5},{1,4,6},{8,7,9}};
	cout<<s.firstCompleteIndex(arr,mat)<<endl;
	arr.clear();arr={1,4,5,2,6,3};
	mat.clear();mat={{4,3,5},{1,2,6}};
	cout<<s.firstCompleteIndex(arr,mat)<<endl;
	return 0;
}
