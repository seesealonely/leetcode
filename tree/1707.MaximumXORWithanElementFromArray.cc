/*
   You are given an array nums consisting of non-negative integers. You are also given a queries array, where queries[i] = [xi, mi].

   The answer to the ith query is the maximum bitwise XOR value of xi and any element of nums that does not exceed mi. In other words, the answer is max(nums[j] XOR xi) for all j such that nums[j] <= mi. If all elements in nums are larger than mi, then the answer is -1.

   Return an integer array answer where answer.length == queries.length and answer[i] is the answer to the ith query.



   Example 1:

Input: nums = [0,1,2,3,4], queries = [[3,1],[1,3],[5,6]]
Output: [3,3,7]
Explanation:
1) 0 and 1 are the only two integers not greater than 1. 0 XOR 3 = 3 and 1 XOR 3 = 2. The larger of the two is 3.
2) 1 XOR 2 = 3.
3) 5 XOR 2 = 7.

Example 2:

Input: nums = [5,2,4,6,6,3], queries = [[12,4],[8,1],[6,3]]
Output: [15,-1,5]



Constraints:

1 <= nums.length, queries.length <= 105
queries[i].length == 2
0 <= nums[j], xi, mi <= 109

*/


#include"head.h"
class Solution {
    public:
        vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        root=new node();
        for(int i=0;i<nums.size();i++)
            insert(nums[i]);

        vector<int> res(queries.size());
        for(int i=0;i<queries.size();i++)
        {
            int x=queries[i][0],m=queries[i][1];
            res[i]=query(x,m);
        }

        return res;
        }
        struct node
        {
            int min;
            struct node *child[2];
            node ()
            {
                min=INT_MAX;
                child[0]=child[1]=NULL;
            }
        };
    private:
        struct node *root;
        void insert(int x)
        {
            node *p=root;
            for(int i=30;i>=0;i--)
            {
                int b=(x>>i)&1;
                if(p->child[b]==NULL) p->child[b]=new node();
                p=p->child[b];
                p->min=min(p->min,x);
            }
        }

        int query(int x,int m)
        {
            node *p=root;
            int res=0;

            for(int i=30;i>=0;i--)
            {
                int b=(x>>i)&1;
                if(p->child[b^1]&&p->child[b^1]->min<=m)
                {
                    res|=1<<i;
                    p=p->child[b^1];
                }
                else if(p->child[b]&&p->child[b]->min<=m)
                    p=p->child[b];
                else
                    return -1;
            }

            return res;
        }
};


int main() 
{
    Solution s;
    vector<int> n={0,1,2,3,4};
    vector<vector<int>> q={{3,1},{1,3},{5,6}};
    show(s.maximizeXor(n,q));
    n.clear();n={5,2,4,6,6,3};
    q.clear();q={{12,4},{8,1},{6,3}};
    show(s.maximizeXor(n,q));
    return 0;
}
