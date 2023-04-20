// https://leetcode.com/problems/combination-sum/

class Solution {
private:
    void combinationSumUtil(vector<int>& candidates, int target, int pos, vector <int> v, vector <vector <int>> &res) {
        if (target == 0) {
            res.push_back(v);
            return;
        }

        for (int i = pos; i < candidates.size(); i++) {
            if (target >= candidates[i]) {
                v.push_back(candidates[i]);
                combinationSumUtil(candidates, target - candidates[i], i, v, res);
                v.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector <vector <int>> res;
        vector <int> v;
        combinationSumUtil(candidates, target, 0, v, res);
        return res;
    }
};
