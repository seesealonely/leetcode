/*
   Given an m x n matrix, return a new matrix answer where answer[row][col] is the rank of matrix[row][col].

   The rank is an integer that represents how large an element is compared to other elements. It is calculated using the following rules:

   The rank is an integer starting from 1.
   If two elements p and q are in the same row or column, then:
   If p < q then rank(p) < rank(q)
   If p == q then rank(p) == rank(q)
   If p > q then rank(p) > rank(q)
   The rank should be as small as possible.

   The test cases are generated so that answer is unique under the given rules.



   Example 1:

Input: matrix = [[1,2],[3,4]]
Output: [[1,2],[2,3]]
Explanation:
The rank of matrix[0][0] is 1 because it is the smallest integer in its row and column.
The rank of matrix[0][1] is 2 because matrix[0][1] > matrix[0][0] and matrix[0][0] is rank 1.
The rank of matrix[1][0] is 2 because matrix[1][0] > matrix[0][0] and matrix[0][0] is rank 1.
The rank of matrix[1][1] is 3 because matrix[1][1] > matrix[0][1], matrix[1][1] > matrix[1][0], and both matrix[0][1] and matrix[1][0] are rank 2.

Example 2:

Input: matrix = [[7,7],[7,7]]
Output: [[1,1],[1,1]]

Example 3:

Input: matrix = [[20,-21,14],[-19,4,19],[22,-47,24],[-19,4,19]]
Output: [[4,2,3],[1,3,4],[5,1,6],[1,3,4]]



Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 500
-109 <= matrix[row][col] <= 109

*/

#define c11
#include"head.h"
class UF
{
	public:
		UF(int n)
		{
			p.resize(n);
			size.resize(n);
			for(int i=0;i<n;i++)
				p[i]=i,size[i]=1;
		}
		int find(int x)
		{
			return p[x]==x?p[x]:find(p[x]);
		}
		void merge(int x,int y)
		{
			int px=find(x),py=find(y);
			if(px==py) return ;
			if(size[px]<size[py])
				p[px]=py,size[py]+=size[px];
			else
				p[py]=px,size[px]+=size[py];
		}
		void reset(int x)
		{
			p[x]=x;
			size[x]=1;
		}
	public: 
		vector<int> p,size;
};
class Solution {
	public:
		vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
			const int r=matrix.size(),c=matrix.back().size();

			unordered_map<int,vector<pair<int,int>>> idx;
			vector<int> sorted;
			for(int i=0;i<r;i++)
				for(int j=0;j<c;j++)
				{
					idx[matrix[i][j]].push_back({i,j});
					sorted.push_back(matrix[i][j]);
				}


			sort(sorted.begin(),sorted.end());
			vector<int>::iterator last=unique(sorted.begin(),sorted.end());
			sorted.erase(last,sorted.end());

			UF uf(r+c);
			vector<vector<int>> res(r,vector<int>(c));
			vector<int> row(r,0),col(c,0),rank(r+c,0);
			for(int i=0;i<sorted.size();i++)
			{
				vector<pair<int,int>> mn=idx[sorted[i]];
				for(int j=0;j<mn.size();j++)
				{
					int x=mn[j].first,y=mn[j].second;
					uf.merge(x,r+y);
				}

				for(int j=0;j<mn.size();j++)
				{
					int x=mn[j].first,y=mn[j].second;
					rank[uf.find(x)]=max(rank[uf.find(x)],max(row[x],col[y]));
				}

				for(int j=0;j<mn.size();j++)
				{
					int x=mn[j].first,y=mn[j].second;
					res[x][y]=row[x]=col[y]=1+rank[uf.find(x)];
				}
				
				for(int j=0;j<mn.size();j++)
				{
					int x=mn[j].first,y=mn[j].second;
					uf.reset(x);
					uf.reset(r+y);
				}
			}
			return res;
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> matrix={{1,2},{3,4}};
	show(s.matrixRankTransform(matrix));
	matrix.clear();matrix={{7,7},{7,7}};
	show(s.matrixRankTransform(matrix));
	matrix.clear();matrix={{20,-21,14},{-19,4,19},{22,-47,24},{-19,4,19}};
	show(s.matrixRankTransform(matrix));
	return 0;
}
