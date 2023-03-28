/*
   You are given a stream of points on the X-Y plane. Design an algorithm that:

   Adds new points from the stream into a data structure. Duplicate points are allowed and should be treated as different points.
   Given a query point, counts the number of ways to choose three points from the data structure such that the three points and the query point form an axis-aligned square with positive area.

   An axis-aligned square is a square whose edges are all the same length and are either parallel or perpendicular to the x-axis and y-axis.

   Implement the DetectSquares class:

   DetectSquares() Initializes the object with an empty data structure.
   void add(int[] point) Adds a new point point = [x, y] to the data structure.
   int count(int[] point) Counts the number of ways to form axis-aligned squares with point point = [x, y] as described above.



   Example 1:

   Input
   ["DetectSquares", "add", "add", "add", "count", "count", "add", "count"]
   [[], [[3, 10]], [[11, 2]], [[3, 2]], [[11, 10]], [[14, 8]], [[11, 2]], [[11, 10]]]
   Output
   [null, null, null, null, 1, 0, null, 2]

   Explanation
   DetectSquares detectSquares = new DetectSquares();
   detectSquares.add([3, 10]);
   detectSquares.add([11, 2]);
   detectSquares.add([3, 2]);
   detectSquares.count([11, 10]); // return 1. You can choose:
				  // - The first, second, and third points
				  detectSquares.count([14, 8]); // return 0. The query point cannot form a square with any points in the data structure.
				  detectSquares.add([11, 2]); // Adding duplicate points is allowed.
				  detectSquares.count([11, 10]); // return 2. You can choose:
								 // - The first, second, and third points
								 // - The first, third, and fourth points



Constraints:

point.length == 2
0 <= x, y <= 1000
At most 3000 calls in total will be made to add and count.

*/


#include"head.h"
const int L = 1001;
const int dx[]={1,1,-1,-1};
const int dy[]={1,-1,1,-1};
class DetectSquares {
	public:
		DetectSquares() {
			memset(node,0,sizeof(node));
		}

		void add(vector<int> point) {
			node[point[0]][point[1]]++;
		}

		int count(vector<int> point) {
			int cx=point[0],cy=point[1];
			int res=0;
			for(int i=0;i<4;i++)
			{
				int x=cx+dx[i],y=cy+dy[i];
				while(x>=0&&x<L&&y>=0&&y<L)
				{
					res+=node[cx][y]*node[x][cy]*node[x][y];
					x+=dx[i];
					y+=dy[i];
				}
			}
			return res;
		}
	private:
		int node[L][L];
};


int main() 
{
	DetectSquares d;
	d.add({3,10});
	d.add({11,2});
	d.add({3,2});
	cout<<d.count({11,10})<<endl;
	cout<<d.count({14,8})<<endl;
	d.add({11,2});
	cout<<d.count({11,10})<<endl;
	return 0;
}
