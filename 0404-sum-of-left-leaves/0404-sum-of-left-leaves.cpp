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
    int ans = 0;
    
    void DFS(TreeNode* root, bool b)
    {
        if(root == nullptr) return;
        if(root!= nullptr && (root->left == nullptr && root->right == nullptr) && b == 1 ) ans +=root->val;
        
        DFS(root->left, 1);
        DFS(root->right, 0);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        DFS(root, 0);
        return ans;
    }
};