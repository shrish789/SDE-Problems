// https://www.interviewbit.com/problems/path-to-given-node/

bool treeTraversal(TreeNode *root, int target, vector <int> &v) {
    if (!root) {
        return false;
    }
    
    if (root -> val == target) {
        v.push_back(root -> val);
        return true;
    }
    
    if (treeTraversal(root -> left, target, v) || treeTraversal(root -> right, target, v)) {
        v.push_back(root -> val);
        return true;
    }
    return false;
}

vector<int> Solution::solve(TreeNode* A, int B) {
    vector <int> v;
    treeTraversal(A, B, v);
    reverse(v.begin(), v.end());
    return v;
}


// A little bit faster approach
bool treeTraversal(TreeNode *root, int target, vector <int> &v) {
    if (!root) {
        return false;
    }
    
    if (root -> val == target) {
        v.push_back(root -> val);
        return true;
    }
    
    bool found = treeTraversal(root -> left, target, v);
    if (found) {
        v.push_back(root -> val);
        return true;
    }
    found = treeTraversal(root -> right, target, v);
    if (found) {
        v.push_back(root -> val);
        return true;
    }
    return false;
}

vector<int> Solution::solve(TreeNode* A, int B) {
    vector <int> v;
    treeTraversal(A, B, v);
    reverse(v.begin(), v.end());
    return v;
}
