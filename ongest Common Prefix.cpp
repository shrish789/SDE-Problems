// https://leetcode.com/problems/longest-common-prefix/description/

class Solution {
private:
    string findCommonPrefixUtil(string str1, string str2) {
        string str = "";
        for (int i = 0; i < min(str1.size(), str2.size()); i++) {
            if (str1[i] == str2[i]) {
                str += str1[i];
            } else {
                break;
            }
        }
        return str;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            ans = findCommonPrefixUtil(ans, strs[i]);
        }
        return ans;
    }
};
