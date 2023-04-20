/*

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

*/

// Prefix and Suffix Array
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), ans = 0;
        vector <int> prefix(n), suffix(n);
        prefix[0] = 0;
        for (int i = 1; i < n; i++) {
            prefix[i] = max(prefix[i - 1], height[i - 1]);
        }
        suffix[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = max(suffix[i + 1], height[i + 1]);
        }

        for (int i = 0; i < n; i++) {
            int x = min(prefix[i], suffix[i]) - height[i];
            ans += x > 0 ? x : 0;
        }

        return ans;
    }
};

// Optimal Solution: O(1) space
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), ans = 0;
        int leftMax = 0, rightMax = 0, l = 0, r = n - 1;
        while (l < r) {
            if (height[l] < height[r]) {
                if (height[l] >= leftMax) {
                    leftMax = height[l];
                } else {
                    ans += leftMax - height[l];
                }
                l++;
            } else {
                if (height[r] >= rightMax) {
                    rightMax = height[r];
                } else {
                    ans += rightMax - height[r];
                }
                r--;
            }
        }
        return ans;
    }
};
