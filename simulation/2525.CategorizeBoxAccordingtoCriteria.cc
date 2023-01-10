/*
   Given four integers length, width, height, and mass, representing the dimensions and mass of a box, respectively, return a string representing the category of the box.

   The box is "Bulky" if:
   Any of the dimensions of the box is greater or equal to 104.
   Or, the volume of the box is greater or equal to 109.
   If the mass of the box is greater or equal to 100, it is "Heavy".
   If the box is both "Bulky" and "Heavy", then its category is "Both".
   If the box is neither "Bulky" nor "Heavy", then its category is "Neither".
   If the box is "Bulky" but not "Heavy", then its category is "Bulky".
   If the box is "Heavy" but not "Bulky", then its category is "Heavy".

   Note that the volume of the box is the product of its length, width and height.

    

   Example 1:

Input: length = 1000, width = 35, height = 700, mass = 300
Output: "Heavy"
Explanation:
None of the dimensions of the box is greater or equal to 104.
Its volume = 24500000 <= 109. So it cannot be categorized as "Bulky".
However mass >= 100, so the box is "Heavy".
Since the box is not "Bulky" but "Heavy", we return "Heavy".

Example 2:

Input: length = 200, width = 50, height = 800, mass = 50
Output: "Neither"
Explanation:
None of the dimensions of the box is greater or equal to 104.
Its volume = 8 1030.MatrixCellsinDistanceOrder.cc 1252.CellswithOddValuesinaMatrix.cc 1450.NumberofStudentsDoingHomeworkataGivenTime.cc 1572.MatrixDiagonalSum.cc 1576.ReplaceAllstoAvoidConsecutiveRepeatingCharacters.cc 1592.RearrangeSpacesBetweenWords.cc 1629.SlowestKey.cc 1630.ArithmeticSubarrays.cc 1638.CountSubstringsThatDifferbyOneCharacter.cc 1656.DesignanOrderedStream.cc 165.CompareVersionNumbers.cc 1678.GoalParserInterpretation.cc 1701.AverageWaitingTime.cc 1802.MaximumValueataGivenIndexinaBoundedArray.cc 1904.TheNumberofFullRoundsYouHavePlayed.cc 1974.MinimumTimetoTypeWordUsingSpecialTypewriter.cc 2048.NextGreaterNumericallyBalancedNumber.cc 2114.MaximumNumberofWordsFoundinSentences.cc 2180.CountIntegersWithEvenDigitSum.cc 2185.CountingWordsWithaGivenPrefix.cc 2201.CountArtifactsThatCanBeExtracted.cc 2210.CountHillsandValleysinanArray.cc 2235.AddTwoIntegers.cc 2239.FindClosestNumbertoZero.cc 223.RectangleArea.cc 2243.CalculateDigitSumofaString.cc 2249.CountLatticePointsInsideaCircle.cc 2288.ApplyDiscounttoPrices.cc 2326.SpiralMatrixIV.cc 2432.TheEmployeeThatWorkedontheLongestTask.cc 2446.DetermineifTwoEventsHaveConflict.cc 2455.AverageValueofEvenNumbersThatAreDivisiblebyThree.cc 2469.ConverttheTemperature.cc 2482.DifferenceBetweenOnesandZerosinRowandColumn.cc 2525.CategorizeBoxAccordingtoCriteria.cc 382.LinkedListRandomNode.cc 495.TeemoAttacking.cc 498.DiagonalTraverse.cc 520.DetectCapital.cc 57.InsertInterval.cc 794.ValidTic-Tac-ToeState.cc 799.ChampagneTower.cc 836.RectangleOverlap.cc 929.UniqueEmailAddresses.cc l.sh 106 <= 109. So it cannot be categorized as "Bulky".
Its mass is also less than 100, so it cannot be categorized as "Heavy" either.
Since its neither of the two above categories, we return "Neither".

 

Constraints:

1 <= length, width, height <= 105
1 <= mass <= 103

*/


#include"head.h"
class Solution {
    public:
        string categorizeBox(int length, int width, int height, int mass) {
        typedef long long ll;
        bool bulky=false,heavy=mass>=100;
        if(length>=1e4||width>=1e4||height>=1e4||(ll)length*width*height>=1e9)
            bulky=true;

        if(bulky&&heavy)
            return "Both";
        else if(!bulky&&!heavy)
            return "Neither";
        else if(bulky&&!heavy)
            return "Bulky";

        return "Heavy";
        }
};


int main() 
{
    Solution s;
    cout<<s.categorizeBox(1000,35,700,300)<<endl;
    cout<<s.categorizeBox(200,50,800,50)<<endl;
    return 0;
}
