/*
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
*/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        deque<TreeNode*> q;
        int zigZagOrder = 0;
        vector<vector<int>> res;
        vector<int> temp;
        if (!root) {
            return res;
        }
        TreeNode* curr;
        
        q.push_back(root);
        int currentSize = 1, i = 0;
        
        while (!q.empty()) {
            i = currentSize;
            currentSize = 0;
            while (i--) {
                if (zigZagOrder == 0) {
                    curr = q.front();
                    temp.push_back(curr -> val);
                    if (curr -> left) {
                        q.push_back(curr -> left);
                        currentSize++;
                    }
                    if (curr -> right) {
                        q.push_back(curr -> right);
                        currentSize++;
                    }
                    q.pop_front();
                } else {
                    curr = q.back();
                    temp.push_back(curr -> val);
                    if (curr -> right) {
                        q.push_front(curr -> right);
                        currentSize++;
                    }
                    if (curr -> left) {
                        q.push_front(curr -> left);
                        currentSize++;
                    }
                    q.pop_back();
                }
            }
            res.push_back(temp);
            temp.clear();
            zigZagOrder = !zigZagOrder;
        }
        return res;
    }
};


// SECOND APPROACH: Same as above but better and easy

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        int zigZagOrder = 0;
        vector<vector<int>> res;
        vector<int> temp;
        if (!root) {
            return res;
        }
        TreeNode* curr;
        
        q.push(root);
        int currentSize = 1, i = 0;
        
        while (!q.empty()) {
            i = currentSize;
            currentSize = 0;
            while (i--) {
                curr = q.front();
                temp.push_back(curr -> val);
                if (curr -> left) {
                    q.push(curr -> left);
                    currentSize++;
                }
                if (curr -> right) {
                    q.push(curr -> right);
                    currentSize++;
                }
                q.pop();
            }
            if (zigZagOrder) {
                reverse(temp.begin(), temp.end());
            }
            res.push_back(temp);
            temp.clear();
            zigZagOrder = !zigZagOrder;
        }
        return res;
    }
};
