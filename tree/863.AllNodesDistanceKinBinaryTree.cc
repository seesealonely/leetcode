/*
   Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

   You can return the answer in any order.



   Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.

Example 2:

Input: root = [1], target = 1, k = 3
Output: []



Constraints:

The number of nodes in the tree is in the range [1, 500].
0 <= Node.val <= 500
All the values Node.val are unique.
target is the value of one of the nodes in the tree.
0 <= k <= 1000

*/

#define c11
#include"head.h"
class Solution {
    public:
        vector<int> distanceK(TreeNode* root, /*TreeNode**/ int target, int k) {
            unordered_map<int,vector<int>> graph;
            unordered_map<int,bool> vis;vis[target]=true;
            queue<int> q;q.push(target);
            createGraph(root,-1,graph);

            vector<int> res;
            if(k==0) return {target};
            while(!q.empty())
            {
                int sz = q.size();
                k--;
                for(int i=0;i<sz;i++)
                {
                    int u=q.front();q.pop();
                    for(int j=0;j<graph[u].size();j++)
                    {
                        int v=graph[u][j];
                        if(k==0&&vis[v]==false)
                            res.push_back(v);
                        if(vis[v]==false)
                            q.push(v),vis[v]=true;
                    }
                }
                if(k==0)
                    break;
            }

            return res;
        }
        void createGraph(TreeNode* root,int father,unordered_map<int,vector<int>>& graph)
        {
            if(!root) return;
            int child=root->val;
            if(father!=-1)
            {
                graph[father].push_back(child);
                graph[child].push_back(father);
            }
            createGraph(root->left,child,graph);
            createGraph(root->right,child,graph);
        }
};


int main() 
{
    Solution s;
    show(s.distanceK(buildTree(),5,2));
    return 0;
}
