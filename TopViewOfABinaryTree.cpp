/*
https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
*/

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    
    void topViewFinal(Node *root, int position, unordered_map<int, pair<int,int>> &res, int height) {
        if (!root) {
            return;
        }
        if (res.find(position) == res.end()) {
            res[position] = {root -> data, height};
        } else {
            if (res[position].second >= height) {
                res[position] = {root -> data, height};
            }
        }
        topViewFinal(root -> left, position - 1, res, height + 1);
        topViewFinal(root -> right, position + 1, res, height + 1);
    }
    
    vector<int> topView(Node *root)
    {
        //Your code here
        unordered_map<int, pair<int,int>> res;
        vector<int> v;
        topViewFinal(root, 0, res, 0);
        vector<pair<int, int>> v1;
        for (auto ele : res) {
            v1.push_back({ele.first, ele.second.first});
        }
        sort(v1.begin(), v1.end());
        // vector<int> v;
        for (auto ele : v1) {
            v.push_back(ele.second);
        }
        return v;
    }

};
