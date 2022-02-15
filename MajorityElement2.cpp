/*
https://leetcode.com/problems/majority-element-ii/

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
 
Constraints:

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109
 
Follow up: Could you solve the problem in linear time and in O(1) space?
*/

// FIRST APPROACH: Brute force. Offcourse

// SECOND APPROACH: HashMap

// THIRD APPROACH: Extended Boyer Moore’s Voting Algorithm
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = INT_MIN, num2 = INT_MIN, count1 = 0, count2 = 0, testCount1 = 0, testCount2 = 0;
        for (int element : nums) {
            if (element == num1) {
                count1++;
            } else if (element == num2) {
                count2++;
            } else if (count1 == 0) {
                num1 = element;
                count1++;
            } else if (count2 == 0) {
                num2 = element;
                count2++;
            } else {
                count1--;
                count2--;
            }
        }
        for (int element : nums) {
            if (element == num1) {
                testCount1++;
            } else if( element == num2) {
                testCount2++;
            }
        }
        vector<int> res;
        if (testCount1 > nums.size()/3) {
            res.push_back(num1);
        }
        if (testCount2 > nums.size()/3) {
            res.push_back(num2);
        }
        return res;
    }
};
