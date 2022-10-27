/*
   Given n cuboids where the dimensions of the ith cuboid is cuboids[i] = [widthi, lengthi, heighti] (0-indexed). Choose a subset of cuboids and place them on each other.

   You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= lengthj and heighti <= heightj. You can rearrange any cuboid's dimensions by rotating it to put it on another cuboid.

   Return the maximum height of the stacked cuboids.



   Example 1:

Input: cuboids = [[50,45,20],[95,37,53],[45,23,12]]
Output: 190
Explanation:
Cuboid 1 is placed on the bottom with the 53x37 side facing down with height 95.
Cuboid 0 is placed next with the 45x20 side facing down with height 50.
Cuboid 2 is placed next with the 23x12 side facing down with height 45.
The total height is 95 + 50 + 45 = 190.

Example 2:

Input: cuboids = [[38,25,45],[76,35,3]]
Output: 76
Explanation:
You can't place any of the cuboids on the other.
We choose cuboid 1 and rotate it so that the 35x3 side is facing down and its height is 76.

Example 3:

Input: cuboids = [[7,11,17],[7,17,11],[11,7,17],[11,17,7],[17,7,11],[17,11,7]]
Output: 102
Explanation:
After rearranging the cuboids, you can see that all cuboids have the same dimension.
You can place the 11x7 side down on all cuboids so their heights are 17.
The maximum height of stacked cuboids is 6 1000.MinimumCosttoMergeStones 1000.MinimumCosttoMergeStones.cc 1027.LongestArithmeticSubsequence 1027.LongestArithmeticSubsequence.cc 1039.MinimumScoreTriangulationofPolygon 1039.MinimumScoreTriangulationofPolygon.cc 1105.FillingBookcaseShelves 1105.FillingBookcaseShelves.cc 1140.StoneGameII 1140.StoneGameII.cc 1223.DiceRollSimulation 1223.DiceRollSimulation.cc 1269.NumberofWaystoStayintheSamePlaceAfterSomeSteps 1269.NumberofWaystoStayintheSamePlaceAfterSomeSteps.cc 1278.PalindromePartitioningIII 1278.PalindromePartitioningIII.cc 1320.MinimumDistancetoTypeaWordUsingTwoFingers 1320.MinimumDistancetoTypeaWordUsingTwoFingers.cc 1349.MaximumStudentsTakingExam.cc 1434.NumberofWaystoWearDifferentHatstoEachOther 1434.NumberofWaystoWearDifferentHatstoEachOther.cc 1444.NumberofWaysofCuttingaPizza 1444.NumberofWaysofCuttingaPizza.cc 1449.FormLargestIntegerWithDigitsThatAdduptoTarget 1449.FormLargestIntegerWithDigitsThatAdduptoTarget.cc 1477.FindTwoNon-overlappingSub-arraysEachWithTargetSum 1477.FindTwoNon-overlappingSub-arraysEachWithTargetSum.cc 1493.LongestSubarrayof1sAfterDeletingOneElement.cc 1510.StoneGameIV 1510.StoneGameIV.cc 1546.MaximumNumberofNon-OverlappingSubarraysWithSumEqualsTarget 1546.MaximumNumberofNon-OverlappingSubarraysWithSumEqualsTarget.cc 1547.MinimumCosttoCutaStick 1547.MinimumCosttoCutaStick.cc 1563.StoneGameV 1563.StoneGameV.cc 1567.MaximumLengthofSubarrayWithPositiveProduct 1567.MaximumLengthofSubarrayWithPositiveProduct.cc 1594.MaximumNonNegativeProductinaMatrix 1594.MaximumNonNegativeProductinaMatrix.cc 1621.NumberofSetsofKNon-OverlappingLineSegments 1621.NumberofSetsofKNon-OverlappingLineSegments.cc 1626.BestTeamWithNoConflicts 1626.BestTeamWithNoConflicts.cc 1641.CountSortedVowelStrings.cc 1659.MaximizeGridHappiness 1659.MaximizeGridHappiness.cc 1690.StoneGameVII.cc 1691.MaximumHeightbyStackingCuboids.cc 1723.FindMinimumTimetoFinishAllJobs.cc 1745.PalindromePartitioningIV 1745.PalindromePartitioningIV.cc 1751.MaximumNumberofEventsThatCanBeAttendedII 1751.MaximumNumberofEventsThatCanBeAttendedII.cc 1770.MaximumScorefromPerformingMultiplicationOperations.cc 1771.MaximizePalindromeLengthFromSubsequences.cc 1774.ClosestDessertCost.cc 1799.MaximizeScoreAfterNOperations.cc 1824.MinimumSidewayJumps.cc 1909.RemoveOneElementtoMaketheArrayStrictlyIncreasing.cc 1955.CountNumberofSpecialSubsequences 1955.CountNumberofSpecialSubsequences.cc 1986.MinimumNumberofWorkSessionstoFinishtheTasks.cc 1987.NumberofUniqueGoodSubsequences.cc 2054.TwoBestNon-OverlappingEvents 2054.TwoBestNon-OverlappingEvents.cc 2063.VowelsofAllSubstrings.cc 2111.MinimumOperationstoMaketheArrayK-Increasing.cc 2140.SolvingQuestionsWithBrainpower 2140.SolvingQuestionsWithBrainpower.cc 2209.MinimumWhiteTilesAfterCoveringWithCarpets 2209.MinimumWhiteTilesAfterCoveringWithCarpets.cc 2218.MaximumValueofKCoinsFromPiles 2218.MaximumValueofKCoinsFromPiles.cc 2222.NumberofWaystoSelectBuildings 2222.NumberofWaystoSelectBuildings.cc 2240.NumberofWaystoBuyPensandPencils 2240.NumberofWaystoBuyPensandPencils.cc 2266.CountNumberofTexts 2266.CountNumberofTexts.cc 2267.CheckifThereIsaValidParenthesesStringPath 2267.CheckifThereIsaValidParenthesesStringPath.cc 2272.SubstringWithLargestVariance 2272.SubstringWithLargestVariance.cc 2304.MinimumPathCostinaGrid 2304.MinimumPathCostinaGrid.cc 2309.GreatestEnglishLetterinUpperandLowerCase.cc 2312.SellingPiecesofWood 2312.SellingPiecesofWood.cc 2318.NumberofDistinctRollSequences 2318.NumberofDistinctRollSequences.cc 2320.CountNumberofWaystoPlaceHouses 2320.CountNumberofWaystoPlaceHouses.cc 2327.NumberofPeopleAwareofaSecret 2327.NumberofPeopleAwareofaSecret.cc 2338.CounttheNumberofIdealArrays 2338.CounttheNumberofIdealArrays.cc 2369.CheckifThereisaValidPartitionForTheArray 2369.CheckifThereisaValidPartitionForTheArray.cc 2370.LongestIdealSubsequence 2370.LongestIdealSubsequence.cc 2380.TimeNeededtoRearrangeaBinaryString 2380.TimeNeededtoRearrangeaBinaryString.cc 2400.NumberofWaystoReachaPositionAfterExactlykSteps 2400.NumberofWaystoReachaPositionAfterExactlykSteps.cc 2435.PathsinMatrixWhoseSumIsDivisiblebyK 2435.PathsinMatrixWhoseSumIsDivisiblebyK.cc 256.PaintHouse 256.PaintHouse.cc 309.BestTimetoBuyandSellStockwithCooldown 309.BestTimetoBuyandSellStockwithCooldown.cc 375.GuessNumberHigherorLowerII 375.GuessNumberHigherorLowerII.cc 464.CanIWin 464.CanIWin.cc 576.OutofBoundaryPaths 576.OutofBoundaryPaths.cc 600.Non-negativeIntegerswithoutConsecutiveOnes 600.Non-negativeIntegerswithoutConsecutiveOnes.cc 698.PartitiontoKEqualSumSubsets 698.PartitiontoKEqualSumSubsets.cc 730.CountDifferentPalindromicSubsequences 730.CountDifferentPalindromicSubsequences.cc 741.CherryPickup.cc 756.PyramidTransitionMatrix.cc 764.LargestPlusSign 764.LargestPlusSign.cc 787.CheapestFlightsWithinKStops 787.CheapestFlightsWithinKStops.cc 790.DominoandTrominoTiling 790.DominoandTrominoTiling.cc 837.New21Game 837.New21Game.cc 887.SuperEggDrop 887.SuperEggDrop.cc 935.KnightDialer 935.KnightDialer.cc head.cc head.h head.o lib.a l.sh makefile 17 = 102.



Constraints:

n == cuboids.length
1 <= n <= 100
1 <= widthi, lengthi, heighti <= 100

*/


#include"head.h"
class Solution {
    public:
        int maxHeight(vector<vector<int>>& cuboids) {
        const int n=cuboids.size();
        for(int i=0;i<n;i++)
            sort(cuboids[i].begin(),cuboids[i].end());

        sort(cuboids.begin(),cuboids.end());
        vector<int> dp(n);
        int res=0;
        for(int i=0;i<n;i++)
        {
            dp[i]=cuboids[i][2];
            for(int j=0;j<i;j++)
                if(cuboids[i][1]>=cuboids[j][1]&&cuboids[i][2]>=cuboids[j][2])
                    dp[i]=max(dp[i],dp[j]+cuboids[i][2]);
            res=max(res,dp[i]);
        }

        return res;
        }
};


int main() 
{
    Solution s;
    vector<vector<int>> v={{50,45,20},{95,37,53},{45,23,12}};
    cout<<s.maxHeight(v)<<endl;
    v.clear();v={{38,25,45},{76,35,3}};
    cout<<s.maxHeight(v)<<endl;
    v.clear();v={{7,11,17},{7,17,11},{11,7,17},{11,17,7},{17,7,11},{17,11,7}};
    cout<<s.maxHeight(v)<<endl;
    return 0;
}
