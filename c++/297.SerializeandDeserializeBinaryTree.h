/*
   Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

   Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

   For example, you may serialize the following tree

   1
   / \
   2   3
   / \
   4   5

   as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless. 
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
class Codec {
	public:

		// Encodes a tree to a single string.
		string serialize(TreeNode* root) {
			ostringstream o;
			encoding(root,o);
			return o.str();
		}

		// Decodes your encoded data to tree.
		TreeNode* deserialize(string data) {
			istringstream i(data);
			return decoding(i);
		}
	private:
		 void encoding(TreeNode *root,ostringstream &o)
		{
			if(root)
			{
				o<<root->val<<' ';
				encoding(root->left,o);
				encoding(root->right,o);
			}
			else o<<"@ ";
		}
		TreeNode *decoding(istringstream &i)
		{
			string s;
			i>>s;
			if(s=="@") return NULL;
			TreeNode *root=new TreeNode(atoi(s.c_str()));
				root->left=decoding(i);
			root->right=decoding(i);
			return root;
		}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
