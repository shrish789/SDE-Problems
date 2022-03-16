// https://leetcode.com/problems/count-and-say/

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        string str = countAndSay(n - 1);
        string str1 = "";
        char topChar = str[0];
        int k = 1;
        for (int i = 1; i < str.size(); i++) {
            if (topChar == str[i]) {
                k++;
            } else {
                str1 += to_string(k);
                str1 += topChar;
                topChar = str[i];
                k = 1;
            }
        }
        str1 += to_string(k);
        str1 += topChar;
        return str1;
    }
};
