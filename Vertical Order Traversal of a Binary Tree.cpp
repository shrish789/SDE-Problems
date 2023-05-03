// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

// Recursive Approach
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
            vector <int> v;
            sort(um[i].begin(), um[i].end());
            for (int j = 0; j < um[i].size(); j++) {
                v.push_back(um[i][j].second);
            }
            res.push_back(v);
        }
        return res;
    }
};

// Iterative Approach
class Solution {
private:
    void verticalOrderTraversalUtil(TreeNode *root, unordered_map <int, vector <pair<int, int>>> &um, int height, int pos, int &maxPos, int &minPos) {
        queue <pair <int, pair <int, TreeNode*>>> q;
        q.push({0, {0, root}});
        while (!q.empty()) {
            pair <int, pair <int, TreeNode*>> p = q.front();
            q.pop();
            maxPos = max(maxPos, p.first);
            minPos = min(minPos, p.first);
            um[p.first].push_back({p.second.first, p.second.second -> val});
            if (p.second.second -> left) {
                q.push({p.first - 1, {p.second.first + 1, p.second.second -> left}});
            }
            if (p.second.second -> right) {
                q.push({p.first + 1, {p.second.first + 1, p.second.second -> right}});
            }
        }
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        unordered_map <int, vector <pair <int, int>>> um;
        int maxPos = INT_MIN, minPos = INT_MAX;
        verticalOrderTraversalUtil(root, um, 0, 0, maxPos, minPos);
        for (int i = minPos; i <= maxPos; i++) {
            vector <int> v;
            sort(um[i].begin(), um[i].end());
            for (int j = 0; j < um[i].size(); j++) {
                v.push_back(um[i][j].second);
            }
            res.push_back(v);
        }
        return res;
    }
};
