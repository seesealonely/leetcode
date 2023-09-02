/*
   You are given an integer array nums and two positive integers m and k.

   Return the maximum sum out of all almost unique subarrays of length k of nums. If no such subarray exists, return 0.

   A subarray of nums is almost unique if it contains at least m distinct elements.

   A subarray is a contiguous non-empty sequence of elements within an array.



   Example 1:

Input: nums = [2,6,7,3,1,7], m = 3, k = 4
Output: 18
Explanation: There are 3 almost unique subarrays of size k = 4. These subarrays are [2, 6, 7, 3], [6, 7, 3, 1], and [7, 3, 1, 7]. Among these subarrays, the one with the maximum sum is [2, 6, 7, 3] which has a sum of 18.

Example 2:

Input: nums = [5,9,9,2,4,5,4], m = 1, k = 3
Output: 23
Explanation: There are 5 almost unique subarrays of size k. These subarrays are [5, 9, 9], [9, 9, 2], [9, 2, 4], [2, 4, 5], and [4, 5, 4]. Among these subarrays, the one with the maximum sum is [5, 9, 9] which has a sum of 23.

Example 3:

Input: nums = [1,2,1,2,1,2,1], m = 3, k = 3
Output: 0
Explanation: There are no subarrays of size k = 3 that contain at least m = 3 distinct elements in the given array [1,2,1,2,1,2,1]. Therefore, no almost unique subarrays exist, and the maximum sum is 0.



Constraints:

1 <= nums.length <= 2 1234.ReplacetheSubstringforBalancedString.cc 1268.SearchSuggestionsSystem 1268.SearchSuggestionsSystem.cc 1521.FindaValueofaMysteriousFunctionClosesttoTarget 1521.FindaValueofaMysteriousFunctionClosesttoTarget.cc 1695.MaximumErasureValue 1695.MaximumErasureValue.cc 1704.DetermineifStringHalvesAreAlike.cc 1712.WaystoSplitArrayIntoThreeSubarrays.cc 1739.BuildingBoxes 1739.BuildingBoxes.cc 1782.CountPairsOfNodes 1782.CountPairsOfNodes.cc 1839.LongestSubstringOfAllVowelsinOrder.cc 1855.MaximumDistanceBetweenaPairofValues.cc 1960.MaximumProductoftheLengthofTwoPalindromicSubstrings 1960.MaximumProductoftheLengthofTwoPalindromicSubstrings.cc 2106.MaximumFruitsHarvestedAfteratMostKSteps.cc 2122.RecovertheOriginalArray.cc 2129.CapitalizetheTitle.cc 2156.FindSubstringWithGivenHashValue.cc 2200.FindAllK-DistantIndicesinanArray.cc 2264.Largest3-Same-DigitNumberinString.cc 2271.MaximumWhiteTilesCoveredbyaCarpet.cc 2302.CountSubarraysWithScoreLessThanK.cc 2337.MovePiecestoObtainaString.cc 2379.MinimumRecolorstoGetKConsecutiveBlackBlocks.cc 2398.MaximumNumberofRobotsWithinBudget 2398.MaximumNumberofRobotsWithinBudget.cc 2414.LengthoftheLongestAlphabeticalContinuousSubstring.cc 2444.CountSubarraysWithFixedBounds.cc 2537.CounttheNumberofGoodSubarrays 2537.CounttheNumberofGoodSubarrays.cc 2555.MaximizeWinFromTwoSegments 2555.MaximizeWinFromTwoSegments.cc 2563.CounttheNumberofFairPairs 2563.CounttheNumberofFairPairs.cc 2609.FindtheLongestBalancedSubstringofaBinaryString 2609.FindtheLongestBalancedSubstringofaBinaryString.cc 2730.FindtheLongestSemi-RepetitiveSubstring 2730.FindtheLongestSemi-RepetitiveSubstring.cc 2747.CountZeroRequestServers 2747.CountZeroRequestServers.cc 2760.LongestEvenOddSubarrayWithThreshold 2760.LongestEvenOddSubarrayWithThreshold.cc 2762.ContinuousSubarrays 2762.ContinuousSubarrays.cc 2765.LongestAlternatingSubarray 2765.LongestAlternatingSubarray.cc 2781.LengthoftheLongestValidSubstring 2781.LengthoftheLongestValidSubstring.cc 2799.CountCompleteSubarraysinanArray 2799.CountCompleteSubarraysinanArray.cc 2825.MakeStringaSubsequenceUsingCyclicIncrements 2825.MakeStringaSubsequenceUsingCyclicIncrements.cc 2831.FindtheLongestEqualSubarray 2831.FindtheLongestEqualSubarray.cc 2841.MaximumSumofAlmostUniqueSubarray.cc 632.SmallestRangeCoveringElementsfromKLists 632.SmallestRangeCoveringElementsfromKLists.cc 927.ThreeEqualParts 927.ThreeEqualParts.cc 992.SubarrayswithKDifferentIntegers 992.SubarrayswithKDifferentIntegers.cc head.cc head.h head.o lib.a l.sh makefile 104
1 <= m <= k <= nums.length
1 <= nums[i] <= 109

*/


#include"head.h"
class Solution {
	public:
		long long maxSum(vector<int>& nums, int m, int k) {
		const int n=nums.size();
		long long res=0,sum=0;
		unordered_map<int,int> vis;

		for(int i=0;i<k-1;i++)
		{
			++vis[nums[i]];
			sum+=nums[i];
		}

		for(int i=k-1;i<n;i++)
		{
			++vis[nums[i]];
			sum+=nums[i];
			if(vis.size()>=m)
				res=max(res,sum);
			int pre=nums[i-k+1];
			sum-=pre;
			if(--vis[pre]==0)
				vis.erase(pre);
		}
		return res;
		}
};


int main() 
{
	Solution s;
	vector<int> nums = {2,6,7,3,1,7};
	cout<<s.maxSum(nums,3,4)<<endl;
	nums.clear();nums={5,9,9,2,4,5,4};
	cout<<s.maxSum(nums,1,3)<<endl;
	nums.clear();nums={1,2,1,2,1,2,1};
	cout<<s.maxSum(nums,3,3)<<endl;
	return 0;
}
