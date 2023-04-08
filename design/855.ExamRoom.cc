/*
   There is an exam room with n seats in a single row labeled from 0 to n - 1.

   When a student enters the room, they must sit in the seat that maximizes the distance to the closest person. If there are multiple such seats, they sit in the seat with the lowest number. If no one is in the room, then the student sits at seat number 0.

   Design a class that simulates the mentioned exam room.

   Implement the ExamRoom class:

   ExamRoom(int n) Initializes the object of the exam room with the number of the seats n.
   int seat() Returns the label of the seat at which the next student will set.
   void leave(int p) Indicates that the student sitting at seat p will leave the room. It is guaranteed that there will be a student sitting at seat p.



   Example 1:

   Input
   ["ExamRoom", "seat", "seat", "seat", "seat", "leave", "seat"]
   [[10], [], [], [], [], [4], []]
   Output
   [null, 0, 9, 4, 2, null, 5]

   Explanation
   ExamRoom examRoom = new ExamRoom(10);
   examRoom.seat(); // return 0, no one is in the room, then the student sits at seat number 0.
   examRoom.seat(); // return 9, the student sits at the last seat number 9.
   examRoom.seat(); // return 4, the student sits at the last seat number 4.
   examRoom.seat(); // return 2, the student sits at the last seat number 2.
   examRoom.leave(4);
   examRoom.seat(); // return 5, the student sits at the last seat number 5.



Constraints:

1 <= n <= 109
It is guaranteed that there is a student sitting at seat p.
At most 104 calls will be made to seat and leave.

*/


#include"head.h"
class ExamRoom {
	public:
		vector<int> seats;
		int n;
		ExamRoom(int N) {
			n=N;
		}

		int seat() {
			if(seats.empty())
			{
				seats.push_back(0);
				return 0;
			}

			int maxdis=max(seats.front()-0,n-1-seats.back());

			for(int i=1;i<seats.size();i++)
				maxdis=max(maxdis,(seats[i]-seats[i-1])>>1);

			if(maxdis==seats.front()-0)
			{
				seats.insert(seats.begin(),0);
				return 0;
			}

			for(int i=1;i<seats.size();i++)
			{
				if(maxdis==(seats[i]-seats[i-1])>>1)
				{
					seats.insert(seats.begin()+i,seats[i-1]+maxdis);
					return seats[i];
				}
			}
			seats.push_back(n-1);
			return n-1;
		}


		void leave(int p) {
			for(int i=0;i<seats.size();i++)
				if(seats[i]==p)
				{
					seats.erase(seats.begin()+i);
					break;
				}
		}
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */

int main() 
{
	ExamRoom e(10);
	cout<<e.seat()<<endl;
	cout<<e.seat()<<endl;
	cout<<e.seat()<<endl;
	cout<<e.seat()<<endl;
	e.leave(4);
	cout<<e.seat()<<endl;
	return 0;
}
