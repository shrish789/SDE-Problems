// https://leetcode.com/problems/permutations/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> v;
        backtrack(v, nums, 0);
        return v;
    }
    void backtrack(vector<vector<int>> &v, vector<int> v1, int pos) {
        if (pos == v1.size()) {
            v.push_back(v1);
        }
        for (int i = pos; i < v1.size(); i++) {
            swap(v1[pos], v1[i]);
            backtrack(v, v1, pos + 1);
            swap(v1[pos], v1[i]);
        }
    }
};
