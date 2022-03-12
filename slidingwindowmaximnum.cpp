/*

https://leetcode.com/problems/sliding-window-maximum/

Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

Follow up:
Could you solve it in linear time?

Example:

Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7] 
Explanation: 

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 

Constraints:

1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
1 <= k <= nums.length

*/

// FIRST APPROACH: Brute force, offcourse

// SECOND APPROACH: Using deque
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>> dq;
        vector<int> ans;
        for(int i=0; i<k; i++){
            while(!dq.empty() && dq.front().first<nums[i]) dq.pop_front();
            dq.push_front({nums[i],i});
        }
        ans.push_back(dq.back().first);
        for(int i=k; i<nums.size(); i++){
            if(dq.back().second==i-k) dq.pop_back();
            while(!dq.empty() && dq.front().first<nums[i]) dq.pop_front();
            dq.push_front({nums[i],i});
            ans.push_back(dq.back().first);
        }
        return ans;
    }
};

// SAME APPROACH BUT BETTER
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int n = nums.size();
        vector<int> maxArray;
        for (int i = 0; i < n; i++) {
            while (!dq.empty() && nums[i] > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (dq.front() + k - 1 < dq.back()) {
                dq.pop_front();
            }
            if (i >= k - 1) {
                maxArray.push_back(nums[dq.front()]);;
            }
        }
        return maxArray;
    }
};
