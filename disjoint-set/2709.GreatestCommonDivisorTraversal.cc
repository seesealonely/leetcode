/*
   You are given a 0-indexed integer array nums, and you are allowed to traverse between its indices. You can traverse between index i and index j, i != j, if and only if gcd(nums[i], nums[j]) > 1, where gcd is the greatest common divisor.

   Your task is to determine if for every pair of indices i and j in nums, where i < j, there exists a sequence of traversals that can take us from i to j.

   Return true if it is possible to traverse between all such pairs of indices, or false otherwise.



   Example 1:

Input: nums = [2,3,6]
Output: true
Explanation: In this example, there are 3 possible pairs of indices: (0, 1), (0, 2), and (1, 2).
To go from index 0 to index 1, we can use the sequence of traversals 0 -> 2 -> 1, where we move from index 0 to index 2 because gcd(nums[0], nums[2]) = gcd(2, 6) = 2 > 1, and then move from index 2 to index 1 because gcd(nums[2], nums[1]) = gcd(6, 3) = 3 > 1.
To go from index 0 to index 2, we can just go directly because gcd(nums[0], nums[2]) = gcd(2, 6) = 2 > 1. Likewise, to go from index 1 to index 2, we can just go directly because gcd(nums[1], nums[2]) = gcd(3, 6) = 3 > 1.

Example 2:

Input: nums = [3,9,5]
Output: false
Explanation: No sequence of traversals can take us from index 0 to index 2 in this example. So, we return false.

Example 3:

Input: nums = [4,3,12,8]
Output: true
Explanation: There are 6 possible pairs of indices to traverse between: (0, 1), (0, 2), (0, 3), (1, 2), (1, 3), and (2, 3). A valid sequence of traversals exists for each pair, so we return true.



Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 105

*/


#include"head.h"
class Solution {
	public:
		void init(int n)
		{
			p.resize(n);
			for(int i=0;i<n;i++)
				p[i]=i;

		}
		void merge(int x,int y)
		{
			int  px=find(x),py=find(y);
			if(px==py) return ;
			if(px<py)
			p[py]=px;
			else
			p[px]=py;
		}
		int find(int x)
		{
			return p[x]==x?p[x]:find(p[x]);
		}
		bool canTraverseAllPairs(vector<int>& nums) {
			if(nums.size()==1)
				return true;
			int mx=*max_element(nums.begin(),nums.end());

			memset(vis,false,sizeof(vis));

			for(int i=0;i<nums.size();i++)
				vis[nums[i]]=true;
			if(vis[1])
				return false;

			init(mx+1);
			memset(getprimes,false,sizeof(vis));

			for(int i=2;i<=mx;i++)
			{
				if(getprimes[i])
					continue;
				for(int j=i+i;j<=mx;j+=i)
				{
					getprimes[j]=true;
					if(vis[j])
						merge(i,j);
				}
			}

			for(int i=1;i<nums.size();i++)
				if(find(nums[i])!=find(nums[0]))
					return false;

			return true;
		}
	private:
		static const int N=100002;
		vector<int> p;
		bool vis[N],getprimes[N];
};


int main() 
{
	Solution s;
	vector<int> nums = {2,3,6};
	cout<<s.canTraverseAllPairs(nums)<<endl;
	nums.clear();nums={3,9,5};
	cout<<s.canTraverseAllPairs(nums)<<endl;
	nums.clear();nums={4,3,12,8};
	cout<<s.canTraverseAllPairs(nums)<<endl;
	return 0;
}
