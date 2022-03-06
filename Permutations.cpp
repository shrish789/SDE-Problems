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
