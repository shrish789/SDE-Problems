/*
https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
*/

class Solution {
public:
    void dfs(TreeNode *root,int x,int y,map<int,multiset<pair<int,int>>> &mp){
        if(root==NULL)  return;
        mp[x].insert({y,root->val});
        dfs(root->left,x-1,y+1,mp);   //sending the vertical and horizantal distance each time
        dfs(root->right,x+1,y+1,mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,multiset<pair<int,int>>> mp;  //map will be sorted based on first index
        vector<vector<int>> ans;
        dfs(root,0,0,mp);
        for(auto group:mp){         //getting set for different vertical distances
            vector<int> v;
            for(auto p:group.second)
               v.push_back(p.second);
            ans.push_back(v);
        }
        return ans;
    }
};
