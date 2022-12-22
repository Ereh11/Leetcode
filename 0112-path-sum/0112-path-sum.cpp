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
    bool DFS(TreeNode* root, int targetSum, int su)
    {
       
        if(root == nullptr) 
            return false;
        if(su + root->val == targetSum && root->left == nullptr && root->right == nullptr) 
            return true;
        else 
            return (DFS(root->left, targetSum, su + root->val) || DFS(root->right, targetSum, su + root->val));
    
    }
   
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if(root == nullptr) return false;
        return DFS(root, targetSum, 0);
    }
};