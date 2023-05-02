// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

// Recursive Solution
class Solution
{
private:
    void topViewUtil(Node *root, int height, int pos, unordered_map <int, pair <int, int>> &um, int &maxPos, int &minPos) {
        if (!root) {
            return;
        }
        
        if (um.find(pos) == um.end()) {
            um[pos] = make_pair(height, root -> data);
        } else if (um[pos].first > height) {
            um[pos] = make_pair(height, root -> data);
        }
        maxPos = max(maxPos, pos);
        minPos = min(minPos, pos);
        topViewUtil(root -> left, height + 1, pos - 1, um, maxPos, minPos);
        topViewUtil(root -> right, height + 1, pos + 1, um, maxPos, minPos);
    }
public:
    vector<int> topView(Node *root) {
        unordered_map <int, pair <int, int>> um;
        vector <int> v;
        int maxPos = -1e6, minPos = 1e6;
        topViewUtil(root, 0, 0, um, maxPos, minPos);
        for (int i = minPos; i <= maxPos; i++) {
            if (um.find(i) != um.end()) {
                v.push_back(um[i].second);
            }
        }
        return v;
    }
};

// Iterative Solution
class Solution
{
    public:
    vector<int> topView(Node *root)
    {
        vector<int> ans; 
        if(root == NULL) return ans; 
        map<int,int> mpp; 
        queue<pair<Node*, int>> q; 
        q.push({root, 0}); 
        while(!q.empty()) {
            auto it = q.front(); 
            q.pop(); 
            Node* node = it.first; 
            int line = it.second; 
            if(mpp.find(line) == mpp.end()) mpp[line] = node->data; 
            
            if(node->left != NULL) {
                q.push({node->left, line-1}); 
            }
            if(node->right != NULL) {
                q.push({node->right, line + 1}); 
            }
            
        }
        
        for(auto it : mpp) {
            ans.push_back(it.second); 
        }
        return ans; 
    }

};
