/*

Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

*/

class Solution {
private:
    void subsetUtil(vector <int> &nums, int pos, vector <int> v, vector <vector <int>> &res) {
        res.push_back(v);

        for (int i = pos; i < nums.size(); i++) {
            v.push_back(nums[i]);
            subsetUtil(nums, i + 1, v, res);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <vector <int>> res;
        vector <int> v;
        subsetUtil(nums, 0, v, res);
        return res;
    }
};
