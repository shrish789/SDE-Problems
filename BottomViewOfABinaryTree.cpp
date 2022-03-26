/*
https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1#
*/

class Solution {
  public:
    void bottomViewFinal(Node *root, unordered_map<int, pair<int,int>> &res, int position, int height) {
        if (!root) {
            return;
        }
        if (res.find(position) == res.end()) {
            res[position] = {root -> data, height};
        } else {
            if (res[position].second <= height) {
                res[position] = {root -> data, height};
            }
        }
        // res[position] = {root -> data, height};
        bottomViewFinal(root -> left, res, position - 1, height + 1);
        bottomViewFinal(root -> right, res, position + 1, height + 1);
    }
    
    vector <int> bottomView(Node *root) {
        unordered_map<int, pair<int,int>> res;
        bottomViewFinal(root, res, 0, 0);
        vector<pair<int, int>> v1;
        for (auto ele : res) {
            v1.push_back({ele.first, ele.second.first});
        }
        sort(v1.begin(), v1.end());
        vector<int> v;
        for (auto ele : v1) {
            v.push_back(ele.second);
        }
        return v;
    }
};
