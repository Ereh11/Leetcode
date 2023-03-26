class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int> &vis, unordered_map<int, int> &m, int p, int &ans) 
    {
        vis[node] = 1;
        for(auto& it:  adj[node]) {
            if(m.find(it) != m.end()) ans = max(ans, p - m[it]);
            m[it] = p++;
            if(!vis[it]) dfs(it, adj, vis, m, p, ans);
        }
    }
    
    
    int longestCycle(vector<int>& edges) 
    {
        int n = edges.size(), ans = -1;
        
        vector<int> adj[n];
        
        for(int i=0; i<n; i++) {
            if(edges[i] != -1) adj[i].push_back(edges[i]);
        }
        
        vector<int> vis(n);
        
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                unordered_map<int, int> m;
                m[i] = 0;
                dfs(i, adj, vis, m, 1, ans);
            }
        }
        
        return ans;
    }
};