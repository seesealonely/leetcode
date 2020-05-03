/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree. 
*/

#include"head.h"

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
       pushLeftAll(root); 
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
       return !st.empty(); 
    }

    /** @return the next smallest number */
    int next() {
       TreeNode *minRight=st.top();
	st.pop();
	pushLeftAll(minRight->right); 
	return minRight->val;
    }
	void pushLeftAll(TreeNode *root)
	{
		for(;root;root=root->left) st.push(root);
	}
stack<TreeNode *> st;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
