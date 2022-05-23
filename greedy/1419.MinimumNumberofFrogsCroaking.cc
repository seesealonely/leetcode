/*
   You are given the string croakOfFrogs, which represents a combination of the string "croak" from different frogs, that is, multiple frogs can croak at the same time, so multiple "croak" are mixed.

   Return the minimum number of different frogs to finish all the croaks in the given string.

   A valid "croak" means a frog is printing five letters 'c', 'r', 'o', 'a', and 'k' sequentially. The frogs have to print all five letters to finish a croak. If the given string is not a combination of a valid "croak" return -1.



   Example 1:

Input: croakOfFrogs = "croakcroak"
Output: 1
Explanation: One frog yelling "croak" twice.

Example 2:

Input: croakOfFrogs = "crcoakroak"
Output: 2
Explanation: The minimum number of frogs is two.
The first frog could yell "crcoakroak".
The second frog could yell later "crcoakroak".

Example 3:

Input: croakOfFrogs = "croakcrook"
Output: -1
Explanation: The given string is an invalid combination of "croak" from different frogs.



Constraints:

1 <= croakOfFrogs.length <= 105
croakOfFrogs is either 'c', 'r', 'o', 'a', or 'k'.

*/


#include"head.h"
class Solution {
    public:
        int minNumberOfFrogs(string croakOfFrogs) {
        int c=0,r=0,o=0,a=0,k=0,n=croakOfFrogs.size(),res=0;
        for(int i=0;i<n;i++)
        {
            char cur=croakOfFrogs[i];
            if(cur=='c')
                c++;
            else if(cur=='r')
                r++;
            else if(cur=='o')
                o++;
            else if(cur=='a')
                a++;
            else if(cur=='k')
                k++;
            else
                return -1;

            res=max(res,c);

            if(c<r||r<o||o<a||a<k)
                return -1;

            if(k==1)
                c--,r--,o--,a--,k--;
        }
        
        if(c) return -1;

        return res;
        }
};


int main() 
{
    Solution s;
    cout<<s.minNumberOfFrogs("croakcroak")<<endl;
    cout<<s.minNumberOfFrogs("crcoakroak")<<endl;
    cout<<s.minNumberOfFrogs("croakcrook")<<endl;
    return 0;
}
