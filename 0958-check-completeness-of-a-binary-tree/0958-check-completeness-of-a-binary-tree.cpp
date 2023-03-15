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
    int solve(TreeNode* root) 
    {
        if (root == nullptr)
            return 0;
        return (1 + solve(root->left) + solve(root->right));
    }

    bool DFS(TreeNode* node, int index, int n) {
        if (node == nullptr)
            return true;
       
        if (index >= n) 
            return false;
       
        return (DFS(node->left, 2 * index + 1, n) && DFS(node->right, 2 * index + 2, n));
    }

    bool isCompleteTree(TreeNode* root) {
        return DFS(root, 0, solve(root));
    }
};