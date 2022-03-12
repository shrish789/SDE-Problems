// https://leetcode.com/problems/largest-rectangle-in-histogram/

// FIRST APPROACH: Brute force, offcourse

// SECOND APPROACH: Using leftsmall and rightsmall arrays
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int leftArray[n], rightArray[n];
        stack<int> st;
        
        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                leftArray[i] = 0;
                st.push(i);
                continue;
            }
            if (heights[i] > heights[st.top()]) {
                leftArray[i] = st.top() + 1;
                st.push(i);
            } else {
                while (!st.empty() && heights[st.top()] >= heights[i]) {
                    st.pop();
                }
                leftArray[i] = st.empty() ? 0 : st.top() + 1;
                st.push(i);
            }
        }
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            if (st.empty()) {
                rightArray[i] = n - 1;
                st.push(i);
                continue;
            }
            if (heights[i] > heights[st.top()]) {
                rightArray[i] = st.top() - 1;
                st.push(i);
            } else {
                while (!st.empty() && heights[st.top()] >= heights[i]) {
                    st.pop();
                }
                rightArray[i] = st.empty() ? n - 1 : st.top() - 1;
                st.push(i);
            }
        }
        int maxArea = -1;
        for (int i = 0; i < n; i++) {
            maxArea = max(maxArea, heights[i] * (rightArray[i] - leftArray[i] + 1));
        }
        return maxArea;
    }
};


// THIRD APPROACH: In single traversal of array
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), maxArea = -1, i;
        int leftArray[n], rightArray[n];
        stack<int> st;
        for (i = 0; i < n; i++) {
            if (st.empty()) {
                leftArray[i] = 0;
                st.push(i);
                continue;
            }
            if (heights[i] > heights[st.top()]) {
                st.push(i);
            } else {
                while (!st.empty() && heights[st.top()] >= heights[i]) {
                    int curr = st.top();
                    st.pop();
                    int left = st.empty() ? 0 : st.top() + 1;
                    maxArea = max(maxArea, heights[curr] * (i - left));
                }
                st.push(i);
            }
        }
        while (!st.empty()) {
            int curr = st.top();
            st.pop();
            int left = st.empty() ? 0 : st.top() + 1;
            maxArea = max(maxArea, heights[curr] * (i - left));
        }
        return maxArea;
    }
};
