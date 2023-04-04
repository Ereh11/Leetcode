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
    
    pair<int, int> Traverse(TreeNode* root, int &ans)
    {
        if(root == NULL)   return {0, 0};
        
        pair<int, int>  lf = Traverse(root->left, ans);
        pair<int, int>  rt = Traverse(root->right, ans);
        
        int sz = lf.second + rt.second + 1;
        int sumAll = lf.first + rt.first + root->val;
        
        if(root->val == sumAll / sz)
            ans++;
        
        return {sumAll, sz};
    }
    
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        Traverse(root, ans);
        
        return ans;
    }
};