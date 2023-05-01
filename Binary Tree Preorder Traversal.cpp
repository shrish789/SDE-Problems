// https://leetcode.com/problems/binary-tree-preorder-traversal/description/

class Solution {
private:
    void preorderTraversalUtil(TreeNode *root, vector <int> &v) {
        if (!root) {
            return;
        }
        v.push_back(root -> val);
        preorderTraversalUtil(root -> left, v);
        preorderTraversalUtil(root -> right, v);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector <int> v;
        preorderTraversalUtil(root, v);
        return v;
    }
};
