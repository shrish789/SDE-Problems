// https://leetcode.com/problems/palindrome-partitioning/

class Solution {
public:
    vector<vector<string>> partition(string str) {
        vector<vector<string>>v;
        vector<string> v1;
        backtrack(v, v1, str);
        return v;
    }
    void backtrack(vector<vector<string>>&v, vector<string> v1, string str) {
        if(str.empty()) {
            v.push_back(v1);
            return;
        }
        
        string str1 = "";
        for(int i=0; i<str.length(); i++) {
            str1+=str[i];
            if(ispalindrome(str1)) {
                v1.push_back(str1);
                backtrack(v, v1, str.substr(i+1, str.length()-i-1));
                v1.pop_back();
            }
        }
    }
    bool ispalindrome(string str) {
        bool f=1;
        int n = str.length();
        for(int i=0; i<str.length()/2; i++)
            if(str[i]!=str[n-1-i]) f=false;
        return f;
    }
};
