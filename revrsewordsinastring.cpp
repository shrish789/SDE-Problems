/*

Given an input string, reverse the string word by word.

 

Example 1:

Input: "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Note:

A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Follow up:

For C programmers, try to solve it in-place in O(1) extra space.

*/

class Solution {
public:
    string reverseWords(string s) {
        if(s.empty()) return "";
        string str="";
        string word="";
        for(int i=0; i<s.length(); i++){
            if(s[i]==' ' && word!=""){
                reverse(word.begin(),word.end());
                str+=word;
                str+=" ";
                word="";
            }
            else if(s[i]!=' ') word+=s[i];
        }
        if(word!=""){
            reverse(word.begin(),word.end());
            str+=word;
            str+=" ";
        }
        while(!str.empty() && str.back()==' ') str.pop_back();
        reverse(str.begin(), str.end());
        return str;
    }
};
