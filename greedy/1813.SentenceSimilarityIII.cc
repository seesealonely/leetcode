/*
   A sentence is a list of words that are separated by a single space with no leading or trailing spaces. For example, "Hello World", "HELLO", "hello world hello world" are all sentences. Words consist of only uppercase and lowercase English letters.

   Two sentences sentence1 and sentence2 are similar if it is possible to insert an arbitrary sentence (possibly empty) inside one of these sentences such that the two sentences become equal. For example, sentence1 = "Hello my name is Jane" and sentence2 = "Hello Jane" can be made equal by inserting "my name is" between "Hello" and "Jane" in sentence2.

   Given two sentences sentence1 and sentence2, return true if sentence1 and sentence2 are similar. Otherwise, return false.



   Example 1:

Input: sentence1 = "My name is Haley", sentence2 = "My Haley"
Output: true
Explanation: sentence2 can be turned to sentence1 by inserting "name is" between "My" and "Haley".

Example 2:

Input: sentence1 = "of", sentence2 = "A lot of words"
Output: false
Explanation: No single sentence can be inserted inside one of the sentences to make it equal to the other.

Example 3:

Input: sentence1 = "Eating right now", sentence2 = "Eating"
Output: true
Explanation: sentence2 can be turned to sentence1 by inserting "right now" at the end of the sentence.



Constraints:

1 <= sentence1.length, sentence2.length <= 100
sentence1 and sentence2 consist of lowercase and uppercase English letters and spaces.
The words in sentence1 and sentence2 are separated by a single space.

*/


#include"head.h"
class Solution {
	public:
		bool areSentencesSimilar(string sentence1, string sentence2) {
		if(sentence1.size()>sentence2.size()) return areSentencesSimilar(sentence2,sentence1);
		vector<string> a=cut(sentence1),b=cut(sentence2);
		int l1=a.size(),l2=b.size(),l=0,r=0;
		while(l<l1&&a[l]==b[l]) l++;
		while(r+l<l1&&a[l1-r-1]==b[l2-r-1]) r++;
		return l+r==l1;
		}
		vector<string> cut(string s)
		{
			vector<string> res;
			stringstream ss;
			ss<<s;
			while(ss>>s) res.push_back(s);
			return res;
		}
};


int main() 
{
	Solution s;
	cout<<s.areSentencesSimilar("My name is Haley","My Haley")<<endl;
	cout<<s.areSentencesSimilar("of", "My Haley")<<endl;
	cout<<s.areSentencesSimilar("Eating right now","Eating")<<endl;
	return 0;
}
