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
    void Traverse(TreeNode* root, string ans, int &res)
    {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) {
            ans += to_string(root->val);
            res += stoi(ans);
            return;
        }
        Traverse(root->left, ans + to_string(root->val), res);
        Traverse(root->right, ans + to_string(root->val), res);
    }
    
    int sumNumbers(TreeNode* root) {
        int res = 0;
        Traverse(root, "", res);
        return res;
    }
};