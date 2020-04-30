/*Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include"head.h"
class Solution {
public:
Solution(int minnp,int prevp):minn(minnp),prev(prevp){}
    int getMinimumDifference(TreeNode* root) {
	return usingStack(root);
    }
    int usingStack(TreeNode* root) {
	if(!root) return 0;
	stack<TreeNode*> st;
	TreeNode *pre=NULL;
	int res=INT_MAX;
	while(root||!st.empty())
	{
		while(root)
		{
			st.push(root);
			root=root->left;
		}
		TreeNode *top=st.top();
		st.pop();
		if(pre) res=min(res,top->val-pre->val);	
		pre=top;
		root=top->right;
	}
	return res;
    }
/*	int dfs(TreeNode *root)
	{
       if(!root) return minn; 
	getMinimumDifference(root->left);
	prev==NULL?prev=root->val:minn=min(minn,root->val-prev);
	getMinimumDifference(root->right);
	return minn;
	}
*/
private:
	int minn;int prev;
};
