/*
   Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

   Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.

   The encoded string should be as compact as possible.

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
		istringstream is(data);
		string s;
		while(is>>s) 
		v.push_back(atoi(s.c_str()));
		return	decoding(v.begin(),v.end()); 
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
		}
		TreeNode *decoding(vector<int>::iterator begin,vector<int>::iterator end)
		{
			if(begin==end) return NULL;
			TreeNode *root=new TreeNode (*begin);
			vector<int>::iterator i=lower_bound(begin+1,end,*begin);
			root->left=decoding(begin+1,i);
			root->right=decoding(i,end);
			return root;
		}
private:

		vector<int> v;
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
