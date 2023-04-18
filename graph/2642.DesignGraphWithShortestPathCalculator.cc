/*
   There is a directed weighted graph that consists of n nodes numbered from 0 to n - 1. The edges of the graph are initially represented by the given array edges where edges[i] = [fromi, toi, edgeCosti] meaning that there is an edge from fromi to toi with the cost edgeCosti.

   Implement the Graph class:

   Graph(int n, int[][] edges) initializes the object with n nodes and the given edges.
   addEdge(int[] edge) adds an edge to the list of edges where edge = [from, to, edgeCost]. It is guaranteed that there is no edge between the two nodes before adding this one.
   int shortestPath(int node1, int node2) returns the minimum cost of a path from node1 to node2. If no path exists, return -1. The cost of a path is the sum of the costs of the edges in the path.



   Example 1:

   Input
   ["Graph", "shortestPath", "shortestPath", "addEdge", "shortestPath"]
   [[4, [[0, 2, 5], [0, 1, 2], [1, 2, 1], [3, 0, 3]]], [3, 2], [0, 3], [[1, 3, 4]], [0, 3]]
   Output
   [null, 6, -1, null, 6]

   Explanation
   Graph g = new Graph(4, [[0, 2, 5], [0, 1, 2], [1, 2, 1], [3, 0, 3]]);
   g.shortestPath(3, 2); // return 6. The shortest path from 3 to 2 in the first diagram above is 3 -> 0 -> 1 -> 2 with a total cost of 3 + 2 + 1 = 6.
   g.shortestPath(0, 3); // return -1. There is no path from 0 to 3.
   g.addEdge([1, 3, 4]); // We add an edge from node 1 to node 3, and we get the second diagram above.
   g.shortestPath(0, 3); // return 6. The shortest path from 0 to 3 now is 0 -> 1 -> 3 with a total cost of 2 + 4 = 6.



Constraints:

1 <= n <= 100
0 <= edges.length <= n * (n - 1)
edges[i].length == edge.length == 3
0 <= fromi, toi, from, to, node1, node2 <= n - 1
1 <= edgeCosti, edgeCost <= 106
There are no repeated edges and no self-loops in the graph at any point.
At most 100 calls will be made for addEdge.
At most 100 calls will be made for shortestPath.

*/


#include"head.h"
class Graph {
	public:
		static const int INF=1e9;
		int n;
		vector<vector<int>> g;
		Graph(int n, vector<vector<int>>& edges) {
			this->n=n;
			g.resize(n,vector<int>(n,INF));

			for(int i=0;i<edges.size();i++)
				g[edges[i][0]][edges[i][1]]=edges[i][2];
		}

		void addEdge(vector<int> edge) {
			g[edge[0]][edge[1]]=edge[2];
		}

		int shortestPath(int node1, int node2) {
			vector<int> d(n,INF);
			vector<bool> vis(n,false);

			d[node1]=0;

			for(int i=0;i<n;i++)
			{
				int mx=INF,idx=-1;
				for(int j=0;j<n;j++)
					if(!vis[j]&&mx>d[j])
					{
						mx=d[j];
						idx=j;
					}
				if(mx==INF)
					break;
				vis[idx]=true;

				for(int j=0;j<n;j++)
					d[j]=min(d[j],d[idx]+g[idx][j]);
			}

			if(d[node2]==INF)
				return -1;

			return d[node2];
		}
};


int main() 
{
	vector<vector<int>> v={{0, 2, 5}, {0, 1, 2}, {1, 2, 1}, {3, 0, 3}};
	Graph g = Graph(4, v);
	cout<<g.shortestPath(3, 2)<<endl; // return 6. The shortest path from 3 to 2 in the first diagram above is 3 -> 0 -> 1 -> 2 with a total cost of 3 + 2 + 1 = 6.
	cout<<g.shortestPath(0, 3)<<endl; // return -1. There is no path from 0 to 3.

	//g.addEdge({1, 3, 4}); // We add an edge from node 1 to node 3, and we get the second diagram above.
	cout<<g.shortestPath(0, 3)<<endl; // return 6. The shortest path from 0 to 3 now is 0 -> 1 -> 3 with a total cost of 2 + 4 = 6.
	return 0;
}
