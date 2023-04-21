// https://leetcode.com/problems/permutations/

// FIRST APPROACH: Using vis array
class Solution {
  private:
    void recurPermute(vector < int > & ds, vector < int > & nums, vector < vector < int >> & ans, int freq[]) {
      if (ds.size() == nums.size()) {
        ans.push_back(ds);
        return;
      }
      for (int i = 0; i < nums.size(); i++) {
        if (!freq[i]) {
          ds.push_back(nums[i]);
          freq[i] = 1;
          recurPermute(ds, nums, ans, freq);
          freq[i] = 0;
          ds.pop_back();
        }
      }
    }
  public:
    vector < vector < int >> permute(vector < int > & nums) {
      vector < vector < int >> ans;
      vector < int > ds;
      int freq[nums.size()];
      for (int i = 0; i < nums.size(); i++) freq[i] = 0;
      recurPermute(ds, nums, ans, freq);
      return ans;
    }
};

// SECOND APPROACH: Without using vis array
class Solution {
private:
    void permuteUtil(vector <int> nums, int pos, vector <vector <int>> &res) {
        if (pos == nums.size()) {
            res.push_back(nums);
        }
        for (int i = pos; i < nums.size(); i++) {
            swap(nums[i], nums[pos]);
            permuteUtil(nums, pos + 1, res);
            swap(nums[i], nums[pos]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector <vector <int>> res;
        permuteUtil(nums, 0, res);
        return res;
    }
};
