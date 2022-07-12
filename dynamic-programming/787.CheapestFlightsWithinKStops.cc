/*
   There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

   You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.



   Example 1:

Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.

Example 2:

Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.

Example 3:

Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph is shown above.
The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.



Constraints:

1 <= n <= 100
0 <= flights.length <= (n 1027.LongestArithmeticSubsequence 1027.LongestArithmeticSubsequence.cc 1349.MaximumStudentsTakingExam.cc 1477.FindTwoNon-overlappingSub-arraysEachWithTargetSum 1477.FindTwoNon-overlappingSub-arraysEachWithTargetSum.cc 1493.LongestSubarrayof1sAfterDeletingOneElement.cc 1510.StoneGameIV 1510.StoneGameIV.cc 1547.MinimumCosttoCutaStick 1547.MinimumCosttoCutaStick.cc 1563.StoneGameV 1563.StoneGameV.cc 1567.MaximumLengthofSubarrayWithPositiveProduct 1567.MaximumLengthofSubarrayWithPositiveProduct.cc 1594.MaximumNonNegativeProductinaMatrix.cc 1621.NumberofSetsofKNon-OverlappingLineSegments 1621.NumberofSetsofKNon-OverlappingLineSegments.cc 1626.BestTeamWithNoConflicts 1626.BestTeamWithNoConflicts.cc 1641.CountSortedVowelStrings.cc 1690.StoneGameVII.cc 1723.FindMinimumTimetoFinishAllJobs.cc 1770.MaximumScorefromPerformingMultiplicationOperations.cc 1771.MaximizePalindromeLengthFromSubsequences.cc 1774.ClosestDessertCost.cc 1799.MaximizeScoreAfterNOperations.cc 1824.MinimumSidewayJumps.cc 1909.RemoveOneElementtoMaketheArrayStrictlyIncreasing.cc 1955.CountNumberofSpecialSubsequences 1955.CountNumberofSpecialSubsequences.cc 1986.MinimumNumberofWorkSessionstoFinishtheTasks.cc 1987.NumberofUniqueGoodSubsequences.cc 2054.TwoBestNon-OverlappingEvents 2054.TwoBestNon-OverlappingEvents.cc 2063.VowelsofAllSubstrings.cc 2111.MinimumOperationstoMaketheArrayK-Increasing.cc 2218.MaximumValueofKCoinsFromPiles.cc 2222.NumberofWaystoSelectBuildings 2222.NumberofWaystoSelectBuildings.cc 2240.NumberofWaystoBuyPensandPencils 2240.NumberofWaystoBuyPensandPencils.cc 2266.CountNumberofTexts 2266.CountNumberofTexts.cc 309.BestTimetoBuyandSellStockwithCooldown 309.BestTimetoBuyandSellStockwithCooldown.cc 375.GuessNumberHigherorLowerII 375.GuessNumberHigherorLowerII.cc 464.CanIWin 464.CanIWin.cc 576.OutofBoundaryPaths 576.OutofBoundaryPaths.cc 698.PartitiontoKEqualSumSubsets 698.PartitiontoKEqualSumSubsets.cc 756.PyramidTransitionMatrix.cc 764.LargestPlusSign 764.LargestPlusSign.cc 787.CheapestFlightsWithinKStops.cc 790.DominoandTrominoTiling 790.DominoandTrominoTiling.cc 837.New21Game.cc head.cc head.h head.o lib.a l.sh makefile (n - 1) / 2)
flights[i].length == 3
0 <= fromi, toi < n
fromi != toi
1 <= pricei <= 104
There will not be any multiple flights between two cities.
0 <= src, dst, k < n
src != dst

*/


#include"head.h"
class Solution {
    public:
        int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> dp(k+2,vector<int>(n,1e8));

        for(int i=1;i<=k+1;i++)
        {
            dp[i][src]=0;
            for(int j=0;j<flights.size();j++)
                dp[i][flights[j][1]]=min(dp[i][flights[j][1]],dp[i-1][flights[j][0]]+flights[j][2]);
        }
        }
};


int main() 
{
    Solution s;
//    s.findCheapestPrice();
    return 0;
}
