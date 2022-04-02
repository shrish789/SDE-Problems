/*
https://leetcode.com/problems/maximum-width-of-binary-tree/
*/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
		// Node and index of the node 
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        long long int ans = 0;
        while(!q.empty())
        {
            long long int size = q.size();
            long long int min_id = q.front().second;
            long long int first, last;
            for(auto i = 0; i < size; i++)
            {
                long long int curr_id = q.front().second - min_id;
                TreeNode *node = q.front().first;
                q.pop();
                if(i == 0) first = curr_id;
                if(i == size-1) last = curr_id;
                if(node->left)
                    q.push({node->left, curr_id*2+1});
                if(node->right)
                    q.push({node->right, curr_id*2+2});
            }
            
            ans = max(ans, last-first+1);
        }
        return ans;
    }
};
