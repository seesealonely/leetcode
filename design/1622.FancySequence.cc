/*
   Write an API that generates fancy sequences using the append, addAll, and multAll operations.

   Implement the Fancy class:

   Fancy() Initializes the object with an empty sequence.
   void append(val) Appends an integer val to the end of the sequence.
   void addAll(inc) Increments all existing values in the sequence by an integer inc.
   void multAll(m) Multiplies all existing values in the sequence by an integer m.
   int getIndex(idx) Gets the current value at index idx (0-indexed) of the sequence modulo 109 + 7. If the index is greater or equal than the length of the sequence, return -1.



   Example 1:

   Input
   ["Fancy", "append", "addAll", "append", "multAll", "getIndex", "addAll", "append", "multAll", "getIndex", "getIndex", "getIndex"]
   [[], [2], [3], [7], [2], [0], [3], [10], [2], [0], [1], [2]]
   Output
   [null, null, null, null, null, 10, null, null, null, 26, 34, 20]

   Explanation
   Fancy fancy = new Fancy();
   fancy.append(2); // fancy sequence: [2]
   fancy.addAll(3); // fancy sequence: [2+3] -> [5]
   fancy.append(7); // fancy sequence: [5, 7]
   fancy.multAll(2); // fancy sequence: [5*2, 7*2] -> [10, 14]
   fancy.getIndex(0); // return 10
   fancy.addAll(3); // fancy sequence: [10+3, 14+3] -> [13, 17]
   fancy.append(10); // fancy sequence: [13, 17, 10]
   fancy.multAll(2); // fancy sequence: [13*2, 17*2, 10*2] -> [26, 34, 20]
   fancy.getIndex(0); // return 26
   fancy.getIndex(1); // return 34
   fancy.getIndex(2); // return 20



Constraints:

1 <= val, inc, m <= 100
0 <= idx <= 105
At most 105 calls total will be made to append, addAll, multAll, and getIndex.

*/


#include"head.h"
class Fancy {
	private:
		typedef long long int ll;
		vector<ll> nums;
		ll add,mul;
		static const int mod=1e9+7;
		ll power(ll x,ll y)
		{
			ll tot=1,p=x;
			for(;y;y>>=1)
			{
				if(y&1)
					tot=(tot*p)%mod;
				p=(p*p)%mod;
			}
			return tot;
		}
	public:
		Fancy() {
			add=0;
			mul=1;
		}

		void append(int val) {
			val=((val-add)%mod+mod)%mod;
			val=(val*power(mul,mod-2))%mod;
			nums.push_back(val);
		}

		void addAll(int inc) {
			add=(add+inc)%mod;
		}

		void multAll(int m) {
			add=add*m%mod;
			mul=mul*m%mod;
		}

		int getIndex(int idx) {
			if(idx>=nums.size())
				return -1;

			return (nums[idx]*mul+add)%mod;
		}
};


int main() 
{
	Fancy fancy=Fancy();
	fancy.append(2);
	fancy.addAll(3);
	fancy.append(7);
	fancy.multAll(2);
	fancy.getIndex(0);
	fancy.addAll(3);
	fancy.append(10);
	fancy.multAll(2);
	fancy.getIndex(0);
	fancy.getIndex(1);
	fancy.getIndex(2);
	return 0;
}
