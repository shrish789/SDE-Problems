// https://leetcode.com/problems/string-to-integer-atoi/description/

class Solution {
public:
    int myAtoi(string s) {
        bool isPos = false, isNeg = false;
        int pos = -1;
        long long ans = 0, curr = 1;
        string str = "";
        for (int i = 0; i < s.size() && s[i] == ' '; i++) {
            if (s[i] == ' ') {
                pos = i;
            }
        }
        pos++;
        int pos1 = pos;
        if (pos + 1 < s.size()) {
            if (s[pos] == '+') isPos = true;
            else if (s[pos] == '-') isNeg = true;
        }

        if (isPos || isNeg) pos++;
        for (int i = pos; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                str += s[i];
            } else {
                break;
            }
        }

        s = "";
        bool flag = false;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '0' && !flag) {
                continue;
            } else {
                flag = true;
                s += str[i];
            }
        }
        int n = s.size();
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] >= '0' && s[i] <= '9') {
                ans += (s[i] - '0') * curr;
                if (!isNeg && curr > INT_MAX) {
                    ans = INT_MAX;
                    break;
                }
                curr *= 10;
            }
            if (isNeg && -1 * ans < INT_MIN) {
                ans = INT_MIN;
                break;
            } else if (!isNeg && ans > INT_MAX) {
                ans = INT_MAX;
                break;
            }
        }
        if (isNeg && ans != INT_MIN) {
            ans *= -1;
        }
        return (int)ans;
    }
};
