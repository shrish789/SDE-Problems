// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

class Solution {
private:
    void verticalOrderTraversalUtil(TreeNode *root, unordered_map <int, vector <pair<int, int>>> &um, int height, int pos, int &maxPos, int &minPos) {
        if (!root) {
            return;
        }
        um[pos].push_back({height, root -> val});
        maxPos = max(maxPos, pos);
        minPos = min(minPos, pos);
        verticalOrderTraversalUtil(root -> left, um, height + 1, pos - 1, maxPos, minPos);
        verticalOrderTraversalUtil(root -> right, um, height + 1, pos + 1, maxPos, minPos);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        unordered_map <int, vector <pair <int, int>>> um;
        int maxPos = INT_MIN, minPos = INT_MAX;
        verticalOrderTraversalUtil(root, um, 0, 0, maxPos, minPos);
        for (int i = minPos; i <= maxPos; i++) {
            if (um.find(i) != um.end()) {
                vector <int> v;
                sort(um[i].begin(), um[i].end());
                for (int j = 0; j < um[i].size(); j++) {
                    v.push_back(um[i][j].second);
                }
                res.push_back(v);
            }
        }
        return res;
    }
};
