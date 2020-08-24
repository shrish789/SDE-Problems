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
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v;
        vector<int> v1;
        backtrack(v, v1, nums, 0);
        return v;
    }
    void backtrack(vector<vector<int>> &v, vector<int> v1, vector<int> nums, int pos){
        v.push_back(v1);
        
        for(int i=pos; i<nums.size(); i++){
            v1.push_back(nums[i]);
            backtrack(v, v1, nums, i+1);
            v1.pop_back();
        }
    }
};
