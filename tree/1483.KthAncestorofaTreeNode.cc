/*
   You are given a tree with n nodes numbered from 0 to n - 1 in the form of a parent array parent where parent[i] is the parent of ith node. The root of the tree is node 0. Find the kth ancestor of a given node.

   The kth ancestor of a tree node is the kth node in the path from that node to the root node.

   Implement the TreeAncestor class:

   TreeAncestor(int n, int[] parent) Initializes the object with the number of nodes in the tree and the parent array.
   int getKthAncestor(int node, int k) return the kth ancestor of the given node node. If there is no such ancestor, return -1.



   Example 1:

   Input
   ["TreeAncestor", "getKthAncestor", "getKthAncestor", "getKthAncestor"]
   [[7, [-1, 0, 0, 1, 1, 2, 2]], [3, 1], [5, 2], [6, 3]]
   Output
   [null, 1, 0, -1]

   Explanation
   TreeAncestor treeAncestor = new TreeAncestor(7, [-1, 0, 0, 1, 1, 2, 2]);
   treeAncestor.getKthAncestor(3, 1); // returns 1 which is the parent of 3
   treeAncestor.getKthAncestor(5, 2); // returns 0 which is the grandparent of 5
   treeAncestor.getKthAncestor(6, 3); // returns -1 because there is no such ancestor



Constraints:

1 <= k <= n <= 5 * 104
parent.length == n
parent[0] == -1
0 <= parent[i] < n for all 0 < i < n
0 <= node < n
There will be at most 5 * 104 queries.

*/


#include"head.h"
class TreeAncestor {
	public:
		TreeAncestor(int n, vector<int>& parent):p(n,vector<int>(16,-1)) {

			for(int i=0;i<n;i++)
				p[i][0]=parent[i];

			for(int j=1;j<16;j++)
				for(int i=0;i<n;i++)
					if(p[i][j-1]!=-1)
						p[i][j]=p[p[i][j-1]][j-1];
		}

		int getKthAncestor(int node, int k) {
			int res=node;
			for(int i=0;i<16;i++)
				if((k>>i)&1)
				{
					res=p[res][i];
					if(res==-1)
						return res;
				}
			return res;
		}
	private:
		vector<vector<int>> p;
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */

int main() 
{
	vector<int> v={-1, 0, 0, 1, 1, 2, 2};
	TreeAncestor t(7,v);
	cout<<t.getKthAncestor(3,1)<<endl;
	cout<<t.getKthAncestor(5,2)<<endl;
	cout<<t.getKthAncestor(6,3)<<endl;
	return 0;
}
