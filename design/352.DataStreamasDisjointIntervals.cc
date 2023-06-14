/*
   Given a data stream input of non-negative integers a1, a2, ..., an, summarize the numbers seen so far as a list of disjoint intervals.

   Implement the SummaryRanges class:

   SummaryRanges() Initializes the object with an empty stream.
   void addNum(int value) Adds the integer value to the stream.
   int[][] getIntervals() Returns a summary of the integers in the stream currently as a list of disjoint intervals [starti, endi]. The answer should be sorted by starti.



   Example 1:

   Input
   ["SummaryRanges", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals"]
   [[], [1], [], [3], [], [7], [], [2], [], [6], []]
   Output
   [null, null, [[1, 1]], null, [[1, 1], [3, 3]], null, [[1, 1], [3, 3], [7, 7]], null, [[1, 3], [7, 7]], null, [[1, 3], [6, 7]]]

   Explanation
   SummaryRanges summaryRanges = new SummaryRanges();
   summaryRanges.addNum(1);      // arr = [1]
   summaryRanges.getIntervals(); // return [[1, 1]]
   summaryRanges.addNum(3);      // arr = [1, 3]
   summaryRanges.getIntervals(); // return [[1, 1], [3, 3]]
   summaryRanges.addNum(7);      // arr = [1, 3, 7]
   summaryRanges.getIntervals(); // return [[1, 1], [3, 3], [7, 7]]
   summaryRanges.addNum(2);      // arr = [1, 2, 3, 7]
   summaryRanges.getIntervals(); // return [[1, 3], [7, 7]]
   summaryRanges.addNum(6);      // arr = [1, 2, 3, 6, 7]
   summaryRanges.getIntervals(); // return [[1, 3], [6, 7]]



Constraints:

0 <= value <= 104
At most 3 * 104 calls will be made to addNum and getIntervals.
At most 102 calls will be made to getIntervals.



Follow up: What if there are lots of merges and the number of disjoint intervals is small compared to the size of the data stream?
*/


#include"head.h"
class SummaryRanges {
	private:
		set<int> num;
		unordered_map<int,int> p;
		unordered_map<int,set<int>::iterator> hash;
		int find(int x)
		{
			return x==p[x]?x:p[x]=find(p[x]);
		}
	public:
		SummaryRanges() {

		}

		void addNum(int value) {
		int x=value,y=value+1;
		num.insert(x);
		hash[x]=num.find(x);

		if(p.find(x)==p.end()) p[x]=x;
		if(p.find(y)==p.end()) p[y]=y;

		if(find(x)!=find(y))
			p[p[x]]=p[y];
		}

		vector<vector<int>> getIntervals() {
		vector<vector<int>> res;

		set<int>::iterator x=num.begin();
		while(x!=num.end())
		{
			int px=find(*x);
			res.push_back({*x,px-1});
			x=hash[px-1];
			x++;
		}
		return res;
		}
};


int main() 
{
	SummaryRanges summaryRanges = SummaryRanges();
summaryRanges.addNum(1);      // arr = [1]
summaryRanges.getIntervals(); // return [[1, 1]]
summaryRanges.addNum(3);      // arr = [1, 3]
summaryRanges.getIntervals(); // return [[1, 1], [3, 3]]
summaryRanges.addNum(7);      // arr = [1, 3, 7]
summaryRanges.getIntervals(); // return [[1, 1], [3, 3], [7, 7]]
summaryRanges.addNum(2);      // arr = [1, 2, 3, 7]
summaryRanges.getIntervals(); // return [[1, 3], [7, 7]]
summaryRanges.addNum(6);      // arr = [1, 2, 3, 6, 7]
summaryRanges.getIntervals(); // return [[1, 3], [6, 7]]
	return 0;
}
