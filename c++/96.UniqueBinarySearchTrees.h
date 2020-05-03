/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

*/

#include"head.h"

class Solution {
public:
    int numTrees(int n) {
	vector<int> dp(n+1,0);
	      dp[0]=dp[1]=1; 
	for(int i=2;i<n+1;++i)
		for(int j=1;j<i+1;++j)
			dp[i]+=dp[j-1]*dp[i-j];
		return dp[n];
    }
};
/*
The problem can be solved in a dynamic programming way. I’ll explain the intuition and formulas in the following.

Given a sequence 1…n, to construct a Binary Search Tree (BST) out of the sequence, we could enumerate each number i in the sequence, and use the number as the root, naturally, the subsequence 1…(i-1) on its left side would lay on the left branch of the root, and similarly the right subsequence (i+1)…n lay on the right branch of the root. We then can construct the subtree from the subsequence recursively. Through the above approach, we could ensure that the BST that we construct are all unique, since they have unique roots.

The problem is to calculate the number of unique BST. To do so, we need to define two functions:

G(n): the number of unique BST for a sequence of length n.

F(i, n), 1 <= i <= n: the number of unique BST, where the number i is the root of BST, and the sequence ranges from 1 to n.

As one can see, G(n) is the actual function we need to calculate in order to solve the problem. And G(n) can be derived from F(i, n), which at the end, would recursively refer to G(n).

First of all, given the above definitions, we can see that the total number of unique BST G(n), is the sum of BST F(i) using each number i as a root.
i.e.

G(n) = F(1, n) + F(2, n) + ... + F(n, n). 

Particularly, the bottom cases, there is only one combination to construct a BST out of a sequence of length 1 (only a root) or 0 (empty tree).
i.e.

G(0)=1, G(1)=1. 

Given a sequence 1…n, we pick a number i out of the sequence as the root, then the number of unique BST with the specified root F(i), is the cartesian product of the number of BST for its left and right subtrees. For example, F(3, 7): the number of unique BST tree with number 3 as its root. To construct an unique BST out of the entire sequence [1, 2, 3, 4, 5, 6, 7] with 3 as the root, which is to say, we need to construct an unique BST out of its left subsequence [1, 2] and another BST out of the right subsequence [4, 5, 6, 7], and then combine them together (i.e. cartesian product). The tricky part is that we could consider the number of unique BST out of sequence [1,2] as G(2), and the number of of unique BST out of sequence [4, 5, 6, 7] as G(4). Therefore, F(3,7) = G(2) * G(4).

i.e.

F(i, n) = G(i-1) * G(n-i)	1 <= i <= n 

Combining the above two formulas, we obtain the recursive formula for G(n). i.e.

G(n) = G(0) * G(n-1) + G(1) * G(n-2) + … + G(n-1) * G(0) 

In terms of calculation, we need to start with the lower number, since the value of G(n) depends on the values of G(0) … G(n-1).

With the above explanation and formulas, here is the implementation in Java.
*/
/*
该问题可以用动态编程方式解决。我将在下面解释直觉和公式。

给定序列1 ... n，从序列中构建二进制搜索树（BST），我们可以枚举序列中的每个数字i，并且使用该数字作为根，当然，子序列1 ...（i-1）其左侧将位于根的左侧分支，同样，正确的子序列（i + 1）... n位于根的右侧分支。然后，我们可以递归地从子序列中构造子树。通过上述方法，我们可以确保我们构建的BST是独一无二的，因为它们具有独特的根源。

问题是计算唯一BST的数量。为此，我们需要定义两个功能：

G（n）：长度为n的序列的唯一BST的数量。

F（i，n），1 <= i <= n：唯一BST的数量，其中数字i是BST的根，并且序列的范围从1到n。

可以看出，G（n）是为了解决问题而需要计算的实际函数。并且G（n）可以从F（i，n）导出，其结尾将递归地指代G（n）。

首先，考虑到上述定义，我们可以看到，唯一BST G（n）的总数是使用每个数字i作为根的BST F（i）的总和。
即

G（n）= F（1，n）+ F（2，n）+ ... + F（n，n）。

特别地，底部情况下，只有一个组合来构造长度为1（只有根）或0（空树）的序列中的BST。
即

G（0）= 1，G（1）= 1。

给定一个序列1 ... n，我们选择序列中的数字i作为根，然后具有指定根F（i）的唯一BST的数量是其左和右子树的BST数的笛卡尔乘积。例如，F（3,7）：具有3号作为其根的唯一BST树的数量。在整个序列[1,2,3,4,5,6,7]中构建一个唯一的BST，其中3为根，也就是说，我们需要在其左子序列[1]中构建一个唯一的BST ，2]和另一个BST在正确的子序列[4,5,6,7]中，然后将它们组合在一起（即笛卡尔乘积）。棘手的部分是我们可以将序列[1,2]中唯一的BST的数目考虑为G（2），并且将序列[4，5，6，7]中唯一的BST的数量视为G（4 ）。因此，F（3,7）= G（2）* G（4）。

即

F（i，n）= G（i-1）* G（n-i）1 <= i <= n

结合上述两个公式，得到G（n）的递归公式。即

G（n）= G（0）* G（n-1）+ G（1）* G（n-2）+ ... + G（n-1）* G

在计算方面，我们需要从较低的数字开始，因为G（n）的值取决于G（0）... G（n-1）的值。

利用上述说明和公式，这里是Java中的实现。
*/
