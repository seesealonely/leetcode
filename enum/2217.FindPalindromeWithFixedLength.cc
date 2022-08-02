/*
   Given an integer array queries and a positive integer intLength, return an array answer where answer[i] is either the queries[i]th smallest positive palindrome of length intLength or -1 if no such palindrome exists.

   A palindrome is a number that reads the same backwards and forwards. Palindromes cannot have leading zeros.



   Example 1:

Input: queries = [1,2,3,4,5,90], intLength = 3
Output: [101,111,121,131,141,999]
Explanation:
The first few palindromes of length 3 are:
101, 111, 121, 131, 141, 151, 161, 171, 181, 191, 202, ...
The 90th palindrome of length 3 is 999.

Example 2:

Input: queries = [2,4,6], intLength = 4
Output: [1111,1331,1551]
Explanation:
The first six palindromes of length 4 are:
1001, 1111, 1221, 1331, 1441, and 1551.



Constraints:

1 <= queries.length <= 5 * 104
1 <= queries[i] <= 109
1 <= intLength <= 15


*/


#include"head.h"
class Solution {
    public:
        vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        vector<long long> res;
        int base=1;
        for(int i=0;i<(intLength+1)>>1;i++)
            base*=10;

        for(int i=0;i<queries.size();i++)
            res.push_back(solve(queries[i],base,intLength));

        return res;
        }
        long long solve(int k,int base,int len)
        {
            if(k>base-base/10)
                return -1;

            k+=base/10-1;

            long long res=k;
            if(len%2)
                k/=10;

            for(int i=0;i<len/2;i++)
            {
                res=res*10+k%10;
                k/=10;
            }
            return res;
        }
};


int main() 
{
    Solution s;
    vector<int> v={1,2,3,4,5,90};
    show(s.kthPalindrome(v,3));
    v.clear();v={2,4,6};
    show(s.kthPalindrome(v,4));
    return 0;
}
