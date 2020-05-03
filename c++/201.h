#include<iostream>
using namespace std;
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
 	int mask=~0;
	while(mask&&(m&mask)!=(n&mask))
	mask<<=1;
	return m&mask;       
    }
};
