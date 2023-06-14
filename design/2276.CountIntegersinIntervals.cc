/*
   Given an empty set of intervals, implement a data structure that can:

   Add an interval to the set of intervals.
   Count the number of integers that are present in at least one interval.

   Implement the CountIntervals class:

   CountIntervals() Initializes the object with an empty set of intervals.
   void add(int left, int right) Adds the interval [left, right] to the set of intervals.
   int count() Returns the number of integers that are present in at least one interval.

   Note that an interval [left, right] denotes all the integers x where left <= x <= right.



   Example 1:

   Input
   ["CountIntervals", "add", "add", "count", "add", "count"]
   [[], [2, 3], [7, 10], [], [5, 8], []]
   Output
   [null, null, null, 6, null, 8]

   Explanation
   CountIntervals countIntervals = new CountIntervals(); // initialize the object with an empty set of intervals.
   countIntervals.add(2, 3); // add [2, 3] to the set of intervals.
   countIntervals.add(7, 10); // add [7, 10] to the set of intervals.
   countIntervals.count(); // return 6
			   // the integers 2 and 3 are present in the interval [2, 3].
			   // the integers 7, 8, 9, and 10 are present in the interval [7, 10].
			   countIntervals.add(5, 8); // add [5, 8] to the set of intervals.
			   countIntervals.count(); // return 8
						   // the integers 2 and 3 are present in the interval [2, 3].
						   // the integers 5 and 6 are present in the interval [5, 8].
						   // the integers 7 and 8 are present in the intervals [5, 8] and [7, 10].
						   // the integers 9 and 10 are present in the interval [7, 10].



Constraints:

1 <= left <= right <= 109
At most 105 calls in total will be made to add and count.
At least one call will be made to count.

*/


#include"head.h"
const int N=1e9;
class Node
{
	public:
		int ls,rs;
		int sum;
		bool add;
		Node()
		{
			ls=rs=sum=0;
			add=false;
		}
};

class CountIntervals {
	public:
		vector<Node> tree;
		int cnt;
		CountIntervals() {
		tree.resize(1);
		tree.push_back(Node());
		cnt=1;
		}

		void pushdown(int u,int len)
		{
			if(!tree[u].add)
				return ;
			int l=tree[u].ls,r=tree[u].rs;
			tree[l].add=tree[r].add=true;
			tree[l].sum=len-(len>>1);
			tree[r].sum=len>>1;
			tree[u].add=false;
		}
		void pushup(int u)
		{
			tree[u].sum=tree[tree[u].ls].sum+tree[tree[u].rs].sum;
		}
		void update(int L,int R,int c,int l,int r,int u)
		{
			if(L<=l&&r<=R)
			{
				tree[u].add=true;
				tree[u].sum=r-l+1;
				return;
			}
			if(tree[u].ls==0)
			{
				tree.push_back(Node());
				tree[u].ls=++cnt;
			}
			if(tree[u].rs==0)
			{
				tree.push_back(Node());
				tree[u].rs=++cnt;
			}
			pushdown(u,r-l+1);

			int mid=(l+r)>>1;
			if(L<=mid) update(L,R,c,l,mid,tree[u].ls);
			if(mid<R) update(L,R,c,mid+1,r,tree[u].rs);

			pushup(u);
		}
		void add(int left, int right) {
		update(left,right,1,1,N,1);
		}

		int count() {
			return tree[1].sum;
		}
};


int main() 
{
	CountIntervals countIntervals = CountIntervals(); // initialize the object with an empty set of intervals.
countIntervals.add(2, 3);  // add [2, 3] to the set of intervals.
countIntervals.add(7, 10); // add [7, 10] to the set of intervals.
countIntervals.count();    // return 6
                           // the integers 2 and 3 are present in the interval [2, 3].
                           // the integers 7, 8, 9, and 10 are present in the interval [7, 10].
countIntervals.add(5, 8);  // add [5, 8] to the set of intervals.
countIntervals.count();    // return 8
                           // the integers 2 and 3 are present in the interval [2, 3].
                           // the integers 5 and 6 are present in the interval [5, 8].
                           // the integers 7 and 8 are present in the intervals [5, 8] and [7, 10].
                           // the integers 9 and 10 are present in the interval [7, 10].
	return 0;
}
