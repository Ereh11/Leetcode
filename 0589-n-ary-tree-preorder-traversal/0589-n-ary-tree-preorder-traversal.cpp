class Solution {
public:
    vector<int> ans;
    
    void DFS(Node* root)
    {
        ans.push_back(root->val);
        for(auto& it: root->children)
            DFS(it);
    }
    vector<int> preorder(Node* root) {
        if(root != nullptr) DFS(root);
        return ans;
    }
};