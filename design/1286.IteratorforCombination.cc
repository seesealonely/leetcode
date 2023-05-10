/*
   Design the CombinationIterator class:

   CombinationIterator(string characters, int combinationLength) Initializes the object with a string characters of sorted distinct lowercase English letters and a number combinationLength as arguments.
   next() Returns the next combination of length combinationLength in lexicographical order.
   hasNext() Returns true if and only if there exists a next combination.



   Example 1:

   Input
   ["CombinationIterator", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
   [["abc", 2], [], [], [], [], [], []]
   Output
   [null, "ab", true, "ac", true, "bc", false]

   Explanation
   CombinationIterator itr = new CombinationIterator("abc", 2);
   itr.next(); // return "ab"
   itr.hasNext(); // return True
   itr.next(); // return "ac"
   itr.hasNext(); // return True
   itr.next(); // return "bc"
   itr.hasNext(); // return False



Constraints:

1 <= combinationLength <= characters.length <= 15
All the characters of characters are unique.
At most 104 calls will be made to next and hasNext.
It is guaranteed that all calls of the function next are valid.

*/


#include"head.h"
class CombinationIterator {
	public:
		vector<int> idx;
		int len;
		string s;
		bool nxt;
		CombinationIterator(string characters, int combinationLength):s(characters.begin(),characters.end()),len(combinationLength) {
			s=characters;
			len=combinationLength;
			idx.resize(combinationLength);
			for(int i=0;i<len;i++)
				idx[i]=i;
			nxt=true;
		}

		string next() {
			string res;
			for(int i=0;i<len;i++)
				res+=s[idx[i]];

			int pos=-1;

			for(int i=len-1;i>=0;i--)
				if(idx[i]-i<s.size()-len)
				{
					pos=i;
					break;
				}
			if(pos!=-1)
			{
				idx[pos]++;
				for(int i=pos+1;i<len;i++)
					idx[i]=idx[i-1]+1;
			}
			else nxt=false;

			return res;

		}

		bool hasNext() {
			return nxt;
		}
};
/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main() 
{
	CombinationIterator *iter=new CombinationIterator("abc",2);
	cout<<iter->next()<<endl;
	cout<<iter->hasNext()<<endl;
	cout<<iter->next()<<endl;
	cout<<iter->hasNext()<<endl;
	cout<<iter->next()<<endl;
	cout<<iter->hasNext()<<endl;

	return 0;
}
