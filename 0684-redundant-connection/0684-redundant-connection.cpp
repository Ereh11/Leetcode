class Solution {
public:
    
    
    int Find(int node, vector<int> &parent){
        return parent[node] = (parent[node] == node ? node : Find(parent[node], parent));
    }
    
    void Merge(int node1, int node2, vector<int> &parent)
    {
        int p1 = Find(node1, parent), p2 = Find(node2, parent);
        
        parent[p1] = p2;
        
    }
    
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(edges.size() + 1);
        vector<int> ans;
        
        for(int i = 1; i < parent.size(); i++)
            parent[i] = i;
        
        for(auto& it: edges)
        {
            if(Find(it[0], parent) != Find(it[1], parent)){
                Merge(it[0], it[1], parent);
            }
            else
                ans = it;
        }
        
        return ans;
    }
};