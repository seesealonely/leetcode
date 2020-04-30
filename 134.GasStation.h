/*
 There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1. 
*/

#include"head.h"

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
 	int begin=0,sum=0,tank=0;
	for(int i=0;i<gas.size();++i)
	if((tank=tank+gas[i]-cost[i])<0)
	{ begin=i+1; sum+=tank; tank=0;}       
	return (sum+tank<0)?-1:begin;
    }
};
