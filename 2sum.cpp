/*

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n=nums.size();
        vector<pair<int,int> > v;
        for(int i=0; i<n; i++)
            v.push_back({nums[i],i});
        sort(v.begin(),v.end());
        
        int l=0,r=n-1;
        while(1)
        {
            if(v[l].first+v[r].first == target)
            {
                ans.push_back(v[l].second);
                ans.push_back(v[r].second);
                break;
            }
            else if(v[l].first+v[r].first > target) r--;
            else l++;
        }
        return ans;
    }
};
