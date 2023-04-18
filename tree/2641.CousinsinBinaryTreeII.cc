/*
   Given the root of a binary tree, replace the value of each node in the tree with the sum of all its cousins' values.

   Two nodes of a binary tree are cousins if they have the same depth with different parents.

   Return the root of the modified tree.

   Note that the depth of a node is the number of edges in the path from the root node to it.



   Example 1:

Input: root = [5,4,9,1,10,null,7]
Output: [0,0,0,7,7,null,11]
Explanation: The diagram above shows the initial binary tree and the binary tree after changing the value of each node.
- Node with value 5 does not have any cousins so its sum is 0.
- Node with value 4 does not have any cousins so its sum is 0.
- Node with value 9 does not have any cousins so its sum is 0.
- Node with value 1 has a cousin with value 7 so its sum is 7.
- Node with value 10 has a cousin with value 7 so its sum is 7.
- Node with value 7 has cousins with values 1 and 10 so its sum is 11.

Example 2:

Input: root = [3,1,2]
Output: [0,0,0]
Explanation: The diagram above shows the initial binary tree and the binary tree after changing the value of each node.
- Node with value 3 does not have any cousins so its sum is 0.
- Node with value 1 does not have any cousins so its sum is 0.
- Node with value 2 does not have any cousins so its sum is 0.



Constraints:

The number of nodes in the tree is in the range [1, 105].
1 <= Node.val <= 104

*/


#include"head.h"
class Solution {
	public:
		TreeNode* replaceValueInTree(TreeNode* root) {
			vector<TreeNode*> q1,q2;
			q1.push_back(root);
			root->val=0;
			while(!q1.empty())
			{
				int sum=0;
				for(int i=0;i<q1.size();i++)
				{
					if(q1[i]->left)
					{
						sum+=q1[i]->left->val;
						q2.push_back(q1[i]->left);
					}
					if(q1[i]->right)
					{
						sum+=q1[i]->right->val;
						q2.push_back(q1[i]->right);
					}
				}

				for(int i=0;i<q1.size();i++)
				{
					int r=sum;
					if(q1[i]->left) r-=q1[i]->left->val;
					if(q1[i]->right) r-=q1[i]->right->val;

					if(q1[i]->left) q1[i]->left->val=r;
					if(q1[i]->right) q1[i]->right->val=r;
				}
				q1=q2;
				q2.clear();
			}
			return root;
		}
};


int main() 
{
	Solution s;
	show(s.replaceValueInTree(buildTree()));
	return 0;
}
