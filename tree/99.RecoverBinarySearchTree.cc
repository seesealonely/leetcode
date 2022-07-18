/*
   You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.



   Example 1:

Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.

Example 2:

Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.



Constraints:

The number of nodes in the tree is in the range [2, 1000].
-231 <= Node.val <= 231 - 1
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
#include"head.h"
class Solution {
    public:
        void recoverTree(TreeNode* root) {
        vector<TreeNode*> t;
        inorder(root,t);
        TreeNode *one=NULL,*two=NULL;
        for(int i=0;i<t.size()-1;i++)
            if(t[i]->val>t[i+1]->val)
            {
                two=t[i+1];
                if(one==NULL)
                    one=t[i];
            }
        swap(one->val,two->val);
        }
        void inorder(TreeNode* root,vector<TreeNode*> &t)
        {
            if(!root)
                return ;
            inorder(root->left,t);
            t.push_back(root);
            inorder(root->right,t);
        }
};


int main() 
{
    Solution s;
    TreeNode* r=buildTree();
    s.recoverTree(r);
    show(r);
    return 0;
}
