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
    vector<int> ans;
    void DFS(TreeNode* root)
    {
        if(root == nullptr) return;
        
        DFS(root->left), DFS(root->right);
        ans.push_back(root->val);
        
    }
     
    vector<int> postorderTraversal(TreeNode* root) {
        if(root != nullptr) DFS(root);
        return ans;
    }
};