/*
   You are given a 2D integer array intervals, where intervals[i] = [lefti, righti] describes the ith interval starting at lefti and ending at righti (inclusive). The size of an interval is defined as the number of integers it contains, or more formally righti - lefti + 1.

   You are also given an integer array queries. The answer to the jth query is the size of the smallest interval i such that lefti <= queries[j] <= righti. If no such interval exists, the answer is -1.

   Return an array containing the answers to the queries.



   Example 1:

Input: intervals = [[1,4],[2,4],[3,6],[4,4]], queries = [2,3,4,5]
Output: [3,3,1,4]
Explanation: The queries are processed as follows:
- Query = 2: The interval [2,4] is the smallest interval containing 2. The answer is 4 - 2 + 1 = 3.
- Query = 3: The interval [2,4] is the smallest interval containing 3. The answer is 4 - 2 + 1 = 3.
- Query = 4: The interval [4,4] is the smallest interval containing 4. The answer is 4 - 4 + 1 = 1.
- Query = 5: The interval [3,6] is the smallest interval containing 5. The answer is 6 - 3 + 1 = 4.

Example 2:

Input: intervals = [[2,3],[2,5],[1,8],[20,25]], queries = [2,19,5,22]
Output: [2,-1,4,6]
Explanation: The queries are processed as follows:
- Query = 2: The interval [2,3] is the smallest interval containing 2. The answer is 3 - 2 + 1 = 2.
- Query = 19: None of the intervals contain 19. The answer is -1.
- Query = 5: The interval [2,5] is the smallest interval containing 5. The answer is 5 - 2 + 1 = 4.
- Query = 22: The interval [20,25] is the smallest interval containing 22. The answer is 25 - 20 + 1 = 6.



Constraints:

1 <= intervals.length <= 105
1 <= queries.length <= 105
intervals[i].length == 2
1 <= lefti <= righti <= 107
1 <= queries[j] <= 107

*/


#include"head.h"
class Solution {
	public:
		static const int N=300002;
		int mn[N<<2];
		int get(int x,const vector<int> &p)
		{
			return lower_bound(p.begin(),p.end(),x)-p.begin()+1;
		}

		void update(int L,int R,int v,int l,int r,int root)
		{
			if(L<=l&&r<=R)
			{
				mn[root]=min(mn[root],v);
				return;
			}
			mn[root<<1]=min(mn[root<<1],mn[root]);
			mn[root<<1|1]=min(mn[root<<1|1],mn[root]);

			int mid=(l+r)>>1;
			if(L<=mid) update(L,R,v,l,mid,root<<1);
			if(mid<R) update(L,R,v,mid+1,r,root<<1|1);
		}
		int query(int p,int l,int r,int root)
		{
			if(l==r)
				return mn[root];

			mn[root<<1]=min(mn[root<<1],mn[root]);
			mn[root<<1|1]=min(mn[root<<1|1],mn[root]);

			int mid=(l+r)>>1;
			if(p<=mid) return query(p,l,mid,root<<1);
			return query(p,mid+1,r,root<<1|1);
		}
		vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
			vector<int> p;
			for(int i=0;i<intervals.size();i++)
			{
				p.push_back(intervals[i][0]);
				p.push_back(intervals[i][1]);
			}

			for(int i=0;i<queries.size();i++)
				p.push_back(queries[i]);

			sort(p.begin(),p.end());
			p.resize(unique(p.begin(),p.end())-p.begin());

			const int n=p.size();

			for(int i=1;i<=(n<<2);i++)
				mn[i]=INT_MAX;

			for(int i=0;i<intervals.size();i++)
			{
				int l=get(intervals[i][0],p),r=get(intervals[i][1],p);
				update(l,r,intervals[i][1]-intervals[i][0]+1,1,n,1);
			}

			const int q=queries.size();
			vector<int> res(q);
			for(int i=0;i<q;i++)
			{
				int cur=get(queries[i],p);
				int f=query(cur,1,n,1);
				res[i]=(f==INT_MAX?-1:f);
			}
			return res;
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> intervals = {{1,4},{2,4},{3,6},{4,4}};
	vector<int>	queries = {2,3,4,5};
	show(s.minInterval(intervals,queries));
	intervals.clear();intervals={{2,3},{2,5},{1,8},{20,25}};
	queries.clear();queries={2,19,5,22};
	show(s.minInterval(intervals,queries));
	return 0;
}
