// https://leetcode.com/problems/palindrome-partitioning/

class Solution {
private:
    void partitionUtil(string s, int pos, vector <string> v, vector <vector<string>> &res) {
        if (pos == s.size()) {
            res.push_back(v);
            return;
        }

        string str = "";
        for (int i = pos; i < s.size(); i++) {
            str += s[i];
            if (isPalindrome(str)) {
                v.push_back(str);
                partitionUtil(s, i + 1, v, res);
                v.pop_back();
            }
        }
    }
    bool isPalindrome(string str) {
        for (int i = 0; i < str.size() / 2; i++) {
            if (str[i] != str[str.size() - i - 1]) {
                return false;
            }
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector < vector <string> > res;
        vector <string> v;
        partitionUtil(s, 0, v, res);
        return res;
    }
};
