/*
https://leetcode.com/problems/jump-game/
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int indexCovered = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (i <= indexCovered) {
                indexCovered = max(indexCovered, i + nums[i]);
            }
        }
        return (indexCovered >= nums.size() - 1) ? true : false;
    }
};
