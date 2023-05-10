/*
   HTML entity parser is the parser that takes HTML code as input and replace all the entities of the special characters by the characters itself.

   The special characters and their entities for HTML are:

   Quotation Mark: the entity is &quot; and symbol character is ".
   Single Quote Mark: the entity is &apos; and symbol character is '.
Ampersand: the entity is &amp; and symbol character is &.
Greater Than Sign: the entity is &gt; and symbol character is >.
Less Than Sign: the entity is &lt; and symbol character is <.
Slash: the entity is &frasl; and symbol character is /.

Given the input text string to the HTML parser, you have to implement the entity parser.

Return the text after replacing the entities by the special characters.



Example 1:

Input: text = "&amp; is an HTML entity but &ambassador; is not."
Output: "& is an HTML entity but &ambassador; is not."
Explanation: The parser will replace the &amp; entity by &

Example 2:

Input: text = "and I quote: &quot;...&quot;"
Output: "and I quote: "...""



Constraints:

1 <= text.length <= 105
The string may contain any possible characters out of all the 256 ASCII characters.

*/


#include"head.h"
class Solution {
	public:
		bool check(const string &s,int idx,const string &p)
		{
			if(s.size()-idx<p.size())
				return false;

			for(int i=0;i<p.size();i++,idx++)
				if(s[idx]!=p[i])
					return false;
			return true;
		}
		string entityParser(string text) {
		const int n=text.size();
		int j=0;

		for(int i=0;i<n;i++)
		{
			if(text[i]!='&')
			{
				text[j++]=text[i];
				continue;
			}

			if(check(text,i+1,"quot;"))
			{
				text[j++]='"';
				i+=5;
			}
			else if(check(text,i+1,"apos;"))
			{
				text[j++]='\'';
				i+=5;
			}
			else if(check(text,i+1,"amp;"))
			{
				text[j++]='&';
				i+=4;
			}
			else if(check(text,i+1,"gt;"))
			{
				text[j++]='>';
				i+=3;
			}
			else if(check(text,i+1,"lt;"))
			{
				text[j++]='<';
				i+=3;
			}
			else if(check(text,i+1,"frasl;"))
			{
				text[j++]='/';
				i+=6;
			}
			else
				text[j++]='&';
		}

		text.resize(j);
		return text;
		}
};


int main() 
{
	Solution s;
	cout<<s.entityParser( "&amp; is an HTML entity but &ambassador; is not.")<<endl;
	cout<<s.entityParser(  "and I quote: &quot;...&quot;")<<endl;
	return 0;
}
