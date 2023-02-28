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
    vector<TreeNode*> ans;
    unordered_map<string, int> mp;
    
    string solve(TreeNode* root) {
        if(!root) return "";
        
        string left = solve(root->left);
        string right = solve(root->right);
        
        string current = to_string(root->val) + "L" + left + "R" +  right;
         mp[current]++;
        if(mp[current] == 2)
            ans.push_back(root);
        
        return current;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        solve(root);
        return ans;
    }
};