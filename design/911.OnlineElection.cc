/*
   You are given two integer arrays persons and times. In an election, the ith vote was cast for persons[i] at time times[i].

   For each query at a time t, find the person that was leading the election at time t. Votes cast at time t will count towards our query. In the case of a tie, the most recent vote (among tied candidates) wins.

   Implement the TopVotedCandidate class:

   TopVotedCandidate(int[] persons, int[] times) Initializes the object with the persons and times arrays.
   int q(int t) Returns the number of the person that was leading the election at time t according to the mentioned rules.



   Example 1:

   Input
   ["TopVotedCandidate", "q", "q", "q", "q", "q", "q"]
   [[[0, 1, 1, 0, 0, 1, 0], [0, 5, 10, 15, 20, 25, 30]], [3], [12], [25], [15], [24], [8]]
   Output
   [null, 0, 1, 1, 0, 0, 1]

   Explanation
   TopVotedCandidate topVotedCandidate = new TopVotedCandidate([0, 1, 1, 0, 0, 1, 0], [0, 5, 10, 15, 20, 25, 30]);
   topVotedCandidate.q(3); // return 0, At time 3, the votes are [0], and 0 is leading.
   topVotedCandidate.q(12); // return 1, At time 12, the votes are [0,1,1], and 1 is leading.
   topVotedCandidate.q(25); // return 1, At time 25, the votes are [0,1,1,0,0,1], and 1 is leading (as ties go to the most recent vote.)
   topVotedCandidate.q(15); // return 0
   topVotedCandidate.q(24); // return 0
   topVotedCandidate.q(8); // return 1



Constraints:

1 <= persons.length <= 5000
times.length == persons.length
0 <= persons[i] < persons.length
0 <= times[i] <= 109
times is sorted in a strictly increasing order.
times[0] <= t <= 109
At most 104 calls will be made to q.

*/


#include"head.h"
class TopVotedCandidate {
	public:
		vector<int> times,votes;
		TopVotedCandidate(vector<int>& persons, vector<int>& times) {
			int n=persons.size();
			vector<int> sum(n+1,0);
			votes.resize(n,0);

			sum[persons[0]]++;
			votes[0]=persons[0];

			for(int i=1;i<n;i++)
			{
				sum[persons[i]]++;
				if(sum[persons[i]]>=sum[votes[i-1]])
					votes[i]=persons[i];
				else
					votes[i]=votes[i-1];
			}
			this->times=times;

		}

		int q(int t) {
			int l=0,r=times.size()-1;
			while(l<r)
			{
				int m=(l+r+1)>>1;
				if(t<times[m])
					r=m-1;
				else
					l=m;
			}
			return votes[l];
		}
};


int main() 
{
	vector<int> p={0, 1, 1, 0, 0, 1, 0},ti={0, 5, 10, 15, 20, 25, 30};
	TopVotedCandidate t(p,ti);
	cout<<t.q(3)<<endl;
	cout<<t.q(12)<<endl;
	cout<<t.q(25)<<endl;
	cout<<t.q(15)<<endl;
	cout<<t.q(24)<<endl;
	cout<<t.q(8)<<endl;
	return 0;
}
