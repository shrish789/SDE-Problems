// https://leetcode.com/problems/largest-rectangle-in-histogram/

// FIRST APPROACH: Brute force, offcourse

// SECOND APPROACH: Using leftsmall and rightsmall arrays
class Solution {
private:
    void findRightSmallerArray(vector<int>& heights, vector <int> &rightSmaller, stack <int> &st) {
        int n = heights.size();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                rightSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
    }
    void findLeftSmallerArray(vector<int>& heights, vector <int> &leftSmaller, stack <int> &st) {
        int n = heights.size();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                leftSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), res = 0;
        vector <int> leftSmaller(n, -1), rightSmaller(n, n);
        stack <int> st;

        findRightSmallerArray(heights, rightSmaller, st);
        while (!st.empty()) {
            st.pop();
        }
        findLeftSmallerArray(heights, leftSmaller, st);

        for (int i = 0; i < n; i++) {
            res = max(res, (rightSmaller[i] - leftSmaller[i] - 1) * heights[i]);
        }

        return res;
    }
};


// THIRD APPROACH: In single traversal of array
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), maxArea = -1, i;
        stack<int> st;
        for (i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                int curr = st.top();
                st.pop();
                int left = st.empty() ? 0 : st.top() + 1;
                maxArea = max(maxArea, heights[curr] * (i - left));
            }
            st.push(i);
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
