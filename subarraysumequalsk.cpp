/*

Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:

Input:nums = [1,1,1], k = 2
Output: 2
 

Constraints:

The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mymap;
        int curr=0,ans=0;
        mymap[0]++;
        for(int i=0; i<nums.size(); i++){
            curr+=nums[i];
            ans+=mymap[curr-k];
            mymap[curr]++;
        }
        return ans;
    }
};
