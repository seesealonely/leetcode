/*
   Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

   Return the smallest level X such that the sum of all the values of nodes at level X is maximal.



   Example 1:

Input: [1,7,0,7,-8,null,null]
Output: 2
Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.



Note:

The number of nodes in the given tree is between 1 and 10^4.
-10^5 <= node.val <= 10^5

*/

#include"head.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
	public:
		int maxLevelSum(TreeNode* root) {
			queue<TreeNode *> qu;
			int res=INT_MIN,level=1,levelres=1;
			qu.push(root);
			while(!qu.empty())
			{
				int tmp=0;
				int size=qu.size();
				for(int i=0;i<size;i++)
				{
					tmp+=qu.front()->val;
					if(qu.front()->left) qu.push(qu.front()->left);
					if(qu.front()->right) qu.push(qu.front()->right);
					qu.pop();
				}
				if(res<tmp)
				{
					res=tmp;
					levelres=level;	
				}
				level++;
			}        
			return levelres;
		}
};
