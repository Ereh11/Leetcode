/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> ans;
    
    void BFS(TreeNode* root)
    {
        queue<TreeNode*> qu; vector<int> v;
        qu.push(root);
        int cnt = 1;
        while(!qu.empty())
        {
           TreeNode* root = qu.front(); qu.pop();
           v.push_back(root->val);
           if(root->left != nullptr) qu.push(root->left);
           if(root->right != nullptr) qu.push(root->right);
            
           if(--cnt == 0) ans.push_back(v), v.clear(), cnt = qu.size();
        }
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if(root != nullptr) BFS(root);
        return ans;
    }
};