/*
   There is an undirected tree with n nodes labeled from 0 to n - 1, and rooted at node 0. You are given a 2D integer array edges of length n - 1, where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

   You are also given a 0-indexed integer array values of length n, where values[i] is the value associated with the ith node.

   You start with a score of 0. In one operation, you can:

   Pick any node i.
   Add values[i] to your score.
   Set values[i] to 0.

   A tree is healthy if the sum of values on the path from the root to any leaf node is different than zero.

   Return the maximum score you can obtain after performing these operations on the tree any number of times so that it remains healthy.



   Example 1:

Input: edges = [[0,1],[0,2],[0,3],[2,4],[4,5]], values = [5,2,5,2,1,1]
Output: 11
Explanation: We can choose nodes 1, 2, 3, 4, and 5. The value of the root is non-zero. Hence, the sum of values on the path from the root to any leaf is different than zero. Therefore, the tree is healthy and the score is values[1] + values[2] + values[3] + values[4] + values[5] = 11.
It can be shown that 11 is the maximum score obtainable after any number of operations on the tree.

Example 2:

Input: edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]], values = [20,10,9,7,4,3,5]
Output: 40
Explanation: We can choose nodes 0, 2, 3, and 4.
- The sum of values on the path from 0 to 4 is equal to 10.
- The sum of values on the path from 0 to 3 is equal to 10.
- The sum of values on the path from 0 to 5 is equal to 3.
- The sum of values on the path from 0 to 6 is equal to 5.
Therefore, the tree is healthy and the score is values[0] + values[2] + values[3] + values[4] = 40.
It can be shown that 40 is the maximum score obtainable after any number of operations on the tree.



Constraints:

2 <= n <= 2 \ 1027.LongestArithmeticSubsequence 1027.LongestArithmeticSubsequence.cc 1039.MinimumScoreTriangulationofPolygon.cc 10.RegularExpressionMatching 10.RegularExpressionMatching.cc 1105.FillingBookcaseShelves.cc 1125.SmallestSufficientTeam 1125.SmallestSufficientTeam.cc 1187.MakeArrayStrictlyIncreasing 1187.MakeArrayStrictlyIncreasing.cc 1220.CountVowelsPermutation 1220.CountVowelsPermutation.cc 1223.DiceRollSimulation.cc 123.BestTimetoBuyandSellStockIII 123.BestTimetoBuyandSellStockIII.cc 1269.NumberofWaystoStayintheSamePlaceAfterSomeSteps.cc 1278.PalindromePartitioningIII.cc 1289.MinimumFallingPathSumII 1289.MinimumFallingPathSumII.cc 1301.NumberofPathswithMaxScore 1301.NumberofPathswithMaxScore.cc 1320.MinimumDistancetoTypeaWordUsingTwoFingers 1320.MinimumDistancetoTypeaWordUsingTwoFingers.cc 1335.MinimumDifficultyofaJobSchedule 1335.MinimumDifficultyofaJobSchedule.cc 1349.MaximumStudentsTakingExam.cc 1388.PizzaWith3nSlices 1388.PizzaWith3nSlices.cc 1411.NumberofWaystoPaintN×3Grid 1411.NumberofWaystoPaintN×3Grid.cc 1420.BuildArrayWhereYouCanFindTheMaximumExactlyKComparisons 1420.BuildArrayWhereYouCanFindTheMaximumExactlyKComparisons.cc 1425.ConstrainedSubsequenceSum 1425.ConstrainedSubsequenceSum.cc 1434.NumberofWaystoWearDifferentHatstoEachOther.cc 1444.NumberofWaysofCuttingaPizza.cc 1449.FormLargestIntegerWithDigitsThatAdduptoTarget.cc 1458.MaxDotProductofTwoSubsequences.cc 1463.CherryPickupII 1463.CherryPickupII.cc 1473.PaintHouseIII 1473.PaintHouseIII.cc 1477.FindTwoNon-overlappingSub-arraysEachWithTargetSum 1477.FindTwoNon-overlappingSub-arraysEachWithTargetSum.cc 1478.AllocateMailboxes 1478.AllocateMailboxes.cc 1493.LongestSubarrayof1sAfterDeletingOneElement.cc 1494.ParallelCoursesII 1494.ParallelCoursesII.cc 1510.StoneGameIV 1510.StoneGameIV.cc 1531.StringCompressionII 1531.StringCompressionII.cc 1546.MaximumNumberofNon-OverlappingSubarraysWithSumEqualsTarget.cc 1547.MinimumCosttoCutaStick 1547.MinimumCosttoCutaStick.cc 1563.StoneGameV 1563.StoneGameV.cc 1567.MaximumLengthofSubarrayWithPositiveProduct 1567.MaximumLengthofSubarrayWithPositiveProduct.cc 1575.CountAllPossibleRoutes.cc 1594.MaximumNonNegativeProductinaMatrix 1594.MaximumNonNegativeProductinaMatrix.cc 1595.MinimumCosttoConnectTwoGroupsofPoints 1595.MinimumCosttoConnectTwoGroupsofPoints.cc 1621.NumberofSetsofKNon-OverlappingLineSegments 1621.NumberofSetsofKNon-OverlappingLineSegments.cc 1626.BestTeamWithNoConflicts 1626.BestTeamWithNoConflicts.cc 1639.NumberofWaystoFormaTargetStringGivenaDictionary 1639.NumberofWaystoFormaTargetStringGivenaDictionary.cc 1641.CountSortedVowelStrings.cc 1655.DistributeRepeatingIntegers 1655.DistributeRepeatingIntegers.cc 1659.MaximizeGridHappiness 1659.MaximizeGridHappiness.cc 1687.DeliveringBoxesfromStoragetoPorts 1687.DeliveringBoxesfromStoragetoPorts.cc 1690.StoneGameVII.cc 1691.MaximumHeightbyStackingCuboids.cc 1723.FindMinimumTimetoFinishAllJobs.cc 1735.CountWaystoMakeArrayWithProduct 1735.CountWaystoMakeArrayWithProduct.cc 1745.PalindromePartitioningIV.cc 1751.MaximumNumberofEventsThatCanBeAttendedII 1751.MaximumNumberofEventsThatCanBeAttendedII.cc 1770.MaximumScorefromPerformingMultiplicationOperations.cc 1771.MaximizePalindromeLengthFromSubsequences.cc 1774.ClosestDessertCost.cc 1787.MaketheXORofAllSegmentsEqualtoZero 1787.MaketheXORofAllSegmentsEqualtoZero.cc 1799.MaximizeScoreAfterNOperations.cc 1824.MinimumSidewayJumps.cc 1866.NumberofWaystoRearrangeSticksWithKSticksVisible.cc 1872.StoneGameVIII 1872.StoneGameVIII.cc 1883.MinimumSkipstoArriveatMeetingOnTime 1883.MinimumSkipstoArriveatMeetingOnTime.cc 188.BestTimetoBuyandSellStockIV 188.BestTimetoBuyandSellStockIV.cc 1896.MinimumCosttoChangetheFinalValueofExpression 1896.MinimumCosttoChangetheFinalValueofExpression.cc 1909.RemoveOneElementtoMaketheArrayStrictlyIncreasing.cc 1928.MinimumCosttoReachDestinationinTime.cc 1931.PaintingaGridWithThreeDifferentColors 1931.PaintingaGridWithThreeDifferentColors.cc 1947.MaximumCompatibilityScoreSum.cc 1955.CountNumberofSpecialSubsequences 1955.CountNumberofSpecialSubsequences.cc 1959.MinimumTotalSpaceWastedWithKResizingOperations 1959.MinimumTotalSpaceWastedWithKResizingOperations.cc 1977.NumberofWaystoSeparateNumbers 1977.NumberofWaystoSeparateNumbers.cc 1986.MinimumNumberofWorkSessionstoFinishtheTasks.cc 1987.NumberofUniqueGoodSubsequences.cc 1994.TheNumberofGoodSubsets 1994.TheNumberofGoodSubsets.cc 2019.TheScoreofStudentsSolvingMathExpression 2019.TheScoreofStudentsSolvingMathExpression.cc 2054.TwoBestNon-OverlappingEvents 2054.TwoBestNon-OverlappingEvents.cc 2060.CheckifanOriginalStringExistsGivenTwoEncodedStrings 2060.CheckifanOriginalStringExistsGivenTwoEncodedStrings.cc 2063.VowelsofAllSubstrings.cc 2111.MinimumOperationstoMaketheArrayK-Increasing.cc 2127.MaximumEmployeestoBeInvitedtoaMeeting.cc 2172.MaximumANDSumofArray 2172.MaximumANDSumofArray.cc 2188.MinimumTimetoFinishtheRace 2188.MinimumTimetoFinishtheRace.cc 2209.MinimumWhiteTilesAfterCoveringWithCarpets.cc 2218.MaximumValueofKCoinsFromPiles 2218.MaximumValueofKCoinsFromPiles.cc 2222.NumberofWaystoSelectBuildings 2222.NumberofWaystoSelectBuildings.cc 2240.NumberofWaystoBuyPensandPencils 2240.NumberofWaystoBuyPensandPencils.cc 2266.CountNumberofTexts 2266.CountNumberofTexts.cc 2272.SubstringWithLargestVariance.cc 2304.MinimumPathCostinaGrid 2304.MinimumPathCostinaGrid.cc 2309.GreatestEnglishLetterinUpperandLowerCase.cc 2312.SellingPiecesofWood.cc 2320.CountNumberofWaystoPlaceHouses 2320.CountNumberofWaystoPlaceHouses.cc 2327.NumberofPeopleAwareofaSecret 2327.NumberofPeopleAwareofaSecret.cc 2338.CounttheNumberofIdealArrays 2338.CounttheNumberofIdealArrays.cc 233.NumberofDigitOne 233.NumberofDigitOne.cc 2369.CheckifThereisaValidPartitionForTheArray.cc 2370.LongestIdealSubsequence.cc 2380.TimeNeededtoRearrangeaBinaryString.cc 2400.NumberofWaystoReachaPositionAfterExactlykSteps.cc 2435.PathsinMatrixWhoseSumIsDivisiblebyK.cc 2463.MinimumTotalDistanceTraveled.cc 2466.CountWaysToBuildGoodStrings.cc 2472.MaximumNumberofNon-overlappingPalindromeSubstrings.cc 2478.NumberofBeautifulPartitions.cc 2518.NumberofGreatPartitions.cc 2538.DifferenceBetweenMaximumandMinimumPriceSum.cc 2547.MinimumCosttoSplitanArray.cc 2556.DisconnectPathinaBinaryMatrixbyatMostOneFlip.cc 256.PaintHouse.cc 2572.CounttheNumberofSquare-FreeSubsets 2572.CounttheNumberofSquare-FreeSubsets.cc 2585.NumberofWaystoEarnPoints 2585.NumberofWaystoEarnPoints.cc 2680.MaximumOR 2680.MaximumOR.cc 2684.MaximumNumberofMovesinaGrid 2684.MaximumNumberofMovesinaGrid.cc 2707.ExtraCharactersinaString 2707.ExtraCharactersinaString.cc 2713.MaximumStrictlyIncreasingCellsinaMatrix 2713.MaximumStrictlyIncreasingCellsinaMatrix.cc 2741.SpecialPermutations 2741.SpecialPermutations.cc 2742.PaintingtheWalls 2742.PaintingtheWalls.cc 2746.DecrementalStringConcatenation 2746.DecrementalStringConcatenation.cc 2770.MaximumNumberofJumpstoReachtheLastIndex 2770.MaximumNumberofJumpstoReachtheLastIndex.cc 2771.LongestNon-decreasingSubarrayFromTwoArrays 2771.LongestNon-decreasingSubarrayFromTwoArrays.cc 2784.CheckifArrayisGood 2786.VisitArrayPositionstoMaximizeScore 2786.VisitArrayPositionstoMaximizeScore.cc 2787.WaystoExpressanIntegerasSumofPowers 2787.WaystoExpressanIntegerasSumofPowers.cc 2809.MinimumTimetoMakeArraySumAtMostx 2809.MinimumTimetoMakeArraySumAtMostx.cc 2826.SortingThreeGroups 2826.SortingThreeGroups.cc 2827.NumberofBeautifulIntegersintheRange 2827.NumberofBeautifulIntegersintheRange.cc 2830.MaximizetheProfitastheSalesman 2830.MaximizetheProfitastheSalesman.cc 2850.MinimumMovestoSpreadStonesOverGrid 2850.MinimumMovestoSpreadStonesOverGrid.cc 2851.StringTransformation 2851.StringTransformation.cc 2867.CountValidPathsinaTree 2867.CountValidPathsinaTree.cc 2896.ApplyOperationstoMakeTwoStringsEqual 2896.ApplyOperationstoMakeTwoStringsEqual.cc 2900.LongestUnequalAdjacentGroupsSubsequenceI 2900.LongestUnequalAdjacentGroupsSubsequenceI.cc 2901.LongestUnequalAdjacentGroupsSubsequenceII 2901.LongestUnequalAdjacentGroupsSubsequenceII.cc 2911.MinimumChangestoMakeKSemi-palindromes 2911.MinimumChangestoMakeKSemi-palindromes.cc 2915.LengthoftheLongestSubsequenceThatSumstoTarget 2915.LengthoftheLongestSubsequenceThatSumstoTarget.cc 2919.MinimumIncrementOperationstoMakeArrayBeautiful 2919.MinimumIncrementOperationstoMakeArrayBeautiful.cc 2920.MaximumPointsAfterCollectingCoinsFromAllNodes 2920.MaximumPointsAfterCollectingCoinsFromAllNodes.cc 2925.MaximumScoreAfterApplyingOperationsonaTree.cc 309.BestTimetoBuyandSellStockwithCooldown 309.BestTimetoBuyandSellStockwithCooldown.cc 375.GuessNumberHigherorLowerII 375.GuessNumberHigherorLowerII.cc 446.ArithmeticSlicesII-Subsequence.cc 464.CanIWin 464.CanIWin.cc 466.CountTheRepetitions 466.CountTheRepetitions.cc 514.FreedomTrail 514.FreedomTrail.cc 546.RemoveBoxes 546.RemoveBoxes.cc 552.StudentAttendanceRecordII 552.StudentAttendanceRecordII.cc 576.OutofBoundaryPaths 576.OutofBoundaryPaths.cc 600.Non-negativeIntegerswithoutConsecutiveOnes 600.Non-negativeIntegerswithoutConsecutiveOnes.cc 629.KInversePairsArray 629.KInversePairsArray.cc 639.DecodeWaysII 639.DecodeWaysII.cc 664.StrangePrinter 664.StrangePrinter.cc 689.MaximumSumof3Non-OverlappingSubarrays.cc 691.StickerstoSpellWord.cc 698.PartitiontoKEqualSumSubsets 698.PartitiontoKEqualSumSubsets.cc 730.CountDifferentPalindromicSubsequences.cc 741.CherryPickup.cc 756.PyramidTransitionMatrix.cc 764.LargestPlusSign 764.LargestPlusSign.cc 787.CheapestFlightsWithinKStops 787.CheapestFlightsWithinKStops.cc 790.DominoandTrominoTiling 790.DominoandTrominoTiling.cc 808.SoupServings 808.SoupServings.cc 837.New21Game 837.New21Game.cc 879.ProfitableSchemes 879.ProfitableSchemes.cc 87.ScrambleString 87.ScrambleString.cc 887.SuperEggDrop 887.SuperEggDrop.cc 903.ValidPermutationsforDISequence 903.ValidPermutationsforDISequence.cc 913.CatandMouse 913.CatandMouse.cc 935.KnightDialer.cc 940.DistinctSubsequencesII 940.DistinctSubsequencesII.cc 943.FindtheShortestSuperstring 943.FindtheShortestSuperstring.cc 956.TallestBillboard 956.TallestBillboard.cc 960.DeleteColumnstoMakeSortedIII.cc head.cc head.h head.o lib.a l.sh makefile 104
edges.length == n - 1
edges[i].length == 2
0 <= ai, bi < n
values.length == n
1 <= values[i] <= 109
The input is generated such that edges represents a valid tree.

*/


