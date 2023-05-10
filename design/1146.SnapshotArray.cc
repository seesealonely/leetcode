/*
   Implement a SnapshotArray that supports the following interface:

   SnapshotArray(int length) initializes an array-like data structure with the given length. Initially, each element equals 0.
   void set(index, val) sets the element at the given index to be equal to val.
   int snap() takes a snapshot of the array and returns the snap_id: the total number of times we called snap() minus 1.
   int get(index, snap_id) returns the value at the given index, at the time we took the snapshot with the given snap_id



   Example 1:

Input: ["SnapshotArray","set","snap","set","get"]
[[3],[0,5],[],[0,6],[0,0]]
Output: [null,null,0,null,5]
Explanation: 
SnapshotArray snapshotArr = new SnapshotArray(3); // set the length to be 3
snapshotArr.set(0,5);  // Set array[0] = 5
snapshotArr.snap();  // Take a snapshot, return snap_id = 0
snapshotArr.set(0,6);
snapshotArr.get(0,0);  // Get the value of array[0] with snap_id = 0, return 5



Constraints:

1 <= length <= 5 * 104
0 <= index < length
0 <= val <= 109
0 <= snap_id < (the total number of times we call snap())
At most 5 * 104 calls will be made to set, snap, and get.

*/


#include"head.h"
class SnapshotArray {
	public:
		vector<vector<pair<int,int>>> snapshot;
		int count;
		SnapshotArray(int length) {
			snapshot.resize(length);
			for(int i=0;i<length;i++)
				snapshot[i].emplace_back(0,0);
			count=0;
		}

		void set(int index, int val) {
			pair<int,int> &x=snapshot[index].back();
			if(x.first==count) x.second=val;
			else snapshot[index].emplace_back(count,val);
		}

		int snap() {
			return count++;
		}

		int get(int index, int snap_id) {
			vector<pair<int,int>> &x=snapshot[index];
			int l=0,r=x.size()-1;
			while(l<r)
			{
				int m=(l+r)>>1;
				if(snap_id>=x[m+1].first)
					l=m+1;
				else
					r=m;
			}
			return x[l].second;
		}
};


int main() 
{
	SnapshotArray *s=new SnapshotArray(3);
	s->set(0,5);
	cout<<s->snap()<<endl;
	s->set(0,6);
	cout<<s->get(0,0)<<endl;
	return 0;
}
