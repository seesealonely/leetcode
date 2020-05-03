#include<iostream>
using namespace std;
class Solution {
public:
    int findComplement(int num) {
     unsigned  int res=~0;
	while(res&num) res<<=1;
	return ~res&~num;
    }
};
