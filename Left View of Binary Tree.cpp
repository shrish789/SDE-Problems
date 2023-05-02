// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

void leftViewUtil(Node *root, int &maxLevel, int level, vector <int> &v) {
    if (!root) {
        return;
    }
    
    if (maxLevel < level) {
        v.push_back(root -> data);
        maxLevel = level;
    }
    
    leftViewUtil(root -> left, maxLevel, level + 1, v);
    leftViewUtil(root -> right, maxLevel, level + 1, v);
}

vector<int> leftView(Node *root) {
   vector <int> v;
   int maxLevel = 0;
   leftViewUtil(root, maxLevel, 1, v);
   return v;
}
