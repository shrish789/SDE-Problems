/*
https://leetcode.com/problems/jump-game-ii/
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        res[0] = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            int finalIndex = i + nums[i];
            finalIndex = min(finalIndex, (int)nums.size() - 1);
            for (int j = finalIndex; j > i; j--) {
                if (res[j] == -1) {
                    res[j] = res[i] + 1;
                } else {
                    break;
                }
            }
        }
        return res.back();
    }
};
