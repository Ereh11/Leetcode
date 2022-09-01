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
    int count = 0;
    void traverse(TreeNode* node,int curMax){
        if (!node) return;
        
        if (node->val >= curMax){
            count++;
            curMax = node->val;
        }
        traverse(node->left, curMax);
        traverse(node->right, curMax);
    }
    int goodNodes(TreeNode* root) {
        traverse(root, root->val);
        return count;
    }
};