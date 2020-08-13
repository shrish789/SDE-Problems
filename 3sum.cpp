/*

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> p;
        sort(nums.begin(),nums.end());
        int l,r;
        for(int i=0; i<n; i++){
            if(i>=1 && nums[i]==nums[i-1]) continue;
            l=i+1,r=n-1;
            int target = -nums[i];
            while(l<r){
                if(nums[l]+nums[r] == target){
                    p.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while(l<r && nums[l]==nums[l-1]) l++;
                }
                else if(nums[l]+nums[r] > target) r--;
                else l++;
            }
        }
        return p;
    }
};
