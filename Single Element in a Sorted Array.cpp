// https://leetcode.com/problems/single-element-in-a-sorted-array/description/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int mid = (low + high) / 2;
        while (low <= high) {
            mid = (low + high) / 2;
            if (mid != nums.size() - 1 && nums[mid] == nums[mid + 1]) {
                mid++;
            }
            if (mid != 0 && nums[mid] != nums[mid - 1]) {
                break;
            } else if ((mid + 1) % 2 == 0) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return nums[mid];
    }
};
