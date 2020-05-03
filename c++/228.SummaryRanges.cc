/*
 Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"]. 
*/
#include"228.SummaryRanges.h"
int main()
{
	int vv[]={0,1,2,4,5,7};
	int vv1[]={-1};
	vector<int> v(vv,vv+6),v1,v2(vv1,vv1+1);
	Solution s;
	show(s.summaryRanges(v));
	show(s.summaryRanges(v1));
	show(s.summaryRanges(v2));
	return 0;
}
