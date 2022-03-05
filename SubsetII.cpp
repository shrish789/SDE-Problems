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
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> v;
        vector<int> v1;
        sort(nums.begin(), nums.end());
        backtrack(v, v1, nums, 0);
        return v;
    }
    void backtrack(vector<vector<int>> &v, vector<int> v1, vector<int> nums, int pos) {
        v.push_back(v1);
        for (int i = pos; i < nums.size(); i++) {
            if (i != pos && nums[i] == nums[i - 1]) continue;
            v1.push_back(nums[i]);
            backtrack(v, v1, nums, i + 1);
            v1.pop_back();
        }
    }
};
