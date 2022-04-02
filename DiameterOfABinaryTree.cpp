/*
https://leetcode.com/problems/diameter-of-binary-tree/
*/

class Solution {
public:
    int height(TreeNode* node, int& diameter) {
        if (!node) {
            return 0;
        }
        int leftHeight = height(node->left, diameter);
        int rightHeight = height(node->right, diameter);
        diameter = max(diameter, leftHeight + rightHeight);
        return 1 + max(leftHeight, rightHeight);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};
