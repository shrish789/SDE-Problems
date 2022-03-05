// https://leetcode.com/problems/combination-sum/

// FIRST APPROACH:
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> v;
        vector<int> v1;
        sort(candidates.begin(), candidates.end());
        backtrack(v, v1, candidates, 0, target);
        return v;
    }
    void backtrack(vector<vector<int>> &v, vector<int> v1, vector<int> nums, int pos, int target) {
        if (target == 0){
            v.push_back(v1);
        }
        for (int i = pos; i < nums.size(); i++) {
            if (i != pos && nums[i] == nums[i - 1]) continue;
            if (target - nums[i] >= 0){
                v1.push_back(nums[i]);
                target -= v1.back();
                backtrack(v, v1, nums, i, target);
                target += v1.back();
                v1.pop_back();
            }
            
        }
    }
};
