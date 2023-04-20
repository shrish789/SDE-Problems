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
private:
    void combinationSumUtil(vector<int>& candidates, int target, int pos, vector <int> v, vector <vector <int>> &res) {
        if (target == 0) {
            res.push_back(v);
            return;
        }

        for (int i = pos; i < candidates.size(); i++) {
            if (target >= candidates[i]) {
                if (i != pos && candidates[i] == candidates[i - 1]) continue;
                v.push_back(candidates[i]);
                combinationSumUtil(candidates, target - candidates[i], i + 1, v, res);
                v.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector <vector <int>> res;
        vector <int> v;
        sort(candidates.begin(), candidates.end());
        combinationSumUtil(candidates, target, 0, v, res);
        return res;
    }
};