#include"head.h"
class Solution {
	public:
		typedef long long ll;
		long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
		const int n=values.size();
		g.resize(n);
		dp.resize(n);
		sum.resize(n);

		for(int i=0;i<edges.size();i++)
		{
			int u=edges[i][0],v=edges[i][1];
			g[u].push_back(v);
			g[v].push_back(u);
		}

		dfs(0,-1,values);
		return dp[0];
		}
		void  dfs(int u,int pa,const vector<int> &values)
		{
			sum[u]=values[u];
			dp[u]=0;
			bool leaf=true;
			for(int i=0;i<g[u].size();i++)
			{
				int v=g[u][i];
				if(v==pa)
					continue;

				dfs(v,u,values);
				sum[u]+=sum[v];
				dp[u]+=dp[v];
				leaf=false;
			}
			if(leaf==false)
				dp[u]=max(dp[u]+values[u],sum[u]-values[u]);
		}
	private:
		vector<vector<int>> g;
		vector<ll> dp,sum;
};


int main() 
{
	Solution s;
	vector<vector<int>> edges=edges = {{0,1},{0,2},{0,3},{2,4},{4,5}};
	vector<int> values={5,2,5,2,1,1};
	cout<<s.maximumScoreAfterOperations(edges,values)<<endl;
	edges.clear();edges=edges = {{0,1},{0,2},{1,3},{1,4},{2,5},{2,6}};
	values.clear();values={20,10,9,7,4,3,5};
	cout<<s.maximumScoreAfterOperations(edges,values)<<endl;
	return 0;
}
