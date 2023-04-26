// https://leetcode.com/problems/next-greater-element-ii/description/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector <int> res(n, -1);
        stack <pair<int, int>> st;
        for (int i = 0; i < 2 * n; i++) {
            while (!st.empty() && st.top().first < nums[i % n]) {
                res[st.top().second % n] = nums[i % n];
                st.pop();
            }
            st.push(make_pair(nums[i % n], i));
        }
        return res;
    }
};
