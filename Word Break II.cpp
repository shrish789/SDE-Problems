// https://leetcode.com/problems/word-break-ii/description/


// Recursion
class Solution {
private:
    void wordBreakUtil(vector <vector <string>> &res, vector <string> &v, unordered_set <string> &st, string &s, int pos) {
    if (pos == s.size()) {
        res.push_back(v);
    }

    string str = "";
    for (int i = pos; i < s.size(); i++) {
        str += s[i];
        if (st.find(str) != st.end()) {
            v.push_back(str);
            wordBreakUtil(res, v, st, s, i + 1);
            v.pop_back();
        }
    }
}
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set <string> st(wordDict.begin(), wordDict.end());
        vector <string> finalRes, v;
        vector <vector <string>> res;
        wordBreakUtil(res, v, st, s, 0);
        for (int i = 0; i < res.size(); i++) {
            string str = "";
            for (int j = 0; j < res[i].size(); j++) {
                str += res[i][j] + " ";
            }
            str.pop_back();
            finalRes.push_back(str);
        }
        return finalRes;
    }
};


// DP
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int N = s.size();
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        
        vector<vector<string>> dp(N + 1, vector<string>());
        dp[0].push_back("");
        for(int i = 1; i <= N; ++i) {
            for(int j = 0; j < i; ++j) {
                string substr = s.substr(j, i - j);
                if(dp[j].size() > 0 && wordSet.find(substr) != wordSet.end()){
                    for(auto l : dp[j]) {
                        dp[i].push_back(l + (l == "" ? "" : " ") + substr);
                    }
                }
            }
        }
        
        return dp[N];
    }
};
