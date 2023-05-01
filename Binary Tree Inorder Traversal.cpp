// https://leetcode.com/problems/binary-tree-inorder-traversal/description/

class Solution {
private:
    void inorderTraversalUtil(TreeNode *root, vector <int> &v) {
        if (!root) {
            return;
        }
        inorderTraversalUtil(root -> left, v);
        v.push_back(root -> val);
        inorderTraversalUtil(root -> right, v);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> v;
        inorderTraversalUtil(root, v);
        return v;
    }
};
