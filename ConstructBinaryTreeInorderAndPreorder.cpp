/*
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
*/

class Solution {
public:
    unordered_map < int, int > mp;
    TreeNode* constructTree(vector<int> preorder, int preStart, int preEnd, vector<int> inorder, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preStart]);
        int elem = mp[root -> val];
        int nElem = elem - inStart;

        root -> left = constructTree(preorder, preStart + 1, preStart + nElem, inorder,
        inStart, elem - 1);
        root -> right = constructTree(preorder, preStart + nElem + 1, preEnd, inorder, 
        elem + 1, inEnd);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preStart = 0, preEnd = preorder.size() - 1;
        int inStart = 0, inEnd = inorder.size() - 1;

        for (int i = inStart; i <= inEnd; i++) {
            mp[inorder[i]] = i;
        }
        return constructTree(preorder, preStart, preEnd, inorder, inStart, inEnd);
    }
};
