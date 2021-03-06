/*
   All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

   Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

   For example,

   Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].

*/
#include"187.RepeatedDNASequences.h"
int main()
{
	Solution s;
//show(s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"));
show(s.findRepeatedDnaSequences("AAGATCCGTCCCCCCAAGATCCGTC"));
	return 0;
}
