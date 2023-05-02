// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

void leftViewUtil(Node *root, int level, vector <int> &v) {
    if (!root) {
        return;
    }
    
    if (v.size() == level) {
        v.push_back(root -> data);
    }
    
    leftViewUtil(root -> left, level + 1, v);
    leftViewUtil(root -> right, level + 1, v);
}

vector<int> leftView(Node *root) {
   vector <int> v;
   int maxLevel = 0;
   leftViewUtil(root, 0, v);
   return v;
}
