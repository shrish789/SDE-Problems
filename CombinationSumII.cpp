// https://leetcode.com/problems/combination-sum-ii/

// FIRST APPROACH: Using Sets
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<int> v1;
        set<vector<int>> s;
        backtrack(s, v1, candidates, target, 0, 0);
        vector<vector<int>> v(s.begin(), s.end());
        return v;
    }
    void backtrack(set<vector<int>>&s, vector<int> v1, vector<int> a, int target, int curr, int pos)
    {
        if(curr==target)
        {
            sort(v1.begin(), v1.end());
            s.insert(v1);
            return;
        }
        
        for(int i=pos; i<a.size(); i++)
        {
            if(curr+a[i]<=target)
            {
                v1.push_back(a[i]);
                backtrack(s, v1, a, target, curr+a[i], i+1);
                v1.pop_back();
            }
        }
    }
};

// SECOND APPROACH: Without using sets
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> v;
        vector<int> v1;
        sort(candidates.begin(), candidates.end());
        backtrack(v, v1, candidates, 0, 0, target);
        return v;
    }
    void backtrack(vector<vector<int>> &v, vector<int> v1, vector<int> nums, int pos, int sum, int target) {
        if (sum == target) v.push_back(v1);
        for (int i = pos; i < nums.size(); i++) {
            if (i != pos && nums[i] == nums[i - 1]) continue;
            if (sum + nums[i] <= target) {
                v1.push_back(nums[i]);
                sum += v1.back();
                backtrack(v, v1, nums, i + 1, sum, target);
                sum -= v1.back();
                v1.pop_back();
            }
        }
    }
};
