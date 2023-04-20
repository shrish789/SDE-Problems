// https://leetcode.com/problems/subsets-ii/

// FIRST APPROACH: Using set
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>v;
        vector<int> v1;
        backtrack(v, v1, nums, 0);
        vector<vector<int>> v2(v.begin(), v.end());
        return v2;
    }
    void backtrack(set<vector<int>> &v, vector<int> v1, vector<int> nums, int pos)
    {
        vector<int> v3 = v1;
        sort(v3.begin(), v3.end());
        v.insert(v3);
        
        for(int i=pos; i<nums.size(); i++)
        {
            v1.push_back(nums[i]);
            backtrack(v, v1, nums, i+1);
            v1.pop_back();
        }
    }
};

// SECOND APPROACH: Without using set
class Solution {
private:
    void subsetUtil(vector <int> &nums, int pos, vector <int> v, vector <vector <int>> &res) {
        res.push_back(v);

        for (int i = pos; i < nums.size(); i++) {
            if (i > pos && nums[i] == nums[i - 1]) continue;
            v.push_back(nums[i]);
            subsetUtil(nums, i + 1, v, res);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector <vector <int>> res;
        vector <int> v;
        sort(nums.begin(), nums.end());
        subsetUtil(nums, 0, v, res);
        return res;
    }
};
