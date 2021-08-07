/*
   In a warehouse, there is a row of barcodes, where the ith barcode is barcodes[i].

   Rearrange the barcodes so that no two adjacent barcodes are equal. You may return any answer, and it is guaranteed an answer exists.



   Example 1:

Input: barcodes = [1,1,1,2,2,2]
Output: [2,1,2,1,2,1]

Example 2:

Input: barcodes = [1,1,1,1,2,2,3,3]
Output: [1,3,1,3,1,2,1,2]



Constraints:

1 <= barcodes.length <= 10000
1 <= barcodes[i] <= 10000

*/
#define c11
#include"head.h"
class Solution {
	public:
		vector<int> rearrangeBarcodes(vector<int>& barcodes) {
		int n=barcodes.size(),index=0;
		vector<int> res(n);
		vector<pair<int,int> > smaller;
		unordered_map<int,int> h(n);
		for(int i=0;i<n;i++)
			h[barcodes[i]]++;
		for(unordered_map<int,int>::iterator it=h.begin();it!=h.end();it++)
			smaller.push_back({it->second,it->first});
		sort(smaller.begin(),smaller.end(),cmp);
		for(int i=0;i<smaller.size();i++)
			for(int j=0;j<smaller[i].first;j++)
			{
				if(index>=n)
					index=1;
				res[index]=smaller[i].second,index+=2;
			}
		return res;
		}
		static	bool cmp(pair<int,int> &a,pair<int,int> &b)
		{
			return a.first>b.first;
		}
};
