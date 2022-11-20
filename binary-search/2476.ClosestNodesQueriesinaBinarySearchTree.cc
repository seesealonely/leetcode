/*
   You are given the root of a binary search tree and an array queries of size n consisting of positive integers.

   Find a 2D array answer of size n where answer[i] = [mini, maxi]:

   mini is the largest value in the tree that is smaller than or equal to queries[i]. If a such value does not exist, add -1 instead.
   maxi is the smallest value in the tree that is greater than or equal to queries[i]. If a such value does not exist, add -1 instead.

   Return the array answer.

    

   Example 1:

Input: root = [6,2,13,1,4,9,15,null,null,null,null,null,null,14], queries = [2,5,16]
Output: [[2,2],[4,6],[15,-1]]
Explanation: We answer the queries in the following way:
- The largest number that is smaller or equal than 2 in the tree is 2, and the smallest number that is greater or equal than 2 is still 2. So the answer for the first query is [2,2].
- The largest number that is smaller or equal than 5 in the tree is 4, and the smallest number that is greater or equal than 5 is 6. So the answer for the second query is [4,6].
- The largest number that is smaller or equal than 16 in the tree is 15, and the smallest number that is greater or equal than 16 does not exist. So the answer for the third query is [15,-1].

Example 2:

Input: root = [4,null,9], queries = [3]
Output: [[-1,4]]
Explanation: The largest number that is smaller or equal to 3 in the tree does not exist, and the smallest number that is greater or equal to 3 is 4. So the answer for the query is [-1,4].

 

Constraints:

The number of nodes in the tree is in the range [2, 105].
1 <= Node.val <= 106
n == queries.length
1 <= n <= 105
1 <= queries[i] <= 106

*/


#include"head.h"
class Solution {
    public:
        vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> array;
        getNoDecreasing(root,array);
        
        vector<vector<int>> res;
        for(int i=0;i<queries.size();i++)
        {
            int x=queries[i];
            vector<int> cur={-1,-1};
            vector<int>::iterator l=upper_bound(array.begin(),array.end(),x);
            if(l!=array.begin())
                cur[0]=*--l;

            vector<int>::iterator r=lower_bound(array.begin(),array.end(),x);
            if(r!=array.end())
                cur[1]=*r;

            res.push_back(cur);
        }
        return res;
        }
        void getNoDecreasing(TreeNode *root,vector<int> &res)
        {
            if(!root) return ;
            getNoDecreasing(root->left,res);
            res.push_back(root->val);
            getNoDecreasing(root->right,res);
        }
};


int main() 
{
    Solution s;
    vector<int> q={2,5,16};
    show(s.closestNodes(buildTree(),q));
    return 0;
}
