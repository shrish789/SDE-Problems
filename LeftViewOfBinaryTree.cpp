// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1#

void leftViewFinal(Node *root, int level, int &maxLevel, vector<int> &v) {
    if (!root) {
       return;
   }
   
   if (maxLevel < level) {
       v.push_back(root -> data);
       maxLevel = level;
   }
   
   leftViewFinal(root -> left, level + 1, maxLevel, v);
   leftViewFinal(root -> right, level + 1, maxLevel, v);
}

vector<int> leftView(Node *root)
{
   vector<int> v;
   int maxLevel = 0;
   leftViewFinal(root, 1, maxLevel, v);
   return v;
}
