/*
   Given the root of an n-ary tree, return the preorder traversal of its nodes' values.

   Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)



   Example 1:

Input: root = [1,null,3,2,4,null,5,6]
Output: [1,3,5,6,2,4]

Example 2:

Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [1,2,3,6,7,11,14,4,8,12,5,9,13,10]



Constraints:

The number of nodes in the tree is in the range [0, 104].
0 <= Node.val <= 104
The height of the n-ary tree is less than or equal to 1000.



Follow up: Recursive solution is trivial, could you do it iteratively?
/bin /boot /cdrom /dev /etc /home /lib /lib32 /lib64 /libx32 /lost+found /media /mnt /opt /proc /root /run /sbin /snap /srv /swapfile /sys /tmp /usr /var
// Definition for a Node.
*/


#include"head.h"
class Node {
	public:
		int val;
		vector<Node*> children;

		Node() {}

		Node(int _val) {
			val = _val;
		}

		Node(int _val, vector<Node*> _children) {
			val = _val;
			children = _children;
		}
};


class Solution {
	public:
		vector<int> preorder(Node* root) {
		vector<int> res;
		if(!root)
			return res;

		stack<pair<Node *,int>> st;
		st.push(make_pair(root,0));

		while(!st.empty())
		{
			pair<Node *,int> cur=st.top();
			st.pop();

			if(cur.second==0)
				res.push_back(cur.first->val);

			if(cur.second<cur.first->children.size())
				st.push(make_pair(cur.first,cur.second+1)),
				st.push(make_pair(cur.first->children[cur.second],0));
		}
		return res;
		}
};
int main() 
{
	Solution s;
	return 0;
}
