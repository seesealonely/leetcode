/*
   You are given a 0-indexed 2D integer array pairs where pairs[i] = [starti, endi]. An arrangement of pairs is valid if for every index i where 1 <= i < pairs.length, we have endi-1 == starti.

   Return any valid arrangement of pairs.

Note: The inputs will be generated such that there exists a valid arrangement of pairs.



Example 1:

Input: pairs = [[5,1],[4,5],[11,9],[9,4]]
Output: [[11,9],[9,4],[4,5],[5,1]]
Explanation:
This is a valid arrangement since endi-1 always equals starti.
end0 = 9 == 9 = start1
end1 = 4 == 4 = start2
end2 = 5 == 5 = start3

Example 2:

Input: pairs = [[1,3],[3,2],[2,1]]
Output: [[1,3],[3,2],[2,1]]
Explanation:
This is a valid arrangement since endi-1 always equals starti.
end0 = 3 == 3 = start1
end1 = 2 == 2 = start2
The arrangements [[2,1],[1,3],[3,2]] and [[3,2],[2,1],[1,3]] are also valid.

Example 3:

Input: pairs = [[1,2],[1,3],[2,1]]
Output: [[1,2],[2,1],[1,3]]
Explanation:
This is a valid arrangement since endi-1 always equals starti.
end0 = 2 == 2 = start1
end1 = 1 == 1 = start2



Constraints:

1 <= pairs.length <= 105
pairs[i].length == 2
0 <= starti, endi <= 109
starti != endi
No two pairs are exactly the same.
There exists a valid arrangement of pairs.

*/


#include"head.h"
class Solution {
	private:
		static  const int N=2e5+5;
		vector<pair<int,int>> g[N];
		int deg[N];
		vector<int> path;
		void dfs(int u,int prev)
		{
			while(!g[u].empty())
			{
				int v=g[u].back().first,e=g[u].back().second;
				g[u].pop_back();
				dfs(v,e);
			}
			if(prev!=-1)
				path.push_back(prev);
		}
	public:
		
		vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
		memset(deg,0,sizeof(N));	
		const int n=pairs.size();

		vector<int> nums;
		for(int i=0;i<n;i++)
		{
			nums.push_back(pairs[i][0]);
			nums.push_back(pairs[i][1]);
		}

		sort(nums.begin(),nums.end());

		const int m=unique(nums.begin(),nums.end())-nums.begin();
		nums.resize(m);

		vector<int> deg(m,0);

		for(int i=0;i<n;i++)
		{
			int u=pairs[i][0],v=pairs[i][1];
			u=lower_bound(nums.begin(),nums.end(),u)-nums.begin();
			v=lower_bound(nums.begin(),nums.end(),v)-nums.begin();
			g[u].push_back({v,i});
			deg[u]++,deg[v]--;
		}

		int start=0;
		for(int i=0;i<m;i++)
			if(deg[i]==1)
			{
				start=i;
				break;
			}

		dfs(start,-1);

		vector<vector<int>>  res;
		for(int i=n-1;i>=0;i--)
			res.push_back({pairs[path[i]][0],pairs[path[i]][1]});

		return res;
		}

};


int main() 
{
	Solution s;
	vector<vector<int>> pairs = {{5,1},{4,5},{11,9},{9,4}};
	show(s.validArrangement(pairs));
	pairs.clear();pairs={{1,3},{3,2},{2,1}};
	show(s.validArrangement(pairs));
	pairs.clear();pairs={{1,2},{1,3},{2,1}};
	show(s.validArrangement(pairs));
	return 0;
}
