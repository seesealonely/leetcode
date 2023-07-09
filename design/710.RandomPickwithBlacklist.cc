/*
   You are given an integer n and an array of unique integers blacklist. Design an algorithm to pick a random integer in the range [0, n - 1] that is not in blacklist. Any integer that is in the mentioned range and not in blacklist should be equally likely to be returned.

   Optimize your algorithm such that it minimizes the number of calls to the built-in random function of your language.

   Implement the Solution class:

   Solution(int n, int[] blacklist) Initializes the object with the integer n and the blacklisted integers blacklist.
   int pick() Returns a random integer in the range [0, n - 1] and not in blacklist.



   Example 1:

   Input
   ["Solution", "pick", "pick", "pick", "pick", "pick", "pick", "pick"]
   [[7, [2, 3, 5]], [], [], [], [], [], [], []]
   Output
   [null, 0, 4, 1, 6, 1, 0, 4]

   Explanation
   Solution solution = new Solution(7, [2, 3, 5]);
   solution.pick(); // return 0, any integer from [0,1,4,6] should be ok. Note that for every call of pick,
		    // 0, 1, 4, and 6 must be equally likely to be returned (i.e., with probability 1/4).
		    solution.pick(); // return 4
		    solution.pick(); // return 1
		    solution.pick(); // return 6
		    solution.pick(); // return 1
		    solution.pick(); // return 0
		    solution.pick(); // return 4



Constraints:

1 <= n <= 109
0 <= blacklist.length <= min(105, n - 1)
0 <= blacklist[i] < n
All the values of blacklist are unique.
At most 2 * 104 calls will be made to pick.

*/

#define c11
#include"head.h"
class Solution {
	public:
		unordered_map<int,int> hash;
		int N,n,idx;
		Solution(int n,vector<int>& blacklist) {
		this->N=n,this->n=blacklist.size(),idx=n-1;

		for(int i=0;i<this->n;i++)
			hash[blacklist[i]]=-1;
		sort(blacklist.begin(),blacklist.end());

		for(int i=0;i<this->n;i++)
		{
			if(blacklist[i]>=n-this->n)
				break;
			while(hash.find(idx)!=hash.end())
				idx--;
			hash[blacklist[i]]=idx--;
		}

		}

		int pick() {
		int res=rand()%(N-n);
		if(hash.find(res)!=hash.end())
			return hash[res];
		return res;
		}
};


int main() 
{
	vector<int> blacklist={2, 3, 5};
	Solution solution = Solution(7,blacklist);
solution.pick(); // return 0, any integer from [0,1,4,6] should be ok. Note that for every call of pick,
                 // 0, 1, 4, and 6 must be equally likely to be returned (i.e., with probability 1/4).
solution.pick(); // return 4
solution.pick(); // return 1
solution.pick(); // return 6
solution.pick(); // return 1
solution.pick(); // return 0
solution.pick(); // return 4
	return 0;
}
