/*
https://leetcode.com/problems/maximum-depth-of-binary-tree/
*/

class Solution {
public:
    void dfs(TreeNode* root, int &ans, int currentDepth) {
        if (!root) {
            return;
        }
        ans = max(ans, currentDepth);
        dfs(root -> left, ans, currentDepth + 1);
        dfs(root -> right, ans, currentDepth + 1);
    }
    
    int maxDepth(TreeNode* root) {
        int ans = 0, currentDepth = 1;
        dfs(root, ans, currentDepth);
        return ans;
    }
};
