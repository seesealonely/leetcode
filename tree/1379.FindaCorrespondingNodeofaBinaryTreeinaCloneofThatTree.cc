/*
   Given two binary trees original and cloned and given a reference to a node target in the original tree.

   The cloned tree is a copy of the original tree.

   Return a reference to the same node in the cloned tree.

   Note that you are not allowed to change any of the two trees or the target node and the answer must be a reference to a node in the cloned tree.



   Example 1:

Input: tree = [7,4,3,null,null,6,19], target = 3
Output: 3
Explanation: In all examples the original and cloned trees are shown. The target node is a green node from the original tree. The answer is the yellow node from the cloned tree.

Example 2:

Input: tree = [7], target = 7
Output: 7

Example 3:

Input: tree = [8,null,6,null,5,null,4,null,3,null,2,null,1], target = 4
Output: 4



Constraints:

The number of nodes in the tree is in the range [1, 104].
The values of the nodes of the tree are unique.
target node is a node from the original tree and is not null.



Follow up: Could you solve the problem if repeated values on the tree are allowed?

*/


#include"head.h"
class Solution {
	public:
		TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
		TreeNode *res;
		res=NULL;
		dfs(original,cloned,target,res);
		return res;

		}
		void dfs(TreeNode* o,TreeNode *c,TreeNode *t,TreeNode *&res)
		{
			if(!o) return;

			if(o==t)
			{
				res=c;
				return ;
			}
			dfs(o->left,c->left,t,res);
			if(!res) dfs(o->right,c->right,t,res);
		}
};


int main() 
{
	Solution s;
	TreeNode *t=new TreeNode(3);
	cout<<s.getTargetCopy(buildTree(),buildTree(),t)<<endl;
	return 0;
}
