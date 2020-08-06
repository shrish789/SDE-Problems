/*

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0; i<nums.size(); i++) s.insert(nums[i]);
        int prev=-1,mx=0,cnt;
        for(int i=0; i<nums.size(); i++){
            if(s.find(nums[i]-1)==s.end()){
                prev=nums[i];
                cnt=1;
                while(s.find(prev+1)!=s.end()){
                    prev++;
                    cnt++;
                }
                mx=max(mx,cnt);
            }
        }
        return mx;
    }
};
