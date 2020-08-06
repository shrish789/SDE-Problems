/*

Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        int n=nums.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                vector<int> v;
                vector<int>v1;
                v1.push_back(nums[i]);
                v1.push_back(nums[j]);
                twosum(nums, v, i, j, target-nums[i]-nums[j]);
                if(v.size()>0){
                    for(int i=0; i<v.size(); i+=2){
                        v1.push_back(v[i]);
                        v1.push_back(v[i+1]);
                        s.insert(v1);
                        v1.pop_back();
                        v1.pop_back();
                    }
                }
            }
        }
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
    
    void twosum(vector<int>& nums, vector<int>& v, int x, int y, int target){
        int l=y+1,r=nums.size()-1;
        while(l<r){
            if(l==x || l==y) l++;
            if(r==x || r==y) r--;
            
            if(nums[l]+nums[r]==target){
                v.push_back(nums[l]);
                v.push_back(nums[r]);
                l++;
                r--;
            }
            else if(nums[l]+nums[r]>target) r--;
            else l++;
        }
    }
};
