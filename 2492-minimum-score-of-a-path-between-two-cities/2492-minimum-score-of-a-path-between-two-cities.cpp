class Solution {
public:
    void DFS(int node, vector<int> &vis, int &ans, vector<vector<pair<int, int>>> &edge)
    {
        vis[node] = 1;
        
        for(auto& it: edge[node]) 
        {
            ans = min(ans, it.second);
            if(!vis[it.first]) {
                DFS(it.first, vis, ans, edge);
            }
        }
    }
    
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> edge(n + 1);
        vector<int> vis(n + 1);
        
        for(auto& it: roads) {
            edge[it[0]].push_back({it[1], it[2]});
            edge[it[1]].push_back({it[0], it[2]});
        }
        
        int ans = INT_MAX;
        
        DFS(1, vis, ans, edge);
        
        return ans;
    }
};