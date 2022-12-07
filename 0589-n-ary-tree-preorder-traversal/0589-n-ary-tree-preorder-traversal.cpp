class Solution {
public:
    vector<int> ans;
   // map<int, bool> vis;
    
    void DFS(Node* root)
    {
        ans.push_back(root->val);//, vis[root->val] = 1;
        for(auto& it: root->children)
            DFS(it);
    }
    vector<int> preorder(Node* root) {
        if(root != nullptr) DFS(root);
        return ans;
    }
};