/*
   You are given two 0-indexed arrays nums1 and nums2 and a 2D array queries of queries. There are three types of queries:

   For a query of type 1, queries[i] = [1, l, r]. Flip the values from 0 to 1 and from 1 to 0 in nums1 from index l to index r. Both l and r are 0-indexed.
   For a query of type 2, queries[i] = [2, p, 0]. For every index 0 <= i < n, set nums2[i] = nums2[i] + nums1[i] * p.
   For a query of type 3, queries[i] = [3, 0, 0]. Find the sum of the elements in nums2.

   Return an array containing all the answers to the third type queries.



   Example 1:

Input: nums1 = [1,0,1], nums2 = [0,0,0], queries = [[1,1,1],[2,1,0],[3,0,0]]
Output: [3]
Explanation: After the first query nums1 becomes [1,1,1]. After the second query, nums2 becomes [1,1,1], so the answer to the third query is 3. Thus, [3] is returned.

Example 2:

Input: nums1 = [1], nums2 = [5], queries = [[2,0,0],[3,0,0]]
Output: [5]
Explanation: After the first query, nums2 remains [5], so the answer to the second query is 5. Thus, [5] is returned.



Constraints:

1 <= nums1.length,nums2.length <= 105
nums1.length = nums2.length
1 <= queries.length <= 105
queries[i].length = 3
0 <= l <= r <= nums1.length - 1
0 <= p <= 106
0 <= nums1[i] <= 1
0 <= nums2[i] <= 109

*/


#include"head.h"
#define ll long long
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
class Solution {
	private:
		static const int N=100010;
		int sum[N<<2],lazy[N<<2];
		void build(int l,int r,int rt,const vector<int> &nums)
		{
			if(l==r)
			{
				sum[rt]=nums[l];
				return ;
			}
			int mid=(l+r)>>1;
			build(lson,nums);
			build(rson,nums);
			sum[rt]=sum[rt<<1]+sum[rt<<1|1];
		}
		void modify(int L,int R,int l,int r,int rt)
		{
			if(L<=l&&r<=R)
			{
				lazy[rt]^=1;
				sum[rt]=r-l+1-sum[rt];
				return;
			}
			pushdown(r-l+1,rt);
			int mid=(l+r)>>1;
			if(L<=mid) modify(L,R,lson);
			if(mid<R) modify(L,R,rson);
			sum[rt]=sum[rt<<1]+sum[rt<<1|1];
		}
		void pushdown(int len,int rt)
		{
			if(lazy[rt]==0)
				return;
			int ls=rt<<1,rs=rt<<1|1;
			lazy[ls]^=1,lazy[rs]^=1;
			sum[ls]=len-(len>>1)-sum[ls];
			sum[rs]=(len>>1)-sum[rs];
			lazy[rt]=0;
		}
	public:
		vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
		const int n=nums1.size();
		build(0,n-1,1,nums1);
		ll s=accumulate(nums2.begin(),nums2.end(),0LL);

		vector<ll> res;
		for(int i=0;i<queries.size();i++)
		{
			int t=queries[i][0];
			if(t==1) modify(queries[i][1],queries[i][2],0,n-1,1);
			else if(t==2) s+=(ll)sum[1]*queries[i][1];
			else res.push_back(s);
		}

		return res;
		}
};


int main() 
{
	Solution s;
	vector<int> nums1={1,0,1},nums2={0,0,0};
	vector<vector<int>> queries={{1,1,1},{2,1,0},{3,0,0}};
	show(s.handleQuery(nums1,nums2,queries));
	nums1.clear();nums1={1};
	nums2.clear();nums2={5};
	queries.clear();queries={{2,0,0},{3,0,0}};
	show(s.handleQuery(nums1,nums2,queries));
	return 0;
}
