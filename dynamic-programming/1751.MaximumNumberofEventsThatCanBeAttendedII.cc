/*
   You are given an array of events where events[i] = [startDayi, endDayi, valuei]. The ith event starts at startDayi and ends at endDayi, and if you attend this event, you will receive a value of valuei. You are also given an integer k which represents the maximum number of events you can attend.

   You can only attend one event at a time. If you choose to attend an event, you must attend the entire event. Note that the end day is inclusive: that is, you cannot attend two events where one of them starts and the other ends on the same day.

   Return the maximum sum of values that you can receive by attending events.



   Example 1:

Input: events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
Output: 7
Explanation: Choose the green events, 0 and 1 (0-indexed) for a total value of 4 + 3 = 7.

Example 2:

Input: events = [[1,2,4],[3,4,3],[2,3,10]], k = 2
Output: 10
Explanation: Choose event 2 for a total value of 10.
Notice that you cannot attend any other event as they overlap, and that you do not have to attend k events.

Example 3:

Input: events = [[1,1,1],[2,2,2],[3,3,3],[4,4,4]], k = 3
Output: 9
Explanation: Although the events do not overlap, you can only attend 3 events. Pick the highest valued three.



Constraints:

1 <= k <= events.length
1 <= k 1027.LongestArithmeticSubsequence 1027.LongestArithmeticSubsequence.cc 1039.MinimumScoreTriangulationofPolygon.cc 1105.FillingBookcaseShelves.cc 1187.MakeArrayStrictlyIncreasing 1187.MakeArrayStrictlyIncreasing.cc 1223.DiceRollSimulation.cc 123.BestTimetoBuyandSellStockIII 123.BestTimetoBuyandSellStockIII.cc 1269.NumberofWaystoStayintheSamePlaceAfterSomeSteps.cc 1278.PalindromePartitioningIII.cc 1289.MinimumFallingPathSumII 1289.MinimumFallingPathSumII.cc 1320.MinimumDistancetoTypeaWordUsingTwoFingers 1320.MinimumDistancetoTypeaWordUsingTwoFingers.cc 1349.MaximumStudentsTakingExam.cc 1388.PizzaWith3nSlices 1388.PizzaWith3nSlices.cc 1434.NumberofWaystoWearDifferentHatstoEachOther.cc 1444.NumberofWaysofCuttingaPizza.cc 1449.FormLargestIntegerWithDigitsThatAdduptoTarget.cc 1458.MaxDotProductofTwoSubsequences.cc 1473.PaintHouseIII 1473.PaintHouseIII.cc 1477.FindTwoNon-overlappingSub-arraysEachWithTargetSum 1477.FindTwoNon-overlappingSub-arraysEachWithTargetSum.cc 1478.AllocateMailboxes 1478.AllocateMailboxes.cc 1493.LongestSubarrayof1sAfterDeletingOneElement.cc 1510.StoneGameIV 1510.StoneGameIV.cc 1546.MaximumNumberofNon-OverlappingSubarraysWithSumEqualsTarget.cc 1547.MinimumCosttoCutaStick 1547.MinimumCosttoCutaStick.cc 1563.StoneGameV 1563.StoneGameV.cc 1567.MaximumLengthofSubarrayWithPositiveProduct 1567.MaximumLengthofSubarrayWithPositiveProduct.cc 1575.CountAllPossibleRoutes.cc 1594.MaximumNonNegativeProductinaMatrix 1594.MaximumNonNegativeProductinaMatrix.cc 1621.NumberofSetsofKNon-OverlappingLineSegments 1621.NumberofSetsofKNon-OverlappingLineSegments.cc 1626.BestTeamWithNoConflicts 1626.BestTeamWithNoConflicts.cc 1641.CountSortedVowelStrings.cc 1690.StoneGameVII.cc 1691.MaximumHeightbyStackingCuboids.cc 1723.FindMinimumTimetoFinishAllJobs.cc 1745.PalindromePartitioningIV.cc 1751.MaximumNumberofEventsThatCanBeAttendedII.cc 1770.MaximumScorefromPerformingMultiplicationOperations.cc 1771.MaximizePalindromeLengthFromSubsequences.cc 1774.ClosestDessertCost.cc 1799.MaximizeScoreAfterNOperations.cc 1824.MinimumSidewayJumps.cc 1866.NumberofWaystoRearrangeSticksWithKSticksVisible.cc 188.BestTimetoBuyandSellStockIV 188.BestTimetoBuyandSellStockIV.cc 1909.RemoveOneElementtoMaketheArrayStrictlyIncreasing.cc 1928.MinimumCosttoReachDestinationinTime.cc 1947.MaximumCompatibilityScoreSum.cc 1955.CountNumberofSpecialSubsequences 1955.CountNumberofSpecialSubsequences.cc 1986.MinimumNumberofWorkSessionstoFinishtheTasks.cc 1987.NumberofUniqueGoodSubsequences.cc 2054.TwoBestNon-OverlappingEvents 2054.TwoBestNon-OverlappingEvents.cc 2063.VowelsofAllSubstrings.cc 2111.MinimumOperationstoMaketheArrayK-Increasing.cc 2209.MinimumWhiteTilesAfterCoveringWithCarpets.cc 2218.MaximumValueofKCoinsFromPiles 2218.MaximumValueofKCoinsFromPiles.cc 2222.NumberofWaystoSelectBuildings 2222.NumberofWaystoSelectBuildings.cc 2240.NumberofWaystoBuyPensandPencils 2240.NumberofWaystoBuyPensandPencils.cc 2266.CountNumberofTexts 2266.CountNumberofTexts.cc 2272.SubstringWithLargestVariance.cc 2304.MinimumPathCostinaGrid 2304.MinimumPathCostinaGrid.cc 2309.GreatestEnglishLetterinUpperandLowerCase.cc 2312.SellingPiecesofWood.cc 2320.CountNumberofWaystoPlaceHouses 2320.CountNumberofWaystoPlaceHouses.cc 2327.NumberofPeopleAwareofaSecret 2327.NumberofPeopleAwareofaSecret.cc 2369.CheckifThereisaValidPartitionForTheArray.cc 2370.LongestIdealSubsequence.cc 2380.TimeNeededtoRearrangeaBinaryString.cc 2400.NumberofWaystoReachaPositionAfterExactlykSteps.cc 2435.PathsinMatrixWhoseSumIsDivisiblebyK.cc 2463.MinimumTotalDistanceTraveled.cc 2466.CountWaysToBuildGoodStrings.cc 2472.MaximumNumberofNon-overlappingPalindromeSubstrings.cc 2478.NumberofBeautifulPartitions.cc 2518.NumberofGreatPartitions.cc 2538.DifferenceBetweenMaximumandMinimumPriceSum.cc 2547.MinimumCosttoSplitanArray.cc 2556.DisconnectPathinaBinaryMatrixbyatMostOneFlip.cc 256.PaintHouse.cc 2572.CounttheNumberofSquare-FreeSubsets 2572.CounttheNumberofSquare-FreeSubsets.cc 2585.NumberofWaystoEarnPoints 2585.NumberofWaystoEarnPoints.cc 309.BestTimetoBuyandSellStockwithCooldown 309.BestTimetoBuyandSellStockwithCooldown.cc 375.GuessNumberHigherorLowerII 375.GuessNumberHigherorLowerII.cc 446.ArithmeticSlicesII-Subsequence.cc 464.CanIWin 464.CanIWin.cc 576.OutofBoundaryPaths 576.OutofBoundaryPaths.cc 600.Non-negativeIntegerswithoutConsecutiveOnes 600.Non-negativeIntegerswithoutConsecutiveOnes.cc 664.StrangePrinter 664.StrangePrinter.cc 689.MaximumSumof3Non-OverlappingSubarrays.cc 691.StickerstoSpellWord.cc 698.PartitiontoKEqualSumSubsets 698.PartitiontoKEqualSumSubsets.cc 730.CountDifferentPalindromicSubsequences.cc 741.CherryPickup.cc 756.PyramidTransitionMatrix.cc 764.LargestPlusSign 764.LargestPlusSign.cc 787.CheapestFlightsWithinKStops 787.CheapestFlightsWithinKStops.cc 790.DominoandTrominoTiling 790.DominoandTrominoTiling.cc 837.New21Game 837.New21Game.cc 935.KnightDialer.cc 960.DeleteColumnstoMakeSortedIII.cc head.cc head.h head.o lib.a l.sh makefile events.length <= 106
1 <= startDayi <= endDayi <= 109
1 <= valuei <= 106

*/


