/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at 
least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.
Note:

-You must not modify the array (assume the array is read only).
-You must use only constant, O(1) extra space.
-Your runtime complexity should be less than O(n2).
-There is only one duplicate number in the array, but it could be repeated more than once.
*/

//Floyd's Tortoise and hare algorithm

class Solution {
public:
    int slow = nums[0];
    int fast = nums[0];
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    fast = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

// Second approach

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int answer;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[abs(nums[i]) - 1] < 0) {
                answer = abs(nums[i]);
                break;
            } else {
                nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
            }
        }
        return answer;
    }
};
