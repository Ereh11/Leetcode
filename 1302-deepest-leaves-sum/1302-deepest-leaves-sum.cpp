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
    void calc_MaxDepth(TreeNode* root,  int step, int &mxdepth)
    {
        if(root == NULL)  return;
        if(root->left == NULL && root->right == NULL)
            mxdepth = max(mxdepth, step);
        
        calc_MaxDepth(root->left, step + 1, mxdepth);
        calc_MaxDepth(root->right, step + 1, mxdepth);
    }
    
    void Traverse(TreeNode* root,  int &ans, int step, int &mxdepth)  {
        if(root == NULL)  return;
        
        if(root->left == NULL && root->right == NULL && step == mxdepth)
            ans += root->val;
        
        Traverse(root->left, ans, step + 1, mxdepth);
        Traverse(root->right, ans, step + 1, mxdepth);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int ans = 0, mxdepth = 0;
        
        calc_MaxDepth(root,  1, mxdepth);
        Traverse(root, ans, 1, mxdepth);
        
        return ans;
    }
};