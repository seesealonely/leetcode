/*
   There is an undirected graph with n nodes, numbered from 0 to n - 1.

   You are given a 0-indexed integer array scores of length n where scores[i] denotes the score of node i. You are also given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

   A node sequence is valid if it meets the following conditions:

   There is an edge connecting every pair of adjacent nodes in the sequence.
   No node appears more than once in the sequence.

   The score of a node sequence is defined as the sum of the scores of the nodes in the sequence.

   Return the maximum score of a valid node sequence with a length of 4. If no such sequence exists, return -1.



   Example 1:

Input: scores = [5,2,9,8,4], edges = [[0,1],[1,2],[2,3],[0,2],[1,3],[2,4]]
Output: 24
Explanation: The figure above shows the graph and the chosen node sequence [0,1,2,3].
The score of the node sequence is 5 + 2 + 9 + 8 = 24.
It can be shown that no other node sequence has a score of more than 24.
Note that the sequences [3,1,2,0] and [1,0,2,3] are also valid and have a score of 24.
The sequence [0,3,2,4] is not valid since no edge connects nodes 0 and 3.

Example 2:

Input: scores = [9,20,6,4,11,12], edges = [[0,3],[5,3],[2,4],[1,3]]
Output: -1
Explanation: The figure above shows the graph.
There are no valid node sequences of length 4, so we return -1.



Constraints:

n == scores.length
4 <= n <= 5 1144.DecreaseElementsToMakeArrayZigzag.cc 1509.MinimumDifferenceBetweenLargestandSmallestValueinThreeMoves.cc 1529.MinimumSuffixFlips.cc 1551.MinimumOperationstoMakeArrayEqual 1551.MinimumOperationstoMakeArrayEqual.cc 1557.MinimumNumberofVerticestoReachAllNodes 1557.MinimumNumberofVerticestoReachAllNodes.cc 1561.MaximumNumberofCoinsYouCanGet.cc 1578.MinimumTimetoMakeRopeColorful 1578.MinimumTimetoMakeRopeColorful.cc 1605.FindValidMatrixGivenRowandColumnSums.cc 1614.MaximumNestingDepthoftheParentheses.cc 1647.MinimumDeletionstoMakeCharacterFrequenciesUnique.cc 1663.SmallestStringWithAGivenNumericValue.cc 1686.StoneGameVI 1686.StoneGameVI.cc 1702.MaximumBinaryStringAfterChange.cc 1717.MaximumScoreFromRemovingSubstrings.cc 1758.MinimumChangesToMakeAlternatingBinaryString.cc 1860.IncrementalMemoryLeak.cc 2116.CheckifaParenthesesStringCanBeValid.cc 2126.DestroyingAsteroids 2126.DestroyingAsteroids.cc 2139.MinimumMovestoReachTargetScore.cc 2170.MinimumOperationstoMaketheArrayAlternating 2170.MinimumOperationstoMaketheArrayAlternating.cc 2178.MaximumSplitofPositiveEvenIntegers.cc 2207.MaximizeNumberofSubsequencesinaString 2207.MaximizeNumberofSubsequencesinaString.cc 2211.CountCollisionsonaRoad 2211.CountCollisionsonaRoad.cc 2216.MinimumDeletionstoMakeArrayBeautiful 2216.MinimumDeletionstoMakeArrayBeautiful.cc 2242.MaximumScoreofaNodeSequence.cc head.cc head.h head.o lib.a l.sh makefile 104
1 <= scores[i] <= 108
0 <= edges.length <= 5 1144.DecreaseElementsToMakeArrayZigzag.cc 1509.MinimumDifferenceBetweenLargestandSmallestValueinThreeMoves.cc 1529.MinimumSuffixFlips.cc 1551.MinimumOperationstoMakeArrayEqual 1551.MinimumOperationstoMakeArrayEqual.cc 1557.MinimumNumberofVerticestoReachAllNodes 1557.MinimumNumberofVerticestoReachAllNodes.cc 1561.MaximumNumberofCoinsYouCanGet.cc 1578.MinimumTimetoMakeRopeColorful 1578.MinimumTimetoMakeRopeColorful.cc 1605.FindValidMatrixGivenRowandColumnSums.cc 1614.MaximumNestingDepthoftheParentheses.cc 1647.MinimumDeletionstoMakeCharacterFrequenciesUnique.cc 1663.SmallestStringWithAGivenNumericValue.cc 1686.StoneGameVI 1686.StoneGameVI.cc 1702.MaximumBinaryStringAfterChange.cc 1717.MaximumScoreFromRemovingSubstrings.cc 1758.MinimumChangesToMakeAlternatingBinaryString.cc 1860.IncrementalMemoryLeak.cc 2116.CheckifaParenthesesStringCanBeValid.cc 2126.DestroyingAsteroids 2126.DestroyingAsteroids.cc 2139.MinimumMovestoReachTargetScore.cc 2170.MinimumOperationstoMaketheArrayAlternating 2170.MinimumOperationstoMaketheArrayAlternating.cc 2178.MaximumSplitofPositiveEvenIntegers.cc 2207.MaximizeNumberofSubsequencesinaString 2207.MaximizeNumberofSubsequencesinaString.cc 2211.CountCollisionsonaRoad 2211.CountCollisionsonaRoad.cc 2216.MinimumDeletionstoMakeArrayBeautiful 2216.MinimumDeletionstoMakeArrayBeautiful.cc 2242.MaximumScoreofaNodeSequence.cc head.cc head.h head.o lib.a l.sh makefile 104
edges[i].length == 2
0 <= ai, bi <= n - 1
ai != bi
There are no duplicate edges.

*/


#include"head.h"
class Solution {
    public:
        int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
            const int n=scores.size();
            vector<vector<pair<int,int>>> g(n);
            for(auto &e:edges)
            {
                int x=e[0],y=e[1];
                g[x].emplace_back(-scores[y],y);
                g[y].emplace_back(-scores[x],x);
            }

            for(auto &i:g)
            {
                if(i.size()>3)
                {
                    nth_element(i.begin(),i.begin()+3,i.end());
                    i.resize(3);
                }
            }

            int res=-1;
            for(auto &e:edges)
            {
                int x=e[0],y=e[1];
                for(auto &[score_a,a]:g[x])
                    for(auto &[score_b,b]:g[y])
                        if(a!=y&&b!=x&&a!=b)
                            res=max(res,-score_a+scores[x]+scores[y]-score_b);
            }
            return res;
        }
};


int main() 
{
    Solution s;
    vector<int> sc={5,2,9,8,4};
    vector<vector<int>> e={{0,1},{1,2},{2,3},{0,2},{1,3},{2,4}};
    cout<<s.maximumScore(sc,e)<<endl;
    sc.clear();sc={9,20,6,4,11,12};
    e.clear();e={{0,3},{5,3},{2,4},{1,3}};
    cout<<s.maximumScore(sc,e)<<endl;
    return 0;
}
