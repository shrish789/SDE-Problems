// https://leetcode.com/problems/reverse-words-in-a-string/

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
