/*
   You are given an array target of n integers. From a starting array arr consisting of n 1's, you may perform the following procedure :

   let x be the sum of all elements currently in your array.
   choose index i, such that 0 <= i < n and set the value of arr at index i to x.
   You may repeat this procedure as many times as needed.

   Return true if it is possible to construct the target array from arr, otherwise, return false.



   Example 1:

Input: target = [9,3,5]
Output: true
Explanation: Start with arr = [1, 1, 1]
[1, 1, 1], sum = 3 choose index 1
[1, 3, 1], sum = 5 choose index 2
[1, 3, 5], sum = 9 choose index 0
[9, 3, 5] Done

Example 2:

Input: target = [1,1,1,2]
Output: false
Explanation: Impossible to create target array from [1,1,1,1].

Example 3:

Input: target = [8,5]
Output: true



Constraints:

n == target.length
1 <= n <= 5 1131.MaximumofAbsoluteValueExpression.cc 1227.AirplaneSeatAssignmentProbability 1227.AirplaneSeatAssignmentProbability.cc 1344.AngleBetweenHandsofaClock 1344.AngleBetweenHandsofaClock.cc 1354.ConstructTargetArrayWithMultipleSums.cc 1362.ClosestDivisors.cc 1551.MinimumOperationstoMakeArrayEqual 1551.MinimumOperationstoMakeArrayEqual.cc 1643.KthSmallestInstructions 1643.KthSmallestInstructions.cc 1685.SumofAbsoluteDifferencesinaSortedArray.cc 1716.CalculateMoneyinLeetcodeBank.cc 1735.CountWaystoMakeArrayWithProduct 1735.CountWaystoMakeArrayWithProduct.cc 1785.MinimumElementstoAddtoFormaGivenSum.cc 1819.NumberofDifferentSubsequencesGCDs 1819.NumberofDifferentSubsequencesGCDs.cc 1862.SumofFlooredPairs 1862.SumofFlooredPairs.cc 1884.EggDropWith2EggsandNFloors 1884.EggDropWith2EggsandNFloors.cc 1969.MinimumNon-ZeroProductoftheArrayElements 1969.MinimumNon-ZeroProductoftheArrayElements.cc 2125.NumberofLaserBeamsinaBank 2125.NumberofLaserBeamsinaBank.cc 2222.NumberofWaystoSelectBuildings 2222.NumberofWaystoSelectBuildings.cc 2224.MinimumNumberofOperationstoConvertTime 2224.MinimumNumberofOperationstoConvertTime.cc 2310.SumofNumbersWithUnitsDigitK 2310.SumofNumbersWithUnitsDigitK.cc 2352.EqualRowandColumnPairs 2352.EqualRowandColumnPairs.cc 2413.SmallestEvenMultiple.cc 2453.DestroySequentialTargets.cc 2470.NumberofSubarraysWithLCMEqualtoK.cc 2481.MinimumCutstoDivideaCircle.cc 2485.FindthePivotInteger.cc 2499.MinimumTotalCosttoMakeArraysUnequal.cc 2507.SmallestValueAfterReplacingWithSumofPrimeFactors.cc 2513.MinimizetheMaximumofTwoArrays 2513.MinimizetheMaximumofTwoArrays.cc 2521.DistinctPrimeFactorsofProductofArray 2521.DistinctPrimeFactorsofProductofArray.cc 2522.PartitionStringIntoSubstringsWithValuesatMostK 2522.PartitionStringIntoSubstringsWithValuesatMostK.cc 2523.ClosestPrimeNumbersinRange 2523.ClosestPrimeNumbersinRange.cc 2543.CheckifPointIsReachable 2543.CheckifPointIsReachable.cc 2544.AlternatingDigitSum 2544.AlternatingDigitSum.cc 2549.CountDistinctNumbersonBoard 2549.CountDistinctNumbersonBoard.cc 2550.CountCollisionsofMonkeysonaPolygon 2550.CountCollisionsofMonkeysonaPolygon.cc 372.SuperPow 372.SuperPow.cc 470.ImplementRand10()UsingRand7().cc 478.GenerateRandomPointinaCircle 478.GenerateRandomPointinaCircle.cc 592.FractionAdditionandSubtraction 592.FractionAdditionandSubtraction.cc 780.ReachingPoints 780.ReachingPoints.cc 883.ProjectionAreaof3DShapes 883.ProjectionAreaof3DShapes.cc 892.SurfaceAreaof3DShapes 892.SurfaceAreaof3DShapes.cc 952.LargestComponentSizebyCommonFactor 952.LargestComponentSizebyCommonFactor.cc head.cc head.h head.o lib.a l.sh makefile 104
1 <= target[i] <= 109

*/


#include"head.h"
class Solution {
    public:
        bool isPossible(vector<int>& target) {
            if(target.size()==1&&target[0]>1)
                return false;

            priority_queue<int> q(target.begin(),target.end());

            long long sum=accumulate(target.begin(),target.end(),0LL);

            while(!q.empty())
            {
                int c=q.top();q.pop();

                if(c==1)
                    return true;

                long long sub=sum-c;

                if(c<=sub) return false;

                int next=c%sub;

                if(next<=0&&sub>1)
                    return false;

                sum=sub+next;
                q.push(next);
            }

            return true;
        }
};


int main() 
{
    Solution s;
    vector<int> v={9,3,5};
    cout<<s.isPossible(v)<<endl;
    v.clear();v={1,1,1,2};
    cout<<s.isPossible(v)<<endl;
    v.clear();v={8,5};
    cout<<s.isPossible(v)<<endl;
    return 0;
}
