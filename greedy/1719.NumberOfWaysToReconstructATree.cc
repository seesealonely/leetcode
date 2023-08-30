/*
   You are given an array pairs, where pairs[i] = [xi, yi], and:

   There are no duplicates.
   xi < yi

   Let ways be the number of rooted trees that satisfy the following conditions:

   The tree consists of nodes whose values appeared in pairs.
   A pair [xi, yi] exists in pairs if and only if xi is an ancestor of yi or yi is an ancestor of xi.
Note: the tree does not have to be a binary tree.

Two ways are considered to be different if there is at least one node that has different parents in both ways.

Return:

0 if ways == 0
1 if ways == 1
2 if ways > 1

A rooted tree is a tree that has a single root node, and all edges are oriented to be outgoing from the root.

An ancestor of a node is any node on the path from the root to that node (excluding the node itself). The root has no ancestors.



Example 1:

Input: pairs = [[1,2],[2,3]]
Output: 1
Explanation: There is exactly one valid rooted tree, which is shown in the above figure.

Example 2:

Input: pairs = [[1,2],[2,3],[1,3]]
Output: 2
Explanation: There are multiple valid rooted trees. Three of them are shown in the above figures.

Example 3:

Input: pairs = [[1,2],[2,3],[2,4],[1,5]]
Output: 0
Explanation: There are no valid rooted trees.



Constraints:

1 <= pairs.length <= 105
1 <= xi < yi <= 500
The elements in pairs are unique.

*/

#define c11
#include"head.h"
class Solution {
	public:
		const int N=505;
		int checkWays(vector<vector<int>>& pairs) {
			bool map[N][N];
			int deg[N];
			memset(deg,0,sizeof(deg));	
			memset(map,false,sizeof(map));	

			unordered_set<int> s;
			for(int i=0;i<pairs.size();i++)
			{
				int x=pairs[i][0],y=pairs[i][1];
				map[x][y]=map[y][x]=true;
				deg[x]++;
				deg[y]++;
				s.insert(x);
				s.insert(y);
			}
			vector<int> v;
			for(unordered_set<int>::iterator it=s.begin();it!=s.end();it++)
				v.push_back(*it);

			sort(v.begin(),v.end(),[&](int x,int y)
					{
					return deg[x]>deg[y];
					});
			int pa[N];
			memset(pa,-1,sizeof(pa));
			for(int i=1;i<v.size();i++)
			{
				for(int j=i-1;j>=0;j--)
					if(map[v[j]][v[i]])
					{
						pa[v[i]]=v[j];
						break;
					}
				if(pa[v[i]]==-1)
					return 0;
			}

			int count=0;
			for(int i=0;i<v.size();i++)
			{
				int j=v[i];
				while(pa[j]!=-1)
				{
					if(!map[j][pa[j]])
						return 0;
					count++;
					j=pa[j];
				}
			}

			if(count!=pairs.size())
				return 0;
			for(int i=0;i<pairs.size();i++)
				if(deg[pairs[i][0]]==deg[pairs[i][1]])
					return 2;
			return 1;
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> pairs={{1,2},{2,3}};
	cout<<s.checkWays(pairs)<<endl;
	pairs.clear();pairs={{1,2},{2,3},{1,3}};
	cout<<s.checkWays(pairs)<<endl;
	pairs.clear();pairs={{1,2},{2,3},{2,4},{1,5}};
	cout<<s.checkWays(pairs)<<endl;
	return 0;
}
