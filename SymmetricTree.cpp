/*
https://leetcode.com/problems/symmetric-tree/
*/

class Solution {
public:
    bool isSymmetric(TreeNode *root1, TreeNode *root2) {
        if (!root1 && !root2) {
            return true;
        }
        if (!root1 || !root2) {
            return false;
        }
        if (root1 -> val != root2 -> val) {
            return false;
        }
        return isSymmetric(root1 -> left, root2 -> right) && isSymmetric(root1 -> right, root2 -> left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root -> left, root -> right);
    }
};
