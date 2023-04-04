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
    
    void Traverse(TreeNode* root, TreeNode* parent, TreeNode* grandparent, int &ans)
    {
        if(root == NULL)  return;
        
        if(grandparent != NULL && !(grandparent->val & 1))
            ans += root->val;
          
        Traverse(root->right, root, parent, ans);
        Traverse(root->left, root, parent, ans);
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        
        int ans = 0;
        Traverse(root, NULL, NULL, ans);
        
        return ans;
    }
};