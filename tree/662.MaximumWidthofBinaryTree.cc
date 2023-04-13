/*
   Given the root of a binary tree, return the maximum width of the given tree.

   The maximum width of a tree is the maximum width among all levels.

   The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

   It is guaranteed that the answer will in the range of a 32-bit signed integer.



   Example 1:

Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).

Example 2:

Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).

Example 3:

Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width exists in the second level with length 2 (3,2).



Constraints:

The number of nodes in the tree is in the range [1, 3000].
-100 <= Node.val <= 100

*/


#include"head.h"
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
class Solution {
	public:
		int widthOfBinaryTree(TreeNode* root) {
			typedef long long ll;
			if(!root) return 0;

			vector<pair<TreeNode*,ll>> q;
			q.push_back({root,0});

			ll res=0LL;
			while(!q.empty())
			{
				ll offset=q.front().second;
				for(int i=0;i<q.size();i++)
					q[i].second-=offset;
				res=max(res,q.back().second+1);
				vector<pair<TreeNode*,ll>> s;
				for(int i=0;i<q.size();i++)
				{
					TreeNode *cur=q[i].first;
					ll pos=q[i].second;

					if(cur->left) s.push_back({cur->left,pos<<1});
					if(cur->right) s.push_back({cur->right,pos<<1|1});
				}
				q=s;
			}
			return (int)res;
		}
};


int main() 
{
	Solution s;
	cout<<s.widthOfBinaryTree(buildTree())<<endl;
	return 0;
}
