/*
   Return the number of distinct non-empty substrings of text that can be written as the concatenation of some string with itself (i.e. it can be written as a + a where a is some string).



   Example 1:

Input: text = "abcabcabc"
Output: 3
Explanation: The 3 substrings are "abcabc", "bcabca" and "cabcab".

Example 2:

Input: text = "leetcodeleetcode"
Output: 2
Explanation: The 2 substrings are "ee" and "leetcodeleetcode".



Constraints:

1 <= text.length <= 2000
text has only lowercase English letters.

*/

#define c11
#include"head.h"
class Solution {
    public:
        #define ULL unsigned long long 
        int distinctEchoSubstrings(string text) {
        const int base=131,n=text.size();

        vector<ULL> h(n+1,0),power(n+1,0);

        power[0]=1;
        for(int i=1;i<=n;i++)
        {
            h[i]=h[i-1]*base+text[i-1]-'a'+1;
            power[i]=power[i-1]*base;
        }

        unordered_set<ULL> s;
        for(int len=2;len<=n;len+=2)
            for(int i=1;i<=n-len+1;i++)
            {
                ULL h1=hash(h,power,i,len/2);
                ULL h2=hash(h,power,i+len/2,len/2);
                
                if(h1==h2&&s.find(h1)==s.end())
                    s.insert(h1);
            }

        return s.size();
        }

        ULL hash(const vector<ULL> &h,const vector<ULL> &power,int start,int len)
        {
            return h[start+len-1]-h[start-1]*power[len];
        }
};


int main() 
{
    Solution s;
    cout<<s.distinctEchoSubstrings("abcabcabc")<<endl;
    cout<<s.distinctEchoSubstrings("leetcodeleetcode")<<endl;
    cout<<s.distinctEchoSubstrings("wdyihepunnmlqjkpnrrzjdnysubneoiafptyurqyoiglsodisssyouhcjpwvdwfnboodwukaizlsifotxxavqybwmxpanaswhhfikcucnmdeqiyttkdqyhomzpfasrmmiurrouxbotovucdmqesiyrdkhlxbnbowwuetdyzhbkimokqqpwhdlxxdbktstkvseiylcrfgmyiatkjqsuwhbkbxuatiolxnhespqvgppzczakrzvhmkxakyipjtsaiyfbxwgrbqqfdrebrtryxdzghlnqgttldoiwezugexbdqikooyccjbflfmowgugwnizlmbtlruldgjriyngfhcigonvdgtjclopdzzwslglnwxjnxepcxcxwofmnkbkpcntxxmoomluhzkjidzxbchtbctinlqrlgihrnppvvqhkeasftmsijgqgntpoxsfszuzpvhvrxbxpfqrlgafxssaiyiismmjiuopbslrdxdzcnupdaeprmgzujmznhmecpzppbkjhlueynamrjgpxqwsvoyyhbmtnexylmfuemcduusueuxpsgfooultqfeuzhlxiyjquagryzsxpabbtmmypbgjzqewsrvtnxvmoamnuamixublfcxlecdpjpdmcztdrygvukldkiooenwkuqkmgllhppvqiqbawddynaqaejvqaqdeuwtqtcfxvbydhiwkrkekazxaftzeqrwsjqrrtorjfsonshmkzwdvexfobceyclpurtdaotjoozawhhvxkesbnauvbfafrvoewmxamxsxdkvhfywfzqbwnuoyqotmyuyveuallhrwuwimuefmzprwmwhasarytunalgebijmlupxchiiqvzeeelprgwbdsgwnjzjhkvehlsgwynuocjhtjehuidszgqbiuvhtbxsegogbffekerpidkuqqvmpwlsaneqanzwwqdjvskamjmdrjzwkugzvppfenlbrapsnnaozqiwqatkqqnfmnxbdgfztoticwvjzcwolzcrucposxjacpafzbvbcmgugtpdkqfdyrpjxnzpnycbqqxwrvnpoerkutiucekgyfyddfpddqegauyuaarmqarwizvswquybdhirqincciydlqeuvlkiivqudnyuqsgrquiupwhpgvwltwzsqtiaqixnvtvqgbsmauditfeqevpinlxmdmjsnczuukbihgovjnejeknwywnneuhjtumujlhpeikfvnbscwmfzhltswbnqkqkrqfqfdzyvnlcpuevhjcyglshlvblochtqcfjjeqeowkowtwoysvvzraxgmvaeuogoahndfgzwohqbiuhlofablccghrcahygjhjiboufjhtznxxdewlsagxhbjmqrygvkikpnoxuubzwqjrnprzpggreqfpawnynqmmzkhexjjcrhzckgfmpkwyuwsqkspjylnzteirhqlbnecejifjliygjxoepvzterssaplerwbnppbivevuhsxuiczmyiuvdsovqnrazsuyuufiaksphalquhoxwwsmoyicmklqcqstorqhemmqsnwfcaznodlogqwhgdkvfnxkgwmlidtxfoulzqbpxjdrzmfgnvcvghwwtznqkvxtcvpfhxykqwclocogyqqdqbjoqvrwgxrflnnzealdadyayxxpnyhkkiueejbysiggloswuydlpvskkdcytwbbdkcmtpzrglxgxilmnkkqxzweimvrcqflqjmcweqbjztwuutzqnninjremjrshckfcycxhgxxpbzulubrjhiiighpzbqwltlfcqbxqdgumwsfcztsgnkbsxojeefeddtbtyztseebyqhqcfeacndmixmlcbnpproynpgiqbktzlawzrgjzqlbnnaskrxywwaikjfdztqnqvigpnvmtqtuzrgnkzbfmigykhvsuabstexeqmmywbaospgtfggqgxdfmgtnrwzxzqbqctnezkbfjsmvknqm")<<endl;
    return 0;
}
