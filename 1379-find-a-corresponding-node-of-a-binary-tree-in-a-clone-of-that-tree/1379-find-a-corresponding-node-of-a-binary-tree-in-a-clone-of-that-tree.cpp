/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans, *T;
    void solve(TreeNode* o, TreeNode* c)
    {
        if(o == NULL)  return;
        
        if(o == T) {
            ans = c;
            return;
        }
        
        solve(o->left, c->left);
        solve(o->right, c->right);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        T = target;
        
        solve(original, cloned);
        
        return ans;
    }
};