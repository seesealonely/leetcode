/*
   A teacher is writing a test with n true/false questions, with 'T' denoting true and 'F' denoting false. He wants to confuse the students by maximizing the number of consecutive questions with the same answer (multiple trues or multiple falses in a row).

   You are given a string answerKey, where answerKey[i] is the original answer to the ith question. In addition, you are given an integer k, the maximum number of times you may perform the following operation:

   Change the answer key for any question to 'T' or 'F' (i.e., set answerKey[i] to 'T' or 'F').

   Return the maximum number of consecutive 'T's or 'F's in the answer key after performing the operation at most k times.



   Example 1:

Input: answerKey = "TTFF", k = 2
Output: 4
Explanation: We can replace both the 'F's with 'T's to make answerKey = "TTTT".
There are four consecutive 'T's.

Example 2:

Input: answerKey = "TFFT", k = 1
Output: 3
Explanation: We can replace the first 'T' with an 'F' to make answerKey = "FFFT".
Alternatively, we can replace the second 'T' with an 'F' to make answerKey = "TFFF".
In both cases, there are three consecutive 'F's.

Example 3:

Input: answerKey = "TTFTTFTT", k = 1
Output: 5
Explanation: We can replace the first 'F' to make answerKey = "TTTTTFTT"
Alternatively, we can replace the second 'F' to make answerKey = "TTFTTTTT".
In both cases, there are five consecutive 'T's.



Constraints:

n == answerKey.length
1 <= n <= 5 1023.CamelcaseMatching 1023.CamelcaseMatching.cc 1023.CamelcaseMatching.h 1438.LongestContinuousSubarrayWithAbsoluteDiffLessThanorEqualtoLimit 1438.LongestContinuousSubarrayWithAbsoluteDiffLessThanorEqualtoLimit.cc 1493.LongestSubarrayof1sAfterDeletingOneElement 1493.LongestSubarrayof1sAfterDeletingOneElement.cc 1498.NumberofSubsequencesThatSatisfytheGivenSumCondition 1498.NumberofSubsequencesThatSatisfytheGivenSumCondition.cc 1498.NumberofSubsequencesThatSatisfytheGivenSumCondition.h 1508.RangeSumofSortedSubarraySums 1508.RangeSumofSortedSubarraySums.cc 1508.RangeSumofSortedSubarraySums.h 1537.GettheMaximumScore 1537.GettheMaximumScore.cc 1537.GettheMaximumScore.h 1574.ShortestSubarraytobeRemovedtoMakeArraySorted 1574.ShortestSubarraytobeRemovedtoMakeArraySorted.cc 1574.ShortestSubarraytobeRemovedtoMakeArraySorted.h 1577.NumberofWaysWhereSquareofNumberIsEqualtoProductofTwoNumbers 1577.NumberofWaysWhereSquareofNumberIsEqualtoProductofTwoNumbers.cc 1577.NumberofWaysWhereSquareofNumberIsEqualtoProductofTwoNumbers.h 1888.MinimumNumberofFlipstoMaketheBinaryStringAlternating 1888.MinimumNumberofFlipstoMaketheBinaryStringAlternating.cc 2024.MaximizetheConfusionofanExam.cc 2058.FindtheMinimumandMaximumNumberofNodesBetweenCriticalPoints 2058.FindtheMinimumandMaximumNumberofNodesBetweenCriticalPoints.cc 2058.FindtheMinimumandMaximumNumberofNodesBetweenCriticalPoints.h 2074.ReverseNodesinEvenLengthGroups 2074.ReverseNodesinEvenLengthGroups.cc 2074.ReverseNodesinEvenLengthGroups.h 2095.DeletetheMiddleNodeofaLinkedList 2095.DeletetheMiddleNodeofaLinkedList.cc 2095.DeletetheMiddleNodeofaLinkedList.h 2106.MaximumFruitsHarvestedAfteratMostKSteps 2106.MaximumFruitsHarvestedAfteratMostKSteps.cc 2106.MaximumFruitsHarvestedAfteratMostKSteps.h 2108.FindFirstPalindromicStringintheArray 2108.FindFirstPalindromicStringintheArray.cc 2108.FindFirstPalindromicStringintheArray.h 475.Heaters 475.Heaters.cc 475.Heaters.h 522.LongestUncommonSubsequenceII 522.LongestUncommonSubsequenceII.cc 522.LongestUncommonSubsequenceII.h 825.FriendsOfAppropriateAges 825.FriendsOfAppropriateAges.cc 825.FriendsOfAppropriateAges.h 838.PushDominoes 838.PushDominoes.cc 838.PushDominoes.h head.cc head.h head.o lib.a l.sh makefile 104
answerKey[i] is either 'T' or 'F'
1 <= k <= n

*/
#include"head.h"
class Solution {
	public:
		int maxConsecutiveAnswers(string answerKey, int k) {
			const int n=answerKey.size();
			int l=0,r=0,res=0,countT=0,countF=0;
			while(r<n)
			{
				answerKey[r]=='T'?countT++:countF++;
				while(countT>k&&countF>k)
				{
					if(answerKey[l]=='T')
						countT--;
					else
						countF--;
					l++;
				}	
				res=max(res,r-l+1);
				r++;
			}
			return res;
		}
};
int main() 
{
	Solution s;
	cout<<s.maxConsecutiveAnswers("TTFF",2)<<endl;
	cout<<s.maxConsecutiveAnswers("TFFT",1)<<endl;
	cout<<s.maxConsecutiveAnswers("TTFTTFTT",1)<<endl;
	return 0;
}