#include"head.h"
class Solution {
	public:
		int maxValue(vector<vector<int>>& events, int k) {
		const int n=events.size();
		typedef long long ll;

		sort(events.begin(),events.end(),cmp);
		events.insert(events.begin(),vector<int>{0,0,0});
		vector<vector<ll>> dp(n+1,vector<ll>(k+1,0));

		for(int i=1;i<=n;i++)
		{
			int l=0,r=i-1;
			while(l<r)
			{
				int m=(l+r+1)>>1;
				if(events[m][1]>=events[i][0])
					r=m-1;
				else
					l=m;
			}

			for(int j=1;j<=k;j++)
				dp[i][j]=max(dp[i-1][j],dp[l][j-1]+events[i][2]);
		}

		return dp[n][k];
		}
		static bool cmp(const vector<int>&x,const vector<int>&y)
		{
			return x[1]<y[1];
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> v={{1,2,4},{3,4,3},{2,3,1}};
	cout<<s.maxValue(v,2)<<endl;
	v.clear();v={{1,2,4},{3,4,3},{2,3,10}};
	cout<<s.maxValue(v,2)<<endl;
	v.clear();v={{1,1,1},{2,2,2},{3,3,3},{4,4,4}};
	cout<<s.maxValue(v,3)<<endl;
	return 0;
}
