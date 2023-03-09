/*
   You are given the root of a binary tree and a positive integer k.

   The level sum in the tree is the sum of the values of the nodes that are on the same level.

   Return the kth largest level sum in the tree (not necessarily distinct). If there are fewer than k levels in the tree, return -1.

   Note that two nodes are on the same level if they have the same distance from the root.



   Example 1:

Input: root = [5,8,9,2,1,3,7,4,6], k = 2
Output: 13
Explanation: The level sums are the following:
- Level 1: 5.
- Level 2: 8 + 9 = 17.
- Level 3: 2 + 1 + 3 + 7 = 13.
- Level 4: 4 + 6 = 10.
The 2nd largest level sum is 13.

Example 2:

Input: root = [1,2,null,3], k = 1
Output: 3
Explanation: The largest level sum is 3.



Constraints:

The number of nodes in the tree is n.
2 <= n <= 105
1 <= Node.val <= 106
1 <= k <= n

*/


#include"head.h"
class Solution {
	public:
		long long kthLargestLevelSum(TreeNode* root, int k) {
		priority_queue<long long,vector<long long>,greater<long long>> pq;

		vector<TreeNode *> c1;
		c1.push_back(root);

		while(!c1.empty())
		{
			vector<TreeNode*> c2;
			long long sum=0;
			for(int i=0;i<c1.size();i++)
			{
				sum+=c1[i]->val;
				if(c1[i]->left) c2.push_back(c1[i]->left);
				if(c1[i]->right) c2.push_back(c1[i]->right);
			}

			pq.push(sum);
			if(pq.size()>k)
				pq.pop();
			c1=c2;
		}

		if(pq.size()<k)
			return -1;

		return pq.top();
		}
};


int main() 
{
	Solution s;
	cout<<s.kthLargestLevelSum(buildTree(),1)<<endl;
	return 0;
}
