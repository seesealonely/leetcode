/*
   字符串的 引力 定义为：字符串中 不同 字符的数量。

   例如，"abbca" 的引力为 3 ，因为其中有 3 个不同字符 'a'、'b' 和 'c' 。

   给你一个字符串 s ，返回 其所有子字符串的总引力 。

   子字符串 定义为：字符串中的一个连续字符序列。



   示例 1：

   输入：s = "abbca"
   输出：28
   解释："abbca" 的子字符串有：
   - 长度为 1 的子字符串："a"、"b"、"b"、"c"、"a" 的引力分别为 1、1、1、1、1，总和为 5 。
   - 长度为 2 的子字符串："ab"、"bb"、"bc"、"ca" 的引力分别为 2、1、2、2 ，总和为 7 。
   - 长度为 3 的子字符串："abb"、"bbc"、"bca" 的引力分别为 2、2、3 ，总和为 7 。
   - 长度为 4 的子字符串："abbc"、"bbca" 的引力分别为 3、3 ，总和为 6 。
   - 长度为 5 的子字符串："abbca" 的引力为 3 ，总和为 3 。
   引力总和为 5 + 7 + 7 + 6 + 3 = 28 。

   示例 2：

   输入：s = "code"
   输出：20
   解释："code" 的子字符串有：
   - 长度为 1 的子字符串："c"、"o"、"d"、"e" 的引力分别为 1、1、1、1 ，总和为 4 。
   - 长度为 2 的子字符串："co"、"od"、"de" 的引力分别为 2、2、2 ，总和为 6 。
   - 长度为 3 的子字符串："cod"、"ode" 的引力分别为 3、3 ，总和为 6 。
   - 长度为 4 的子字符串："code" 的引力为 4 ，总和为 4 。
   引力总和为 4 + 6 + 6 + 4 = 20 。



   提示：

   1 <= s.length <= 105
   s 由小写英文字母组成

   来源：力扣（LeetCode）
   链接：https://leetcode-cn.com/problems/total-appeal-of-a-string
   */


#include"head.h"
class Solution {
    public:
        long long appealSum(string s) {
            vector<int> idx(26,-1);
            long long res=0;
            for(int i=0,sum=0;i<s.size();i++)
            {
                int pi=s[i]-'a';
                sum+=i-idx[pi];
                res+=sum;
                idx[pi]=i;
            }
            return res;
        }
};


int main() 
{
    Solution s;
    cout<<s.appealSum("abbca")<<endl;
    cout<<s.appealSum("code")<<endl;
    return 0;
}
