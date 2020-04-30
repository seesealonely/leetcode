/*
 There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1. 
*/

#include"134.GasStation.h"

int main()
{
	int vv[]={1,2,3,4,5,6,7};
	vector<int> g(vv,vv+7);
	vector<int> c(vv,vv+7);
	Solution s;
	cout<<s.canCompleteCircuit(g,c)<<endl;
	return 0;
}
