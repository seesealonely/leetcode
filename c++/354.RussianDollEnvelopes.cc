/*
You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Note:
Rotation is not allowed.

Example:

Input: [[5,4],[6,4],[6,7],[2,3]]
Output: 3 
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

*/
#include"354.RussianDollEnvelopes.h"

int main()
{
	Solution s;
	vector<pair<int,int> > v= {{5,4},{6,4},{6,7},{2,3}};
	cout<<s.maxEnvelopes(v)<<endl;
	v.clear();v={{46,89},{50,53},{52,68},{72,45},{77,81}};
	cout<<s.maxEnvelopes(v)<<endl;
	return 0;
}
