/*
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Input: [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
*/
#include"head.h"
class Solution {
public:
struct node
{
	struct node *l,*r;
	int lessroot;
	int val;	
	node(int v,int l):val(v),lessroot(l),r(NULL),l(NULL){}
};
int insert(struct node* &root,int cur)
{
	if(!root) return (root=new node(cur,0)),0;
	if(root->val>cur) return root->lessroot++,insert(root->l,cur);
	return insert(root->r,cur)+root->lessroot+(root->val<cur?1:0);
}
	
vector<int> countSmaller(vector<int>& nums) {
	vector<int> res(nums.size());
	struct node *root=NULL;
	for(int i=nums.size()-1;i>=0;i--)
	{
		res[i]=insert(root,nums[i]);
	}
	return res;
}
};
