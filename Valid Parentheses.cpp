// https://leetcode.com/problems/valid-parentheses/description/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++) {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') {
                st.push(s[i]);
            } else {
                if (st.empty()) return false;

                if(s[i]==')' && st.top()=='(' || s[i]=='}' && st.top()=='{' || s[i]==']' && st.top()=='[') {
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            }
        }
        return st.empty();
    }
};
