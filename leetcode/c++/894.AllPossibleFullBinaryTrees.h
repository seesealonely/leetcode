/*
   Given an integer n, return a list of all possible full binary trees with n nodes. Each node of each tree in the answer must have Node.val == 0.

   Each element of the answer is the root node of one possible tree. You may return the final list of trees in any order.

   A full binary tree is a binary tree where each node has exactly 0 or 2 children.



   Example 1:

Input: n = 7
Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]

Example 2:

Input: n = 3
Output: [[0,0,0]]



Constraints:

1 <= n <= 20

*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#define c11
#include"head.h"
class Solution {
	public:
		vector<TreeNode*> allPossibleFBT(int n) {
		unordered_map<int,vector<TreeNode*> > h;
		return dfs(n,h);
		}

		vector<TreeNode*> dfs(int n,unordered_map<int,vector<TreeNode*> > &h) {
			if(n==1) return {new TreeNode(0)};
			if(n==2) return {};
			if(h.count(n)) return h[n];

			vector<TreeNode*> res;

			for(int i=1;i<n;i+=2)
			{
				vector<TreeNode*> l=dfs(i,h),r=dfs(n-i-1,h);
				for(int i=0;i<l.size();i++)
					for(int j=0;j<r.size();j++)
					{
						TreeNode* cur=new TreeNode(0);
						cur->left=l[i];
						cur->right=r[j];
						res.push_back(cur);
					}
			}
			return h[n]=res;
		}
};
