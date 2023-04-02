/*

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int l = nums.size(), inflectionIndex = 0;
        for (int i = l - 1; i >= 1; i--) {
            if (nums[i] > nums[i - 1]) {
                inflectionIndex = i;
                break;
            }
        }
        if (inflectionIndex != 0) {
            for (int k = l - 1; k >= inflectionIndex; k--) {
                if (nums[k] > nums[inflectionIndex - 1]) {
                    swap(nums[inflectionIndex - 1], nums[k]);
                    break;
                }
            }
        }
        reverse(nums.begin() + inflectionIndex, nums.end());
    }
};
