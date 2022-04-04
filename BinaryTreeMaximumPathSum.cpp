/*
https://leetcode.com/problems/binary-tree-maximum-path-sum/
*/

class Solution {
public:
    int maxSum(TreeNode* root, int &maximumSum) {
        if (!root) {
            return 0;
        }
        
        int leftSum = max(0, maxSum(root -> left, maximumSum));
        int rightSum = max(0, maxSum(root -> right, maximumSum));
        maximumSum = max(leftSum + rightSum + root -> val, maximumSum);
        return max(leftSum, rightSum) + root -> val;
    }
    
    int maxPathSum(TreeNode* root) {
        int maximumSum = INT_MIN;
        maxSum(root, maximumSum);
        return maximumSum;
    }
};
