// https://leetcode.com/problems/count-and-say/

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        string str = countAndSay(n - 1);
        string ans = "";
        int cnt = 1;
        for (int i = 1; i < str.size(); i++) {
            if (str[i] == str[i - 1]) {
                cnt++;
            } else {
                ans += to_string(cnt) + str[i - 1];
                cnt = 1;
            }
        }
        ans += to_string(cnt) + str[str.size() - 1];
        return ans;
    }
};
