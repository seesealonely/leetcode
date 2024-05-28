/*
   There exists an infinite number line, with its origin at 0 and extending towards the positive x-axis.

   You are given a 2D array queries, which contains two types of queries:

   For a query of type 1, queries[i] = [1, x]. Build an obstacle at distance x from the origin. It is guaranteed that there is no obstacle at distance x when the query is asked.
   For a query of type 2, queries[i] = [2, x, sz]. Check if it is possible to place a block of size sz anywhere in the range [0, x] on the line, such that the block entirely lies in the range [0, x]. A block cannot be placed if it intersects with any obstacle, but it may touch it. Note that you do not actually place the block. Queries are separate.

   Return a boolean array results, where results[i] is true if you can place the block specified in the ith query of type 2, and false otherwise.



   Example 1:

Input: queries = [[1,2],[2,3,3],[2,3,1],[2,2,2]]

Output: [false,true,true]

Explanation:

For query 0, place an obstacle at x = 2. A block of size at most 2 can be placed before x = 3.

Example 2:

Input: queries = [[1,7],[2,7,6],[1,2],[2,7,5],[2,7,6]]

Output: [true,true,false]

Explanation:

Place an obstacle at x = 7 for query 0. A block of size at most 7 can be placed before x = 7.
Place an obstacle at x = 2 for query 2. Now, a block of size at most 5 can be placed before x = 7, and a block of size at most 2 before x = 2.



Constraints:

1 <= queries.length <= 15 * 104
2 <= queries[i].length <= 3
1 <= queries[i][0] <= 2
1 <= x, sz <= min(5 * 104, 3 * queries.length)
The input is generated such that for queries of type 1, no obstacle exists at distance x when the query is asked.
The input is generated such that there is at least one query of type 2.

*/


#include"head.h"
class Solution {
	public:
		vector<bool> getResults(vector<vector<int>>& queries) {
			set<int> pos;
			pos.insert(0);
			pos.insert(N-1);
			update(N-1,N-1,0,N-1,1);

			vector<bool> res;
			const int q=queries.size();
			for(int i=0;i<q;i++)
			{
				int x=queries[i][0],y=queries[i][1];
				set<int>::iterator it=pos.upper_bound(y);
				int up=*it--;
				int lo=*it;
				if(x==1)
				{
					update(up,up-y,0,N-1,1);
					update(y,y-lo,0,N-1,1);
					pos.insert(y);
				}
				else
					res.push_back(max(y-lo,query(0,lo,0,N-1,1))>=queries[i][2]);
			}
			return res;
		}
	private:
		static const int N=50005;
		int mx[N<<2];
	private:
		int query(int L,int R,int l,int r,int root)
		{
			if(L<=l&&r<=R)
				return mx[root];

			int m=(l+r)>>1,res=0;
			if(L<=m)
				res=max(res,query(L,R,l,m,root<<1));
			if(m<R)
				res=max(res,query(L,R,m+1,r,root<<1|1));
			return res;
		}
		void update(int p,int x,int l,int r,int root)
		{
			if(l==r)
			{
				mx[root]=x;
				return ;
			}
			int m=(l+r)>>1;
			if(p<=m) update(p,x,l,m,root<<1);
			else update(p,x,m+1,r,root<<1|1);
			mx[root]=max(mx[root<<1],mx[root<<1|1]);
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> queries = {{1,2},{2,3,3},{2,3,1},{2,2,2}};
	show(s.getResults(queries));
	queries.clear();
	queries = {{1,7},{2,7,6},{1,2},{2,7,5},{2,7,6}};
	show(s.getResults(queries));
	return 0;
}
