// https://leetcode.com/problems/word-break/description/


// Normal Recursion
class Solution {
private:
    void wordBreakUtil(bool &finalRes, vector <string> &v, unordered_set <string> &st, string &s, int pos) {
    if (pos == s.size()) {
        finalRes = true;
    }

    string str = "";
    for (int i = pos; i < s.size(); i++) {
        str += s[i];
        if (st.find(str) != st.end() and !finalRes) {
            v.push_back(str);
            wordBreakUtil(finalRes, v, st, s, i + 1);
            v.pop_back();
        }
    }
}
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set <string> st;
        for (int i = 0; i < wordDict.size(); i++) {
            st.insert(wordDict[i]);
        }

        bool finalRes = false;
        vector <string> v;
        wordBreakUtil(finalRes, v, st, s, 0);
        return finalRes;
    }
};


// Recursion with Memoization
class Solution {
private:
    void wordBreakUtil(bool &finalRes, unordered_set <string> &st, unordered_map <int, int> &dp, string &s, int pos) {
    if (pos == s.size()) {
        finalRes = true;
        return;
    }

    if (dp[pos] != 0) {
        return;
    }

    string str = "";
    for (int i = pos; i < s.size(); i++) {
        str += s[i];
        if (st.find(str) != st.end() and !finalRes) {
            wordBreakUtil(finalRes, st, dp, s, i + 1);
            if (finalRes) {
                dp[i + 1] = 1;
            } else {
                dp[i + 1] = 2;
            }
        }
    }
}
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set <string> st;
        unordered_map <int, int> dp;
        for (int i = 0; i < wordDict.size(); i++) {
            st.insert(wordDict[i]);
        }

        bool finalRes = false;
        wordBreakUtil(finalRes, st, dp, s, 0);
        return finalRes;
    }
};


// Normal DP
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> word_set(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.length() + 1);
        dp[0] = true;

        for (int i = 1; i <= s.length(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && word_set.find(s.substr(j, i - j)) != word_set.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
};
