// https://leetcode.com/problems/binary-tree-postorder-traversal/description/

class Solution {
private:
    void postorderTraversalUtil(TreeNode *root, vector <int> &v) {
        if (!root) {
            return;
        }
        postorderTraversalUtil(root -> left, v);
        postorderTraversalUtil(root -> right, v);
        v.push_back(root -> val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector <int> v;
        postorderTraversalUtil(root, v);
        return v;
    }
};
