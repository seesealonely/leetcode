/*
   You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.

   Each minute, a node becomes infected if:

   The node is currently uninfected.
   The node is adjacent to an infected node.

   Return the number of minutes needed for the entire tree to be infected.



   Example 1:

Input: root = [1,5,3,null,4,10,6,9,2], start = 3
Output: 4
Explanation: The following nodes are infected during:
- Minute 0: Node 3
- Minute 1: Nodes 1, 10 and 6
- Minute 2: Node 5
- Minute 3: Node 4
- Minute 4: Nodes 9 and 2
It takes 4 minutes for the whole tree to be infected so we return 4.

Example 2:

Input: root = [1], start = 1
Output: 0
Explanation: At minute 0, the only node in the tree is infected so we return 0.



Constraints:

The number of nodes in the tree is in the range [1, 105].
1 <= Node.val <= 105
Each node has a unique value.
A node with a value of start exists in the tree.

*/

#define c11
#include"head.h"
class Solution {
    public:
        int amountOfTime(TreeNode* root, int start) {
            unordered_map<int,vector<int>> graph;
            unordered_map<int,bool> vis;vis[start]=true;
            queue<int> q;q.push(start);
            createGraph(root,-1,graph);

            int res=0;
            while(!q.empty())
            {
                int sz = q.size();
                for(int i=0;i<sz;i++)
                {
                    int u=q.front();q.pop();
                    for(int j=0;j<graph[u].size();j++)
                    {
                        int v=graph[u][j];
                        if(vis[v]==false)
                            q.push(v),vis[v]=true;
                    }
                }
                res++;
            }
            return res-1;

        }
        void createGraph(TreeNode* root,int father,unordered_map<int,vector<int>>&graph)
        {
            if(!root) return;
            int child=root->val;
            if(father!=-1)
            {
                graph[father].push_back(child);
                graph[child].push_back(father);
            }
            createGraph(root->left,root->val,graph);
            createGraph(root->right,root->val,graph);
        }
};


int main() 
{
    Solution s;
    cout<<s.amountOfTime(buildTree(),3)<<endl;
    return 0;
}
